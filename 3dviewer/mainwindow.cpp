#include "mainwindow.h"

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  ui->wii = new s21::Widget(ui->centralwidget);
  ui->wii->resize(1000, 1000);
  ui->wii->setFocus();
}
