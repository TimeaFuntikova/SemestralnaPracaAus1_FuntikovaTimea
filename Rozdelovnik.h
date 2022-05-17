#pragma once
#include <string>
#include "Zoznam.h"

namespace nacitavanieZoSuboru {

	class Rozdelovnik 
	{
	private:
		std::string aVstupnySubor = nullptr;
		Zoznam aZoznam;
	public:
		Rozdelovnik(const char* subor) :aVstupnySubor(subor) {}
		virtual ~Rozdelovnik() = default;
		void Start();
	private:
		bool Nacitaj();
		char* VytvorVystup(const char* menosuboru);
	protected:
		void Uloz(const char* subor, Zoznam& zoznam);
		void Uloz(std::ofstream& vystup, const Obec& obec);
		virtual Obec* AlokujObec(const unsigned pocet, const char* nazov);
		// Inherited via IRozdelovnik
		void RozdelObce() ;
		//Obec* DajObec(unsigned i) const {return }

	};
}
