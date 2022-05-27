// SemestralnaPracaAus1_FuntikovaTimea.cpp : This file contains the 'main' function. Program execution begins and ends there.

//#include "Structure.h"
//#include "Kriterium.h"
//#include "Filter.h"
//#include "FilterUJNazov.h"
#include "Reader.h"

int main()
{
		structures::Reader* reader = new structures::Reader();
		delete reader;
		std::cout << "______" << std::endl;
	    std::cout << "Koniec." << std::endl;
		return 0;
	}

