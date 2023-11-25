#include "Observadores/Subject.hpp"

namespace Observadores {

Subject::Subject() {}

Subject::~Subject() {
    lObserver.clear();
}

} // namespace Observadores
