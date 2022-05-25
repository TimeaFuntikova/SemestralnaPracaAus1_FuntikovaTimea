#include "KriteriumUZJUJVzdelaniePodiel.h"

double structures::KriteriumUZJUJVzdelaniePodiel::evaluate(UZJ* object)
{
    int citatel = object->getVzdelaniePocet()->celkovyPocetLudiSoVzdelanimALL();
    int menovatel = object->getPocetObyvatelov();
    double vysledok = 100 * (citatel / static_cast<double>(menovatel));
    return vysledok;
}
