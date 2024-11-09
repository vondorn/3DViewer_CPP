#ifndef WIDGET_H
#define WIDGET_H

#include <QKeyEvent>
#include <QMatrix4x4>
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

  // void initShaders();
  // void initCube();

  void on_pushButton_clicked();

  void keyPressEvent(QKeyEvent* event) override;

 private:
  Model* model_;
  QMatrix4x4 m;
  // QOpenGLShaderProgram sp;
  // QOpenGLTexture* texture;
  // QOpenGLBuffer arrayBuffer;
  // QOpenGLBuffer indexBuffer;
};
}  // namespace s21
#endif  // WIDGET_H
