#ifndef WIDGET_H
#define WIDGET_H

#include <QMatrix4x4>
#include <QMouseEvent>
#include <QOpenGLBuffer>
#include <QOpenGLShaderProgram>
#include <QOpenGLTexture>
#include <QtOpenGLWidgets/QOpenGLWidget>

#include "controller.h"

namespace s21 {

class Widget : public QOpenGLWidget {
  Q_OBJECT

 public:
  Widget(QWidget* parent = nullptr);

  ~Widget();

  void initializeGL() override;
  void resizeGL(int w, int h) override;
  void paintGL() override;

  void keyPressEvent(QKeyEvent* event) override;
  void keyReleaseEvent(QKeyEvent* event) override;

  void mousePressEvent(QMouseEvent* event) override;
  void mouseReleaseEvent(QMouseEvent* event) override;
  void mouseMoveEvent(QMouseEvent* event) override;

  void wheelEvent(QWheelEvent* event) override;

  void moveSpin(float x, float y, float z);
  void rotateSpin(float x, float y, float z);
  void scaleSpin(float x, float y, float z);

 private:
  Controller* controller_;
  // QMatrix4x4 m_pr;
  // QMatrix4x4 m_view;
  // QOpenGLShaderProgram sp;

  bool isMousePressed = 0;
  bool isSpacePressed = 0;
  QPoint lastPosition;

  // void resizeEvent(QResizeEvent* event) override {
  //   resize(event->size().width(), event->size().width());
  // }
};
}  // namespace s21
#endif  // WIDGET_H
