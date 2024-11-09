#include "widget.h"

#include "./ui_widget.h"

namespace s21 {

Widget::Widget(Model* model) : model_(model) {}

Widget::~Widget() {}

void Widget::initializeGL() {
  glLoadIdentity();
  glClearColor(0.792969f, 0.613281f, 0.9375f, 1.0f);  // покраска фона rgb
  // glMatrixMode(GL_MODELVIEW);
  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
  glEnable(GL_DEPTH_TEST);  // включение теста глубины
  // glEnable(GL_CULL_FACE);  // не ренднерим то, что находится вне поля зрения
}

void Widget::resizeGL(int w, int h) {
  float aspect = w / (float)h;  // соотношение ширины к высоте для правильного
                                // масштабирования сцены
  // m.setToIdentity();  // делают матрицу m единичной
  // m.perspective(45, aspect, 0.1f,
  //               10.0f);  // создание матрицы перспектив: угол обзораº,
  //               аспект,
  //                        // ближний и дальний предел
}

void Widget::paintGL() {
  glClear(GL_COLOR |
          GL_DEPTH_BUFFER_BIT);  // очищение цветового и глубинного буфера

  QVector<QVector3D> vert = model_->getVertexes();
  QVector<facet> faces = model_->getFacets();
  glLineWidth(2);

  glColor3f(0.0f, 0.0f, 1.0f);  // Синий цвет

  // if (faces.size() != 3) close();

  glEnableClientState(GL_VERTEX_ARRAY);
  glVertexPointer(3, GL_FLOAT, 0, vert.data());
  glDrawElements(GL_LINES, faces.size() * 3, GL_UNSIGNED_INT, faces.data());

  glColor3f(0.0f, 1.0f, 0.0f);  // Зеленый цвет

  glDrawArrays(GL_POINTS, 0, vert.size());
  glPointSize(8);
  glDisableClientState(GL_VERTEX_ARRAY);

  // for (int i = 0; i < faces.size(); i++) {
  //   unsigned first = faces.at(i).faceVertices[0] - 1;
  //   unsigned second = faces.at(i).faceVertices[1] - 1;
  //   unsigned third = faces.at(i).faceVertices[2] - 1;
  //   if (i) {
  //     glVertex3f(vert.at(first).x(), vert.at(first).y(), vert.at(first).z());
  //   }
  //   glVertex3f(vert.at(first).x(), vert.at(first).y(), vert.at(first).z());
  //   glVertex3f(vert.at(second).x(), vert.at(second).y(),
  //   vert.at(second).z()); glVertex3f(vert.at(second).x(),
  //   vert.at(second).y(), vert.at(second).z()); glVertex3f(vert.at(third).x(),
  //   vert.at(third).y(), vert.at(third).z());
  // }

  // glVertex3f(vert.at(0).x(), vert.at(0).y(), vert.at(0).z());
  // glVertex3f(vert.at(1).x(), vert.at(1).y(), vert.at(1).z());
  // glVertex3f(vert.at(2).x(), vert.at(2).y(), vert.at(2).z());

  // glEnd();
}

void Widget::on_pushButton_clicked() { model_->moveModel(); }

void Widget::keyPressEvent(QKeyEvent* event) {
  switch (event->key()) {
    case Qt::Key_Space:
      model_->moveModel();
      break;
    case Qt::Key_S:
      model_->scaleModel();
      break;
    default:
      break;
  }
  update();
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
