#include <QApplication>
#include <QLocale>
#include <QTranslator>

#include "model.h"
#include "widget.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  s21::Model model = s21::Model::getInstance();
  model.loadModel(
      "/Users/granceti/Projects/cpp/3DViewer_CPP/3dviewer/objects/cube.obj");
  s21::Widget w(&model);
  w.show();
  return a.exec();
}