#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsObject>
#include <QGraphicsTextItem>
#include <QTimer>
#include <QVector>
#include <QPainter>

#include "turingmachine.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class HeadItem : public QGraphicsObject {
  Q_OBJECT
 public:
  QRectF boundingRect() const override { return QRectF(0,0,40,20); }

  void paint(QPainter *p, const QStyleOptionGraphicsItem*, QWidget*) override {
        QPolygonF tri;
        tri << QPointF(0,20) << QPointF(40,20) << QPointF(20,0);
        p->setBrush(Qt::red);
        p->drawPolygon(tri);
  }

};



class TapeCell : public QGraphicsObject {
    Q_OBJECT
public:
    TapeCell(QChar symbol) : m_symbol(symbol) {
        setFlag(ItemIsSelectable, false);
    }

    QRectF boundingRect() const override {
        return QRectF(0, 0, 40, 40);
    }

    void paint(QPainter *painter, const QStyleOptionGraphicsItem*, QWidget*) override {
        painter->setPen(QPen(Qt::black, 1));
        painter->setBrush(Qt::white);
        painter->drawRect(boundingRect());

        painter->setPen(Qt::black);
        painter->setFont(QFont("Arial", 16));
        painter->drawText(boundingRect(), Qt::AlignCenter, QString(m_symbol));
    }

    void setSymbol(QChar symbol) {
        m_symbol = symbol;
        update();  // Перерисовываем ячейку
    }

private:
    QChar m_symbol;
};

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 private slots:
  void on_setAlphabetButton_clicked();
  void on_setTapeButton_clicked();
  void on_stepButton_clicked();
  void on_runButton_clicked();
  void on_stopButton_clicked();
  void on_addStateButton_clicked();
  void on_speedSlider_valueChanged(int);

  void runStep();

 private:
  Ui::MainWindow *ui;

  TuringMachine machine;

  QStringList mainAlphabet;
  QStringList extraAlphabet;
  QStringList fullAlphabet;

  QGraphicsScene *scene;
  QVector<TapeCell*> tapeItems;
  HeadItem *head;

  QTimer timer;

  int visibleCenter = 30;
  int offset = 0;

  void buildTable();
  void loadRules();
  void updateView();
  void highlightCell();
};

#endif
