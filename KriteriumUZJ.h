#pragma once
#include "UZJ.h"
#include "Kriterium.h"

//potomok kriteria, kde je objecttype UZJ:

namespace structures {
	template <typename ResultType>
	class KriteriumUZJ : public Kriterium<UZJ, ResultType>
	{
	};
}

