#pragma once

#include "Structure.h"
#include "Types.h"
#include "Utils.h"
#include "Vector.h" 
#include <cstring>
#include <iostream>


//podla impl. prirucky zodpoveda triede student
namespace structures {

	class UZJ_B_S
	{
	public:
		UZJ_B_S(std::string nazov);
	protected:
		std::string nazov_;
		Vector* vek_;
		static const int vzdelanie_; //flag od 1 do 8 podla stupna vzdelania jaksik
		//typUZJ typUZJ_;
		//??? prislusnost_;
		static const int vekovaSkupina;
		static const int pohlavie;
		//bool nadradena_;
	};
}

