#pragma once
#include "KriteriumUZJ.h"

enum typUZJ {
	OBEC = 1,
	OKRES = 2,
	KRAJ = 3,
	STAT = 4,
};

namespace structures {
	class KriteriumUZJTyp : public KriteriumUZJ<typUZJ>
	{
	public:
		typUZJ evaluate(const UZJ& obj);
	};
}

