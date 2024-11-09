#include "model.h"

namespace s21 {

void Model::loadModel(const QString& path) {
  QFile file(path);

  if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) return;

  QTextStream in(&file);
  QString line;

  while (!in.atEnd()) {
    line = in.readLine().trimmed();

    if (line.startsWith("v ")) {
      QStringList vertex = line.split(' ', Qt::SkipEmptyParts);
      if (vertex.size() == 4) {
        float x = vertex[1].toFloat() / 140;
        float y = vertex[2].toFloat() / 140;
        float z = vertex[3].toFloat() / 140;
        vertexes.append(QVector3D(x, y, z));
      }
    } else if (line.startsWith("f ")) {
      QStringList list = line.split(' ', Qt::SkipEmptyParts);
      if (list.size() == 4) {
        facet f;
        for (short int i = 1; i < 4; i++) {
          QStringList vertex = list[i].split('/', Qt::SkipEmptyParts);
          f.faceVertices[i - 1] = vertex[0].toUInt() - 1;
        }
        facets.push_back(f);
      }
    }
  }
  file.close();
}

void Model::moveModel() {
  for (int i = 0; i < vertexes.size(); i++) {
    vertexes[i].setX(vertexes[i].x() + 0.1);
  }
}

void Model::scaleModel() {
  for (int i = 0; i < vertexes.size(); i++) {
    vertexes[i].setX(vertexes[i].x() * 1.1);
    vertexes[i].setY(vertexes[i].y() * 1.1);
    vertexes[i].setZ(vertexes[i].z() * 1.1);
  }
}
}  // namespace s21
