#include <QApplication>
#include <QLocale>
#include <QTranslator>

#include "mainwindow.h"
#include "model.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  s21::Model* model = s21::Model::getInstance();
  model->loadModel(
      "/Users/granceti/Projects/cpp/3DViewer_CPP/3dviewer/objects/cube.obj");
  MainWindow m;
  m.show();
  return a.exec();
}
