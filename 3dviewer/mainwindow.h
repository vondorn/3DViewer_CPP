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
  MainWindow();
  explicit MainWindow(QWidget* parent = nullptr, s21::Widget* widget = nullptr);
  ~MainWindow() = default;

  // void keyPressEvent(QKeyEvent* event) override;
  // void paintEvent(QPaintEvent* event) override;

 private:
  Ui::MainWindow* ui;
  int a;
};
#endif  // MAINWINDOW_H
