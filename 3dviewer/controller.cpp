#include "controller.h"

namespace s21 {

void Controller::setMousePressed(QPoint lastPos) {
  isMousePressed = true;
  lastPosition = lastPos;
}

void Controller::unsetMousePressed() { isMousePressed = false; }

bool Controller::getMousePressed() { return isMousePressed; }

void Controller::moveMouse(QPoint position) {
  if (getSpacePressed() && getMousePressed()) {
    float x = (position.x() - lastPosition.x()) / 500.0f;
    float y = (lastPosition.y() - position.y()) / 500.0f;
    float z = 0.0f;

    model_->moving(x, y, z);

    lastPosition = position;
  } else if (getMousePressed()) {
    float x = (lastPosition.y() - position.y()) / 4.0f;
    float y = (lastPosition.x() - position.x()) / 4.0f;
    float z = 0.0f;

    model_->rotate(x, y, z);

    lastPosition = position;
  }
}

void Controller::scaleMouse(bool dir) {
  float m = dir ? 1.1 : 0.9;
  model_->scale(m, m, m);
}

void Controller::setSpacePressed(bool press) { isSpacePressed = press; }

bool Controller::getSpacePressed() { return isSpacePressed; }

void Controller::move(float x, float y, float z) { model_->moving(x, y, z); }

void Controller::rotate(float x, float y, float z) { model_->rotate(x, y, z); }

void Controller::scale(float x, float y, float z) { model_->scale(x, y, z); }

}  // namespace s21
