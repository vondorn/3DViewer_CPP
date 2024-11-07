#ifndef WIDGET_H
#define WIDGET_H

#include <QMatrix4x4>
#include <QOpenGLBuffer>
#include <QOpenGLShaderProgram>
#include <QOpenGLTexture>
#include <QtOpenGLWidgets/QOpenGLWidget>

struct VertexData {
  VertexData() {}
  VertexData(QVector3D p, QVector2D c, QVector3D n)
      : position(p), coord(c), normal(n) {}
  QVector3D position;
  QVector2D coord;
  QVector3D normal;
};

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QOpenGLWidget {
  Q_OBJECT

 public:
  Widget(QWidget* parent = nullptr);
  ~Widget();

  void initializeGL() override;
  void resizeGL(int w, int h) override;
  void paintGL() override;

  void initShaders();
  void initCube();

 private:
  QMatrix4x4 m;
  QOpenGLShaderProgram sp;
  QOpenGLTexture* texture;
  QOpenGLBuffer arrayBuffer;
  QOpenGLBuffer indexBuffer;
};
#endif  // WIDGET_H
