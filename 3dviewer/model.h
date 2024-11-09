#ifndef MODEL_H
#define MODEL_H

#include <QFile>
#include <QStringList>
#include <QTextStream>
#include <QVector3D>
#include <QVector>

namespace s21 {

struct facet {
  // facet(unsigned v[3]) {
  //   for (short i = 0; i < 3; i++) {
  //     faceVertices[i] = v[i];
  //   }
  // }

  unsigned int faceVertices[3];
};

class Model {
 public:
  Model(){};
  static Model& getInstance() {
    static Model instance;
    return instance;
  }

  void loadModel(const QString& path);
  QVector<QVector3D>& getVertexes() { return vertexes; }
  QVector<facet>& getFacets() { return facets; }

  void moveModel();
  void scaleModel();

 private:
  QVector<QVector3D> vertexes;
  QVector<facet> facets;
};
}  // namespace s21
#endif  // MODEL_H
