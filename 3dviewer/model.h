#ifndef MODEL_H
#define MODEL_H

#include <QDebug>
#include <QFile>
#include <QStringList>
#include <QTextStream>
#include <QVector3D>
#include <QVector>

namespace s21 {

class Model {
 public:
  Model(){};
  static Model* getInstance() {
    static Model* instance;
    if (!instance) {
      instance = new Model;
    }
    return instance;
  }

  void loadModel(const QString& path);
  QVector<QVector3D>& getVertexes() { return vertexes; }
  QVector<unsigned>& getFacets() { return facets; }

  void moving(float x, float y, float z);
  void rotate(float x, float y, float z);
  void scale(float x, float y, float z);

  void rotateX(float angle);
  void rotateY(float angle);
  void rotateZ(float angle);

  struct ModelData {
    float mx, my, mz, rx, ry, rz, sx = 1.0f, sy = 1.0f, sz = 1.0f;
  };

 private:
  QVector<QVector3D> vertexes;
  QVector<unsigned> facets;
  ModelData modelData;
};
}  // namespace s21
#endif  // MODEL_H
