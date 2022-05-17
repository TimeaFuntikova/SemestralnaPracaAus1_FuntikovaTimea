#pragma once
#include "Obec.h"

namespace nacitavanieZoSuboru {
	class Zoznam
	{
	private:
		unsigned aPocet = 0;
		Obec** aData = nullptr;
	public:
		Zoznam() = default;
		Zoznam(const Zoznam& zdroj) = delete;
		Zoznam& operator=(const Zoznam& zdroj) = delete;
		~Zoznam();
		unsigned Pocet() const { return aPocet; }
		void PridajObec(Obec& obec);
		Obec* DajObec(unsigned i) const { return i < aPocet ? aData[i] : nullptr; }
		void Vypis() const;
		void Usporiadaj(bool podlaPoctu = true);
	};
}

