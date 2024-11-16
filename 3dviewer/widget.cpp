#include "widget.h"

#include "./ui_widget.h"

namespace s21 {

Widget::Widget(QWidget* parent)
    : QOpenGLWidget(parent), controller_(new Controller) {}

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
  glViewport(0, 0, w, h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  GLfloat x = (GLfloat)w / h;
  glFrustum(-x, x, -10.0f, 10.0f, -100.0f, 100.0f);
  glMatrixMode(GL_MODELVIEW);
}

void Widget::paintGL() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();

  QVector<QVector3D> vert = controller_->getVertexes();
  QVector<unsigned> faces = controller_->getFacets();

  if (faces.empty()) close();

  // glTranslatef(-0.25f, 0.25f, 0.0f);

  glLineWidth(6);
  glColor3f(0.0f, 0.0f, 1.0f);
  glEnableClientState(GL_VERTEX_ARRAY);
  glVertexPointer(3, GL_FLOAT, 0, vert.data());
  glDrawElements(GL_TRIANGLES, faces.size(), GL_UNSIGNED_INT, faces.data());

  glColor3f(0.0f, 1.0f, 0.0f);
  glPointSize(12);

  glDrawArrays(GL_POINTS, 0, vert.size());

  glDisableClientState(GL_VERTEX_ARRAY);

  glColor3f(0.3164f, 0.3164f, 0.3164f);
  glBegin(GL_LINES);
  glVertex2f(-1.0f, 0.0f);
  glVertex2f(1.0f, 0.0f);
  glVertex2f(0.0f, -1.0f);
  glVertex2f(0.0f, 1.0f);
  glEnd();

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
  if (event->key() == Qt::Key_Space) {
    setCursor(QCursor(Qt::OpenHandCursor));
    isSpacePressed = true;
  }
}

void Widget::keyReleaseEvent(QKeyEvent* event) {
  if (event->key() == Qt::Key_Space) {
    unsetCursor();
    isSpacePressed = false;
  }
}

void Widget::mousePressEvent(QMouseEvent* event) {
  isMousePressed = true;
  lastPosition = event->pos();
}

void Widget::mouseReleaseEvent(QMouseEvent* event) { isMousePressed = false; }

void Widget::mouseMoveEvent(QMouseEvent* event) {
  if (isSpacePressed && isMousePressed) {
    float x = (event->pos().x() - lastPosition.x()) / 500.0f;
    float y = (lastPosition.y() - event->pos().y()) / 500.0f;
    float z = 0.0f;

    // mainwindow_->setMoveX(x);
    // mainwindow_->setMoveY(y);
    // mainwindow_->setMoveZ(z);

    // controller_->move(x, y, z);

    lastPosition = event->pos();
  } else if (isMousePressed) {
    float x = (lastPosition.y() - event->pos().y()) / 4.0f;
    float y = (lastPosition.x() - event->pos().x()) / 4.0f;
    float z = 0.0f;

    // model_->rotate(x, y, z);

    lastPosition = event->pos();
  }
  update();
}

void Widget::wheelEvent(QWheelEvent* event) {
  controller_->scaleMouse(event->angleDelta().y() > 0 ? 1 : 0);
  update();
}

void Widget::moveSpin(float x, float y, float z) {
  controller_->move(x, y, z);
  update();
}

void Widget::rotateSpin(float x, float y, float z) {
  controller_->rotate(x, y, z);
  update();
}

void Widget::scaleSpin(float x, float y, float z) {
  controller_->scale(x, y, z);
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
