#include "KriteriumUZJUJVekPocet.h"

int structures::KriteriumUZJPocetObyvatelovSDanymVekomAPohlavim::evaluate(UZJ* object)
{
    return object->getVek()->getPocetLudiSDanymVekom(pohl_, vek_);
}
