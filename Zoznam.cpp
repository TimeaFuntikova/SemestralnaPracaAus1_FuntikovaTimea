#include <cstring>
#include <iostream>
#include "Zoznam.h"

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
	Zoznam::~Zoznam()
	{
		if (aData)
		{
			for (unsigned i = 0; i < aPocet; i++)
				delete aData[i];
			delete[] aData;
		}
		aData = nullptr;
		aPocet = 0;
	}

	void Zoznam::PridajObec(Obec& obec)
	{
		aPocet++;
		Obec** noveData = DBG_NEW Obec * [aPocet];
		if (aData)
			memmove(noveData, aData, sizeof(Obec*) * (aPocet - 1));
		delete[] aData;
		noveData[aPocet - 1] = &obec;
		aData = noveData;
	}

	void Zoznam::Vypis() const
	{
		for (unsigned i = 0; i < aPocet; i++)
			aData[i]->Vypis();
		std::cout << std::endl;
	}

	void Zoznam::Usporiadaj(bool podlaPoctu)
	{
		_CoreCrtNonSecureSearchSortCompareFunction compareFun =
			podlaPoctu ? PorovnajPocet : PorovnajNazov;
		qsort(aData, aPocet, sizeof(Obec*), compareFun);
	}
}
