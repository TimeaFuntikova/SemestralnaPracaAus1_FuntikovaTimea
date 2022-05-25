#pragma once
#include "KriteriumUZJ.h"

namespace structures {
	class KriteriumUZJTyp : public KriteriumUZJ<typUZJ_enum>
	{
	public:
		typUZJ_enum evaluate(UZJ* obj);
	};
}

