#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "model.h"

namespace s21 {

class Controller {
 public:
  explicit Controller(Model* model = nullptr);

 private:
  Model* model_;
};
}  // namespace s21

#endif  // CONTROLLER_H
