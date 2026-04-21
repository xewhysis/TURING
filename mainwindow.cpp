#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QPropertyAnimation>
#include <QSet>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {

    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    // Теперь создаём TapeCell вместо QGraphicsTextItem
    for (int i = 0; i < 31; i++) {
        TapeCell *cell = new TapeCell('^');  // ← Изменено
        cell->setPos(i * 40, 0);
        scene->addItem(cell);
        tapeItems.append(cell);
    }

    head = new HeadItem();
    scene->addItem(head);
    head->setPos(visibleCenter * 40, 40);

    timer.setInterval(400);
    connect(&timer, &QTimer::timeout, this, &MainWindow::runStep);
}

MainWindow::~MainWindow() {
    delete ui;
}

//АЛФАВИТ
void MainWindow::on_setAlphabetButton_clicked() {
    mainAlphabet = ui->mainAlphabetLine->text().split(" ", Qt::SkipEmptyParts);
    extraAlphabet = ui->extraAlphabetLine->text().split(" ",
                                                        Qt::SkipEmptyParts);

    for (QString line: mainAlphabet) {
        if (line.size() > 1) {
            QMessageBox::warning(
                this,"Ошибка","Видимо вы не знаете что такое символ");
            return;
        }
    }

    for (QString line: extraAlphabet) {
        if (line.size() > 1) {
            QMessageBox::warning(
                this,"Ошибка","Видимо вы не знаете что такое символ");
            return;
        }
    }

    QSet<QString> mA = QSet<QString>(mainAlphabet.begin(),
                                     mainAlphabet.end());
    QSet<QString> eA = QSet<QString>(extraAlphabet.begin(),
                                     extraAlphabet.end());

    if (mA.contains("^") || eA.contains("^")) {
        QMessageBox::warning(
            this,"Ошибка","Уберите пожалуйста символ пустоты из алфавита");
        return;
    }

    if (mA.intersects(eA)) {
        QMessageBox::warning(
            this,"Ошибка","Похоже у вас есть одинаковые символы");
        return;
    }

    if (mainAlphabet.isEmpty()) {
        QMessageBox::warning(this,"Ошибка","Введите основной алфавит");
        return;
    }

    mainAlphabet = mA.values();
    extraAlphabet = eA.values();

    std::sort(mainAlphabet.begin(), mainAlphabet.end());
    std::sort(extraAlphabet.begin(), extraAlphabet.end());

    fullAlphabet = mainAlphabet;
    fullAlphabet.append("^");
    fullAlphabet.append(extraAlphabet);

    buildTable();
}

//ТАБЛИЦА
void MainWindow::buildTable() {
    ui->rulesTable->setColumnCount(fullAlphabet.size());
    ui->rulesTable->setHorizontalHeaderLabels(fullAlphabet);

    ui->rulesTable->setRowCount(3);
    ui->rulesTable->setVerticalHeaderLabels({"q0","q1","q2"});
}

// ДОБАВИТЬ СОСТОЯybt
void MainWindow::on_addStateButton_clicked() {
    int row = ui->rulesTable->rowCount();
    ui->rulesTable->insertRow(row);
    ui->rulesTable->setVerticalHeaderItem(row,
    new QTableWidgetItem("q" + QString::number(row)));
}

//СТРОКА
void MainWindow::on_setTapeButton_clicked() {
    QString s = ui->inputLine->text();

    for (QChar c: s) {
        if (!mainAlphabet.contains(QString(c))) {
            QMessageBox::warning(
                this,"Ошибка","Символ не из основного алфавита");
            return;
        }
    }

    machine.reset();
    machine.setTape(s);

    loadRules();
    updateView();
}

// ПРАВИЛА
void MainWindow::loadRules() {
    for (int i = 0; i < ui->rulesTable->rowCount(); ++i) {
        QString state = ui->rulesTable->verticalHeaderItem(i)->text();

        for (int j = 0 ; j < ui->rulesTable->columnCount(); ++j) {
            auto item = ui->rulesTable->item(i,j);
            if (!item) continue;

            QStringList p = item->text().split(',');
            if (p[0] == "!") {
                p[0] = "";
                p.append("");
                p.append("!");
            }
            for (QString &s : p) {
                s = s.trimmed();
            }
            //for (QString s: p) {
            //    qDebug() << s;
            //}
            if (p.size()!=3) continue;
            // qDebug() << "228";

            QChar symbol = fullAlphabet[j][0];
            p[0] = p[0] == "" ? symbol : p[0];
            p[1] = p[1] == "" ? "S" : p[1];
            p[2] = p[2] == "" ? state : p[2];
            qDebug() << p[0] << " " << p[1] << " " << p[2];
            Rule r{p[0][0], p[1]=="R"?1:(p[1]=="L"?-1:0), p[2]};
            machine.setRule(state, fullAlphabet[j][0], r);
        }
    }
}

// ОБНОВЛЕНИЕ
void MainWindow::updateView() {
    int realHead = machine.getHead();

    int visualHead = realHead - offset;
    qDebug() << visualHead;

    if (visualHead >= 29) {
        offset += (visualHead - 15);
        visualHead = 15;
    }

    if (visualHead < 0) {
        offset += (visualHead - 15);
        visualHead = 15;
    }

    // ОБНОВЛЯЕМ ЛЕНТУ - используем setSymbol
    for (int i = 0; i < tapeItems.size(); i++) {
        int pos = offset + i;
        QChar c = machine.getSymbol(pos);
        tapeItems[i]->setSymbol(c);  // ← Изменено! Больше не setPlainText
    }

    QPropertyAnimation *a = new QPropertyAnimation(head, "pos");
    a->setDuration(timer.interval() / 2);
    a->setEndValue(QPointF(visualHead * 40, 40));
    a->start(QAbstractAnimation::DeleteWhenStopped);

    highlightCell();
}

// ПОДСВЕТКА
void MainWindow::highlightCell() {
    QString state = machine.getState();
    QChar symbol = machine.getSymbol(machine.getHead());

    for (int i = 0; i < ui->rulesTable->rowCount(); ++i) {
        for (int j = 0; j < ui->rulesTable->columnCount(); ++j) {
            auto item = ui->rulesTable->item(i,j);
            if (item) item->setBackground(Qt::white);
        }
    }

    for (int i = 0; i < ui->rulesTable->rowCount(); ++i){
        if (ui->rulesTable->verticalHeaderItem(i)->text()==state) {
            for (int j = 0; j < fullAlphabet.size(); ++j){
                if (fullAlphabet[j][0]==symbol){
                    auto item = ui->rulesTable->item(i,j);
                    if (item) item->setBackground(Qt::yellow);
                }
            }
        }
    }
}

// ШАГ
void MainWindow::on_stepButton_clicked() {
    if (!machine.step()) {
        QMessageBox::information(this,"Стоп","Нет правила");
    }
    updateView();
}

void MainWindow::runStep() {
    if (!machine.step()) {
        timer.stop();
    }
    updateView();
}

void MainWindow::on_runButton_clicked() {
    loadRules();
    timer.start();
}

void MainWindow::on_stopButton_clicked() {
    timer.stop();
}

// СКОРОСТЬ
void MainWindow::on_speedSlider_valueChanged(int value) {
    timer.setInterval(1000 - value);
}
