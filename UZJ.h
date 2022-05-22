#pragma once

#include "Structure.h"
#include "Types.h"
#include "Utils.h"
#include "Vector.h" 
#include <cstring>
#include <iostream>


//podla impl. prirucky zodpoveda triede student
namespace structures {

	class UZJ
	{
	public:
		UZJ(std::string nazov);
	private:
		std::string nazov_;
		int vek_;


		static const int vzdelanie_; //flag od 1 do 8 podla stupna vzdelania jaksik
		//typUZJ typUZJ_;
		//??? prislusnost_;
		static const int vekovaSkupina;
		static const int pohlavie;
		//bool nadradena_;
	public:
		const std::string& getName() const { return nazov_; };
		const int& getVek() const { return vek_; };


	};
}
