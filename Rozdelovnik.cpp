#include <fstream>
#include "Rozdelovnik.h"


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
	void Rozdelovnik::Start()
	{
		if (Nacitaj())
		{
			aZoznam.Usporiadaj();
			RozdelObce();
		}
	}

	bool Rozdelovnik::Nacitaj()
	{
		std::ifstream vstup;
		vstup.open(aVstupnySubor);
		if (!vstup) return false;

		std::string nazov;
		unsigned pocet;
		while (vstup >> nazov)
		{
			vstup >> pocet;
			aZoznam.PridajObec(*AlokujObec(pocet, nazov.c_str()));
		}
		vstup.close();
		return true;
	}

	char* Rozdelovnik::VytvorVystup(const char* menosuboru)
	{
		char* path_buffer = DBG_NEW char[_MAX_PATH];
		char drive[_MAX_DRIVE];
		char dir[_MAX_DIR];
		char fname[_MAX_FNAME];
		char ext[_MAX_EXT];

		_splitpath(aVstupnySubor.c_str(), drive, dir, fname, ext);
		_makepath(path_buffer, drive, dir, menosuboru, ext);
		return path_buffer;
	}

	void Rozdelovnik::Uloz(const char* vystsubor, Zoznam& zoznam)
	{
		char* subor = VytvorVystup(vystsubor);
		std::ofstream ofs;
		ofs.open(subor);
		if (!ofs) return;
		for (unsigned i = 0; i < zoznam.Pocet(); i++)
		{
			Obec* obec = zoznam.DajObec(i);
			Uloz(ofs, *obec);
		}
		ofs.close();
		delete[] subor;
	}

	void Rozdelovnik::Uloz(std::ofstream& vystup, const Obec& obec)
	{
		vystup << obec.ToString() << std::endl;
	}

	Obec* Rozdelovnik::AlokujObec(const unsigned pocet, const char* nazov)
	{

		throw std::runtime_error("Not implemented yet.");

	}

	void Rozdelovnik::RozdelObce()
	{
		throw std::runtime_error("Not implemented yet.");

		/*
		Zoznam dediny;
		Zoznam mesta;
		for (unsigned i = 0; i < aZoznam.Pocet(); i++)
		{
			Obec* obec = aZoznam.DajObec(i);
			obec->VelkostObce() ?
				mesta.PridajObec(*(Obec*)obec->Clone()) :
				dediny.PridajObec(*(Obec*)obec->Clone());
		}
		Uloz("dediny", dediny);
		Uloz("mesta", mesta);
		*/
	}
}