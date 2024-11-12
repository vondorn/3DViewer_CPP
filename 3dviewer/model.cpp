#include "model.h"

namespace s21 {

void Model::loadModel(const QString& path) {
  // unsigned point = -1;
  // bool pushFlag = 0;

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
      QStringList list = line.split(' ', Qt::SkipEmptyParts);
      if (list.size() == 4) {
        for (short int i = 1; i < 4; i++) {
          QStringList vertex = list[i].split('/', Qt::SkipEmptyParts);
          facets.push_back(vertex[0].toUInt() - 1);
          qDebug() << vertex[0].toUInt() - 1;
        }
      }
    }
  }

  // while (!in.atEnd()) {
  //   line = in.readLine().trimmed();

  //   if (line.startsWith("v ")) {
  //     QStringList vertex = line.split(' ', Qt::SkipEmptyParts);
  //     if (vertex.size() == 4) {
  //       float x = vertex[1].toFloat();
  //       float y = vertex[2].toFloat();
  //       float z = vertex[3].toFloat();
  //       vertexes.append(QVector3D(x, y, z));
  //     }
  //   } else if (line.startsWith("f ")) {
  //     QStringList list = line.split(' ', Qt::SkipEmptyParts);
  //     if (list.size() == 4) {
  //       for (short int i = 1; i < 4; i++) {
  //         QStringList str = list[i].split('/', Qt::SkipEmptyParts);
  //         unsigned vertex = str[0].toUInt() - 1;
  //         if (i == 1 && point != vertex) {
  //           facets.push_back(point);
  //           qDebug() << point;
  //           point = vertex;
  //           facets.push_back(vertex);
  //           qDebug() << vertex;
  //           pushFlag = 1;
  //         } else if (i == 2 && pushFlag) {
  //           pushFlag = 0;
  //           facets.push_back(vertex);
  //           qDebug() << vertex;
  //           facets.push_back(vertex);
  //           qDebug() << vertex;
  //         } else if (i == 2 || i == 3) {
  //           facets.push_back(vertex);
  //           qDebug() << vertex;
  //         }
  //       }
  //     }
  //   }
  // }
  // if (!facets.empty()) {
  //   facets.pop_front();
  // }
  // qDebug() << facets.back();
  // facets.push_back(facets.back());
  // facets.push_back(point);
  // qDebug() << point;

  file.close();
}

void Model::moveModelX(float distance) {
  for (int i = 0; i < vertexes.size(); i++) {
    vertexes[i].setX(vertexes[i].x() + distance);
  }
}

void Model::moveModelY(float distance) {
  for (int i = 0; i < vertexes.size(); i++) {
    vertexes[i].setY(vertexes[i].y() + distance);
  }
}

void Model::scaleModel(bool scaling) {
  float m = scaling ? 1.1f : 0.9f;
  for (int i = 0; i < vertexes.size(); i++) {
    vertexes[i].setX(vertexes[i].x() * m);
    vertexes[i].setY(vertexes[i].y() * m);
    vertexes[i].setZ(vertexes[i].z() * m);
  }
}

void Model::rotateModel() {}

void Model::rotateY(float angle) {
  angle *= M_PI / 180.0f;
  for (int i = 0; i < vertexes.size(); i++) {
    float x = vertexes[i].x();
    float z = vertexes[i].z();
    vertexes[i].setX(x * cos(angle) + z * sin(angle));
    vertexes[i].setZ(-x * sin(angle) + z * cos(angle));
  }
}

void Model::rotateX(float angle) {
  angle *= M_PI / 180.0f;
  for (int i = 0; i < vertexes.size(); i++) {
    float y = vertexes[i].y();
    float z = vertexes[i].z();
    vertexes[i].setY(y * cos(angle) - z * sin(angle));
    vertexes[i].setZ(y * sin(angle) + z * cos(angle));
  }
}

void Model::rotateZ(float angle) {
  angle *= M_PI / 180.0f;
  for (int i = 0; i < vertexes.size(); i++) {
    float y = vertexes[i].y();
    float x = vertexes[i].x();
    vertexes[i].setX(x * cos(angle) - y * sin(angle));
    vertexes[i].setY(x * sin(angle) + y * cos(angle));
  }
}

}  // namespace s21
