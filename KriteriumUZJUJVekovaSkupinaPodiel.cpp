#include "KriteriumUZJUJVekovaSkupinaPodiel.h"

double structures::KriteriumUZJUJVekovaSkupinaPodiel::evaluate(UZJ* object)
{
	int citatel = object->getVek()->getPocetEkoVekSkupinCelkovo(evs_);
	int menovatel = object->getPocetObyvatelov();
	double vypocet = (100 * (citatel / static_cast<double>(menovatel))); //hlasi warning ak nie je static_cast...
	return vypocet;
}
