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
  void add3DWidget(s21::Widget* wid);

 private:
  Ui::MainWindow* ui;
};
#endif  // MAINWINDOW_H
