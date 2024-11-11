#ifndef WIDGET_H
#define WIDGET_H

#include <QKeyEvent>
#include <QMatrix4x4>
#include <QMouseEvent>
#include <QOpenGLBuffer>
#include <QOpenGLShaderProgram>
#include <QOpenGLTexture>
#include <QtOpenGLWidgets/QOpenGLWidget>

#include "model.h"

namespace s21 {

struct VertexData {
  VertexData() {}

  QVector3D vertexes;
};

class Widget : public QOpenGLWidget {
  Q_OBJECT

 public:
  explicit Widget(Model* model = nullptr);
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

 private:
  Model* model_;
  QMatrix4x4 m_pr;
  QMatrix4x4 m_view;
  QOpenGLShaderProgram sp;

  bool isPressed = 0;  // Флаг, отслеживающий состояние нажатия
  bool isSpacePressed = 0;
  QPoint lastPosition;  // Последняя известная позиция нажатия
};
}  // namespace s21
#endif  // WIDGET_H
