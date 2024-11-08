#include "widget.h"

#include "./ui_widget.h"

namespace s21 {

Widget::Widget(Model* model) : model_(model) {}

Widget::~Widget() {}

void Widget::initializeGL() {
  glClearColor(0.792969f, 0.613281f, 0.9375f, 1.0f);  // покраска фона rgb
  glEnable(GL_DEPTH_TEST);  // включение теста глубины
  glEnable(GL_CULL_FACE);  // не ренднерим то, что находится вне поля зрения
}

void Widget::resizeGL(int w, int h) {
  float aspect = w / (float)h;  // соотношение ширины к высоте для правильного
                                // масштабирования сцены
  m.setToIdentity();  // делают матрицу m единичной
  m.perspective(45, aspect, 0.1f,
                10.0f);  // создание матрицы перспектив: угол обзораº, аспект,
                         // ближний и дальний предел
}

void Widget::paintGL() {
  glClear(GL_COLOR |
          GL_DEPTH_BUFFER_BIT);  // очищение цветового и глубинного буфера

  QVector<QVector3D> vert = model_->getVertexes();

  glLineWidth(2);
  glBegin(GL_LINES);

  glColor3f(0.0f, 0.0f, 1.0f);  // Синий цвет

  if (!vert.size()) close();

  for (int i = 0; i < vert.size() - 1; i++) {
    glVertex3f(vert.at(i).x(), vert.at(i).y(), vert.at(i).z());
    glVertex3f(vert.at(i + 1).x(), vert.at(i + 1).y(), vert.at(i + 1).z());
  }

  glEnd();
}

// void Widget::initShaders() {
//   if (!sp.addShaderFromSourceFile(
//           QOpenGLShader::Vertex,
//           ":/vshader.vsh")) {  // загрузка вершиннвх шейдеров
//     close();
//   }

//   if (!sp.addShaderFromSourceFile(
//           QOpenGLShader::Fragment,
//           ":/fshader.fsh")) {  // загрузка фрагментных шейдеров
//     close();
//   }

//   if (!sp.link()) {  // связывание шейдеров в программу
//     close();
//   }
// }

// void Widget::initCube(float w) {
//   float v = w / 2.0f;
//   QVector<VertexData> vertexes;
//   vertexes.append(
//       VertexData(QVector3D(-v, v, v), QVector2D(0, 1), QVector3D(0, 0, 1)));
//   vertexes.append(
//       VertexData(QVector3D(-v, -v, v), QVector2D(0, 0), QVector3D(0, 0, 1)));
//   vertexes.append(
//       VertexData(QVector3D(v, v, v), QVector2D(1, 1), QVector3D(0, 0, 1)));
//   vertexes.append(
//       VertexData(QVector3D(v, -v, v), QVector2D(1, 0), QVector3D(0, 0, 1)));

//   vertexes.append(
//       VertexData(QVector3D(v, v, v), QVector2D(0, 1), QVector3D(1, 0, 0)));
//   vertexes.append(
//       VertexData(QVector3D(v, -v, v), QVector2D(0, 0), QVector3D(1, 0, 0)));
//   vertexes.append(
//       VertexData(QVector3D(v, v, -v), QVector2D(1, 1), QVector3D(1, 0, 0)));
//   vertexes.append(
//       VertexData(QVector3D(v, -v, -v), QVector2D(1, 0), QVector3D(1, 0, 0)));

//   vertexes.append(
//       VertexData(QVector3D(v, v, v), QVector2D(0, 1), QVector3D(1, 0, 0)));
//   vertexes.append(
//       VertexData(QVector3D(v, -v, v), QVector2D(0, 0), QVector3D(1, 0, 0)));
//   vertexes.append(
//       VertexData(QVector3D(v, v, -v), QVector2D(1, 1), QVector3D(1, 0, 0)));
//   vertexes.append(
//       VertexData(QVector3D(v, -v, -v), QVector2D(1, 0), QVector3D(1, 0, 0)));
// }
}  // namespace s21
