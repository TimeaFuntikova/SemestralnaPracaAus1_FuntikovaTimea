#pragma once


//https://en.cppreference.com/w/cpp/language/enum
enum class typUZJ_enum {
	STAT, KRAJ, OKRES , OBEC
};

enum class pohlavie_enum : char {
	ZENA = 'Z', MUZ = 'M'
};

enum class EVS_enum {
	PREDPRDUKTIVNI = 0, PRODUKTIVNI = 1, POPRODUKTIVNI = 2
};

enum class vzdelanie_enum : int {
	BEZ_UKONCENEHO_VZDELANIA = 0,
	ZAKLADNE = 1,
	UCNOVSKE = 2,
	STREDNE = 3,
	VYSSIE = 4,
	VYSOKOSKOLSKE = 5,
	BEZ_VZDELANIA = 6,
	NEZISTENE = 7
};