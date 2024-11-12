#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>

#include "widget.h"

namespace s21 {

class MainWindow : public QMainWindow {
 public:
  explicit MainWindow(Widget* widget = nullptr) {
    setLayout(layout());
    setCentralWidget(widget);
  }

 private:
  void resizeEvent(QResizeEvent* event) override {
    resize(event->size().width(), event->size().width());
  }
};
}  // namespace s21

#endif  // MAINWINDOW_H
