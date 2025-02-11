#include "Observadores/Subject.hpp"

namespace Observadores {

Subject::Subject() : lObserver() {}

Subject::~Subject() { lObserver.clear(); }

} // namespace Observadores
