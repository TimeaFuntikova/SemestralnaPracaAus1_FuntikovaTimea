#include "KriteriumUZJNazov.h"

namespace structures {

	std::string KriteriumUZJNazov::evaluate(UZJ* object) //override
	{
		return object->getName();
	}
}