#pragma once
#include "Enums.h"
#include "Array.h"

/// <summary>
/// Slúži na uloženie údajov o veku obyvatelov do jednoduchého pola.
/// Je tu zabezpecena zlozist (O1) čo s týka prístupu na index.
/// </summary>
namespace structures {
	class Vek {
	private:
		Array<int>* vekSKM_;
		Array<int>* vekSKZ_;
		Array<int>* EVSM_;
		Array<int>* EVSZ_;
	public:
		Vek();
		~Vek();
		void pridajVek(pohlavie_enum pohl, int miestoVPoliNaVek, int kolkoSaNapocitalo);
		void pridajVekCelkovo(Vek* vek);
		void pridajDoEVS(Vek* vek);
		void pridajZDoEVS(EVS_enum evs, int kolkosaPridava);
		void pridajMDoEVS(EVS_enum evs, int kolkosaPridava);
		void setVekSM(Array<int>* vek);
		void setVekSZ(Array<int>* vek);
		Array<int>* getvekSM();
		Array<int>* getvekSZ();
		Array<int>* getEVSM();
		Array<int>* getEVSZ();
		int getPocetLudiSDanymVekom(pohlavie_enum pohl, int miestoNaVekVPoli);
		int getPocetZvEVS(EVS_enum evs);
		int getPocetMvEVS(EVS_enum evs);
		int getPocetEkoVekSkupinCelkovo(EVS_enum evs);

	};
}

