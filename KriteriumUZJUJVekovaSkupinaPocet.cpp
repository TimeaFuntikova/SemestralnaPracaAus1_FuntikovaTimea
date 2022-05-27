#include "KriteriumUZJUJVekovaSkupinaPocet.h"
#include <algorithm>
#include <numeric>

int structures::KriteriumUZJUJVekovaSkupinaPocet::evaluate(UZJ* object) //override
{
    return object->getVek()->getPocetEkoVekSkupinCelkovo(evs_);
  
}
