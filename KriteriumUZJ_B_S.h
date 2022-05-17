#pragma once
#include "UZJ_B_S.h"
#include "Kriterium.h"

//potomok kriteria, kde je objecttype UZJ_B_S:

namespace structures {
	template <typename ResultType>
	class KriteriumUZJ_B_S : public Kriterium<UZJ_B_S, ResultType>
	{
	};
}

