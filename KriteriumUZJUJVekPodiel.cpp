#include "KriteriumUZJUJVekPodiel.h"


namespace structures {
	double KriteriumUZJUJVekPodiel::evaluate(UZJ* object)
	{
		int citatel = object->getVek()->getPocetLudiSDanymVekom(pohl_, vek_);
		int menovatel = object->getPocetObyvatelov();
		double vypocet = (100 * (citatel / static_cast<double>(menovatel)));
		return vypocet;
	}
}
