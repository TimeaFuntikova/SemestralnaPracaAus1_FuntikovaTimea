#include "Kraj.h"

Kraj::Kraj(int num, std::string nazovKraja)
{
	num_ = num;
	nazovKraja_ = nazovKraja;
}

std::string Kraj::getNazovKraja()
{
	return this->nazovKraja_;
}

int Kraj::getNum()
{
	return this->num_;
}


