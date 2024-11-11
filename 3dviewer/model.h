#ifndef MODEL_H
#define MODEL_H

#include <QDebug>
#include <QFile>
#include <QStringList>
#include <QTextStream>
#include <QVector3D>
#include <QVector>

namespace s21 {

// struct facet {
//   // facet(unsigned v[3]) {
//   //   for (short i = 0; i < 3; i++) {
//   //     faceVertices[i] = v[i];
//   //   }
//   // }

//   unsigned int faceVertices[3];
// };

class Model {
 public:
  Model(){};
  static Model& getInstance() {
    static Model instance;
    return instance;
  }

  void loadModel(const QString& path);
  QVector<QVector3D>& getVertexes() { return vertexes; }
  QVector<unsigned>& getFacets() { return facets; }

  void moveModelX(float distance);
  void moveModelY(float distance);
  void scaleModel(bool scaling);
  void rotateModel();
  void rotateY(float angle);
  void rotateX(float angle);
  void rotateZ(float angle);

 private:
  QVector<QVector3D> vertexes;
  QVector<unsigned> facets;
};
}  // namespace s21
#endif  // MODEL_H
