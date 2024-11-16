#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "widget.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT
 public:
  explicit MainWindow(QWidget* parent = nullptr);
  ~MainWindow() = default;

  // void keyPressEvent(QKeyEvent* event) override;
  // void paintEvent(QPaintEvent* event) override;
  void add3DWidget();

  void setMoveX(float value);
  void setMoveY(float value);
  void setMoveZ(float value);

 private slots:
  void on_moveXSpinBox_valueChanged(double arg1);
  void on_moveYSpinBox_valueChanged(double arg1);
  void on_moveZSpinBox_valueChanged(double arg1);

  void on_rotateXSpinBox_valueChanged(double arg1);
  void on_rotateYSpinBox_valueChanged(double arg1);
  void on_rotateZSpinBox_valueChanged(double arg1);

  void on_scalingXSpinBox_valueChanged(double arg1);
  void on_scalingYSpinBox_valueChanged(double arg1);
  void on_scalingZSpinBox_valueChanged(double arg1);

 private:
  Ui::MainWindow* ui;
  s21::Widget* wid;
};

#endif  // MAINWINDOW_H
