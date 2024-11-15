#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "model.h"

namespace s21 {

class Controller {
 public:
  Controller() : model_(Model::getInstance()){};

  void moveMouse(QPoint pos);
  void scaleMouse(bool dir);
  void setSpacePressed(bool press);
  bool getSpacePressed();
  void setMousePressed(QPoint lastPos);
  void unsetMousePressed();
  bool getMousePressed();

  QVector<QVector3D>& getVertexes() { return model_->getVertexes(); }
  QVector<unsigned>& getFacets() { return model_->getFacets(); }

 private:
  Model* model_;
  bool isMousePressed = 0;
  bool isSpacePressed = 0;
  QPoint lastPosition;
};
}  // namespace s21

#endif  // CONTROLLER_H
