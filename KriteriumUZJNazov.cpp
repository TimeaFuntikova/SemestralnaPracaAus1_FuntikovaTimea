#include "KriteriumUZJNazov.h"

namespace structures {

	std::string KriteriumUZJNazov::evaluate(const UZJ& object) //override
	{
		return object.getName();
	}
}