/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *vboxLayout;
    QHBoxLayout *hboxLayout;
    QLabel *label;
    QLineEdit *mainAlphabetLine;
    QLabel *label1;
    QLineEdit *extraAlphabetLine;
    QPushButton *setAlphabetButton;
    QLineEdit *inputLine;
    QPushButton *setTapeButton;
    QTableWidget *rulesTable;
    QHBoxLayout *hboxLayout1;
    QPushButton *stepButton;
    QPushButton *runButton;
    QPushButton *stopButton;
    QPushButton *addStateButton;
    QHBoxLayout *hboxLayout2;
    QLabel *label2;
    QSlider *speedSlider;
    QGraphicsView *graphicsView;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        vboxLayout = new QVBoxLayout(centralwidget);
        vboxLayout->setObjectName("vboxLayout");
        hboxLayout = new QHBoxLayout();
        hboxLayout->setObjectName("hboxLayout");
        label = new QLabel(centralwidget);
        label->setObjectName("label");

        hboxLayout->addWidget(label);

        mainAlphabetLine = new QLineEdit(centralwidget);
        mainAlphabetLine->setObjectName("mainAlphabetLine");

        hboxLayout->addWidget(mainAlphabetLine);

        label1 = new QLabel(centralwidget);
        label1->setObjectName("label1");

        hboxLayout->addWidget(label1);

        extraAlphabetLine = new QLineEdit(centralwidget);
        extraAlphabetLine->setObjectName("extraAlphabetLine");

        hboxLayout->addWidget(extraAlphabetLine);

        setAlphabetButton = new QPushButton(centralwidget);
        setAlphabetButton->setObjectName("setAlphabetButton");

        hboxLayout->addWidget(setAlphabetButton);


        vboxLayout->addLayout(hboxLayout);

        inputLine = new QLineEdit(centralwidget);
        inputLine->setObjectName("inputLine");

        vboxLayout->addWidget(inputLine);

        setTapeButton = new QPushButton(centralwidget);
        setTapeButton->setObjectName("setTapeButton");

        vboxLayout->addWidget(setTapeButton);

        rulesTable = new QTableWidget(centralwidget);
        rulesTable->setObjectName("rulesTable");

        vboxLayout->addWidget(rulesTable);

        hboxLayout1 = new QHBoxLayout();
        hboxLayout1->setObjectName("hboxLayout1");
        stepButton = new QPushButton(centralwidget);
        stepButton->setObjectName("stepButton");

        hboxLayout1->addWidget(stepButton);

        runButton = new QPushButton(centralwidget);
        runButton->setObjectName("runButton");

        hboxLayout1->addWidget(runButton);

        stopButton = new QPushButton(centralwidget);
        stopButton->setObjectName("stopButton");

        hboxLayout1->addWidget(stopButton);

        addStateButton = new QPushButton(centralwidget);
        addStateButton->setObjectName("addStateButton");

        hboxLayout1->addWidget(addStateButton);


        vboxLayout->addLayout(hboxLayout1);

        hboxLayout2 = new QHBoxLayout();
        hboxLayout2->setObjectName("hboxLayout2");
        label2 = new QLabel(centralwidget);
        label2->setObjectName("label2");

        hboxLayout2->addWidget(label2);

        speedSlider = new QSlider(centralwidget);
        speedSlider->setObjectName("speedSlider");
        speedSlider->setOrientation(Qt::Horizontal);
        speedSlider->setMinimum(100);
        speedSlider->setMaximum(900);
        speedSlider->setValue(400);

        hboxLayout2->addWidget(speedSlider);


        vboxLayout->addLayout(hboxLayout2);

        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setMinimumHeight(120);

        vboxLayout->addWidget(graphicsView);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Turing Machine", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\236\321\201\320\275\320\276\320\262\320\275\320\276\320\271:", nullptr));
        mainAlphabetLine->setPlaceholderText(QCoreApplication::translate("MainWindow", "a b c", nullptr));
        label1->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\277:", nullptr));
        extraAlphabetLine->setPlaceholderText(QCoreApplication::translate("MainWindow", "x y z", nullptr));
        setAlphabetButton->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\264\320\260\321\202\321\214 \320\260\320\273\321\204\320\260\320\262\320\270\321\202", nullptr));
        inputLine->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\275\320\260\321\207\320\260\320\273\321\214\320\275\321\203\321\216 \321\201\321\202\321\200\320\276\320\272\321\203", nullptr));
        setTapeButton->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\264\320\260\321\202\321\214 \321\201\321\202\321\200\320\276\320\272\321\203", nullptr));
        stepButton->setText(QCoreApplication::translate("MainWindow", "\320\250\320\260\320\263", nullptr));
        runButton->setText(QCoreApplication::translate("MainWindow", "\320\241\321\202\320\260\321\200\321\202", nullptr));
        stopButton->setText(QCoreApplication::translate("MainWindow", "\320\241\321\202\320\276\320\277", nullptr));
        addStateButton->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\201\320\276\321\201\321\202\320\276\321\217\320\275\320\270\320\265", nullptr));
        label2->setText(QCoreApplication::translate("MainWindow", "\320\241\320\272\320\276\321\200\320\276\321\201\321\202\321\214:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
