#include "mainwindow.h"

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  wid = new s21::Widget(ui->centralwidget);
  ui->gridLayout->addWidget(wid, 0, 1, 1, 1);

  // wid->resize(1000, 1000);
  wid->setFocus();
}

void MainWindow::on_moveXSpinBox_valueChanged(double arg1) {
  wid->moveSpin(arg1, ui->moveYSpinBox->value(), ui->moveZSpinBox->value());
  wid->setFocus();
}

void MainWindow::on_moveYSpinBox_valueChanged(double arg1) {
  wid->moveSpin(ui->moveXSpinBox->value(), arg1, ui->moveZSpinBox->value());
  wid->setFocus();
}

void MainWindow::on_moveZSpinBox_valueChanged(double arg1) {
  wid->moveSpin(ui->moveXSpinBox->value(), ui->moveYSpinBox->value(), arg1);
  wid->setFocus();
}

void MainWindow::on_rotateXSpinBox_valueChanged(double arg1) {
  wid->rotateSpin(arg1, ui->rotateYSpinBox->value(),
                  ui->rotateZSpinBox->value());
  wid->setFocus();
}

void MainWindow::on_rotateYSpinBox_valueChanged(double arg1) {
  wid->rotateSpin(ui->rotateXSpinBox->value(), arg1,
                  ui->rotateZSpinBox->value());
  wid->setFocus();
}

void MainWindow::on_rotateZSpinBox_valueChanged(double arg1) {
  wid->rotateSpin(ui->rotateXSpinBox->value(), ui->rotateYSpinBox->value(),
                  arg1);
  wid->setFocus();
}

void MainWindow::on_scalingXSpinBox_valueChanged(double arg1) {
  wid->scaleSpin(arg1, ui->scalingYSpinBox->value(),
                 ui->scalingZSpinBox->value());
  wid->setFocus();
}

void MainWindow::on_scalingYSpinBox_valueChanged(double arg1) {
  wid->scaleSpin(ui->scalingXSpinBox->value(), arg1,
                 ui->scalingZSpinBox->value());
  wid->setFocus();
}

void MainWindow::on_scalingZSpinBox_valueChanged(double arg1) {
  wid->scaleSpin(ui->scalingXSpinBox->value(), ui->rotateYSpinBox->value(),
                 arg1);
  wid->setFocus();
}

void MainWindow::setMoveX(float value) { ui->moveXSpinBox->setValue(value); }

void MainWindow::setMoveY(float value) { ui->moveYSpinBox->setValue(value); }

void MainWindow::setMoveZ(float value) { ui->moveZSpinBox->setValue(value); }
