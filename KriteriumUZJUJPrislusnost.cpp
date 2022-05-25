#include "KriteriumUZJUJPrislusnost.h"

structures::KriteriumUZJPatriDoVyssiehoCelku::KriteriumUZJPatriDoVyssiehoCelku(UZJ* vyssiCelok)
{
	vyssiCelok_ = vyssiCelok;
}

bool structures::KriteriumUZJPatriDoVyssiehoCelku::evaluate(UZJ* object)
{
	return object->getVyssiCelok() == vyssiCelok_;
}
