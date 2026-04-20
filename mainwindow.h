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
  QVector<QGraphicsTextItem*> tapeItems;
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
