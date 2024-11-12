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
  // float aspect = w / (float)h;  // соотношение ширины к высоте для
  // правильного
  //                               // масштабирования сцены
  // m_pr.setToIdentity();  // делает матрицу m единичной
  // m_pr.perspective(45, aspect, 0.1f,
  //                  10.0f);  // создание матрицы перспектив: угол обзораº,
  // аспект, ближний и дальний предел

  // glViewport(0, 0, w, h);
  // glMatrixMode(GL_PROJECTION);
  // glLoadIdentity();
  // GLfloat x = (GLfloat)w / h;
  // glFrustum(-x, x, -1.0, 1.0, -1.0, 1.0);
  // glMatrixMode(GL_MODELVIEW);
}

void Widget::paintGL() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  QVector<QVector3D> vert = model_->getVertexes();
  QVector<unsigned> faces = model_->getFacets();

  if (faces.empty()) close();

  glLineWidth(6);
  glColor3f(0.0f, 0.0f, 1.0f);
  glEnableClientState(GL_VERTEX_ARRAY);
  glVertexPointer(3, GL_FLOAT, 0, vert.data());
  glDrawElements(GL_TRIANGLES, faces.size(), GL_UNSIGNED_INT, faces.data());

  glColor3f(0.0f, 1.0f, 0.0f);
  glPointSize(12);

  glDrawArrays(GL_POINTS, 0, vert.size());

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

void Widget::keyPressEvent(QKeyEvent* event) {
  switch (event->key()) {
    case Qt::Key_Space:
      setCursor(QCursor(Qt::ClosedHandCursor));
      isSpacePressed = 1;
      break;
    case Qt::Key_R:
      model_->rotateY(5);
      break;
    case Qt::Key_T:
      model_->rotateX(5);
      break;
    case Qt::Key_Y:
      model_->rotateZ(5);
      break;
    default:
      break;
  }
  update();
}

void Widget::keyReleaseEvent(QKeyEvent* event) {
  switch (event->key()) {
    case Qt::Key_Space:
      unsetCursor();
      isSpacePressed = 0;
      break;
    default:
      break;
  }
}

void Widget::mousePressEvent(QMouseEvent* event) {
  isPressed = true;
  lastPosition = event->pos();
}

void Widget::mouseReleaseEvent(QMouseEvent* event) { isPressed = false; }

void Widget::mouseMoveEvent(QMouseEvent* event) {
  if (isSpacePressed && isPressed) {
    QPoint position = event->pos();
    model_->moveModelY((lastPosition.y() - position.y()) / 500.0f);
    model_->moveModelX((position.x() - lastPosition.x()) / 500.0f);
    update();
    lastPosition = position;
  } else if (isPressed) {
    QPoint position = event->pos();
    model_->rotateY((lastPosition.x() - position.x()) / 4.0f);
    model_->rotateX((lastPosition.y() - position.y()) / 4.0f);
    // model_->rotateZ((position.x() - lastPosition.x()) / 50);

    update();
    lastPosition = position;
  }
}

void Widget::wheelEvent(QWheelEvent* event) {
  bool scaling = event->angleDelta().y() > 0 ? 1 : 0;
  model_->scaleModel(scaling);
  update();
}

// void Widget::initShaders() {
//   if (!sp.addShaderFromSourceFile(
//           QOpenGLShader::Vertex,
//           ":/shaders/vshader.vsh")) {  // загрузка вершиннвх шейдеров
//     close();
//   }

//   // if (!sp.addShaderFromSourceFile(
//   //         QOpenGLShader::Fragment,
//   //         ":/shaders/fshader.fsh")) {  // загрузка фрагментных шейдеров
//   //   close();
//   // }

//   if (!sp.link()) {  // связывание шейдеров в программу
//     close();
//   }
// }

}  // namespace s21
