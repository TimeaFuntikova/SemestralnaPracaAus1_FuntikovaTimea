#include "KriteriumUZJUJVzdelaniePocet.h"

int structures::KriteriumUZJUJPocetObyvatelovSoVzdelanim::evaluate(UZJ* object)
{
    return object->getVzdelaniePocet()->celkovyPocetLudiSoVzdelanimALL();
}
