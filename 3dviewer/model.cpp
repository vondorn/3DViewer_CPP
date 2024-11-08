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
        float x = vertex[1].toFloat();
        float y = vertex[2].toFloat();
        float z = vertex[3].toFloat();
        vertexes.append(QVector3D(x, y, z));
      }
    } else if (line.startsWith("f ")) {
    }
  }
  file.close();
}
}  // namespace s21
