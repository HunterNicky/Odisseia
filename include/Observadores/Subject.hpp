#pragma once

#include "Observadores/Observer.hpp"
#include <list>

namespace Observadores {

class Subject {
protected:
  std::list<Observadores::Observer *> lObserver;

public:
  Subject();
  ~Subject();
  virtual void addObserver(Observadores::Observer *observer) = 0;
  virtual void removeObserver(Observadores::Observer *observer) = 0;
  virtual void notify() = 0;
};

} // namespace Observadores