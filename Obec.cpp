#include <cstring>
#include <iostream>
#include <sstream>
#include "Obec.h"


#ifdef _DEBUG
#include <crtdbg.h>
//predefinovanie klucoveho slova new pre DEBUG rezim
#define DBG_NEW new (_NORMAL_BLOCK, __FILE__, __LINE__)

/// <summary>
/// pre vytvorenie konstantneho objektu pre indikaciu nedealokovanej pamati
/// </summary>
class MemLeak
{
public:
	~MemLeak() { _CrtDumpMemoryLeaks(); }
};

const MemLeak dummyLeak;
#else
#define DBG_NEW new
#endif // _DEBUG

namespace nacitavanieZoSuboru {

	Obec::Obec(unsigned pocetObyvatelov, const char* nazov)
		:aPocetObyvatelov(pocetObyvatelov)
	{
		if (nazov && *nazov)
		{
			aNazov = DBG_NEW char[strlen(nazov) + 1];
			strcpy(aNazov, nazov);
		}
	}

	Obec::Obec(const Obec& zdroj)
		:aPocetObyvatelov(zdroj.aPocetObyvatelov)
	{
		aNazov = DBG_NEW char[strlen(zdroj.aNazov) + 1];
		strcpy(aNazov, zdroj.aNazov);
	}

	Obec::~Obec()
	{
		delete[] aNazov;
	}

	void Obec::Vypis() const
	{
		std::cout << aNazov << '\t' << aPocetObyvatelov << std::endl;
	}

	std::string Obec::ToString()const
	{
		std::stringstream out;
		out << Nazov() << " " << PocetObyvatelov();
		return out.str();
	}

	int PorovnajPocet(const void* p1, const void* p2)
	{
		Obec** obecPtr1 = (Obec**)p1;
		Obec** obecPtr2 = (Obec**)p2;
		Obec* obec1 = *obecPtr1;
		Obec* obec2 = *obecPtr2;
		return obec1->aPocetObyvatelov - obec2->aPocetObyvatelov;
	}

	int PorovnajNazov(const void* p1, const void* p2)
	{
		Obec** obecPtr1 = (Obec**)p1;
		Obec** obecPtr2 = (Obec**)p2;
		return strcmpi((*obecPtr1)->aNazov, (*obecPtr2)->aNazov);
	}
}