#include "KriteriumUZJNadradenaUzemnaJednotka.h"

namespace structures {

    UZJ* KriteriumUZJNadradenaUzemnaJednotka::evaluate(UZJ* object)
    {
        return object->getVyssiCelok();
    }
}
