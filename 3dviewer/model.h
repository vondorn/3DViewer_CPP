#ifndef MODEL_H
#define MODEL_H

#include <QFile>
#include <QStringList>
#include <QTextStream>
#include <QVector3D>
#include <QVector>

namespace s21 {
class Model {
 public:
  Model(){};
  static Model& getInstance() {
    static Model instance;
    return instance;
  }

  void loadModel(const QString& path);
  QVector<QVector3D>& getVertexes() { return vertexes; }

 private:
  QVector<QVector3D> vertexes;
};
}  // namespace s21
#endif  // MODEL_H
