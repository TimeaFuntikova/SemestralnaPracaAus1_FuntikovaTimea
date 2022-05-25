#include <iostream>
#include <fstream>
#include <vector>

#include "Reader.h"
#include "Kraj.h"
#include "Array.h"
using namespace std;

//"C:\\Users\\timka\\source\\repos\\SemestralnaPracaAus1_FuntikovaTimea\\data\\kraje.csv"

/*
void Reader::nacitajTabulku()
	{
		sqceTable_ = new structures::SortedSequenceTable<int, std::string>();
		for (int i = 0; i < 10; i++) {

			sqceTable_->insert(i, "i");
			std::cout << "Do tabulky sa pridal prvok: " + std::to_string(i) + " .";
		}
		delete sqceTable_;
	}

	structures::SortedSequenceTable<int, std::string>* Reader::getSqceTable()
	{
		return sqceTable_;
	}
	*/

	Reader::Reader() 
	{
		std::string path = "C:\\Users\\timka\\source\\repos\\SemestralnaPracaAus1_FuntikovaTimea\\data\\kraje.csv";
		nacitajKraje(path);
	}

	/*
	bool Reader::nacitajKraje(const char* nazov)
	{
		bool succeded_ = false;

		FILE* vstup_ = nullptr;
		vstup_ = fopen(nazov, "rt");
		if (!vstup_)
		{
			std::cout << "File is opened or corrupt. Close the file and re-run the app." << std::endl;
			throw std::runtime_error("File is opened or corrupt. Close the file and re-run the app.");
		}
		else
		{
			while(!feof(vstup_)) {
				int pocetKrajov;
				fscanf(vstup_, "%d", &pocetKrajov);

				this->zoznamKrajov_ = new structures::Array<Kraj*>(pocetKrajov);
				for (int i = 0; i < pocetKrajov; i++)
				{
					char nazov[2];
					fscanf(vstup_, "%s", &nazov);
					Kraj* kraj = new Kraj(i, nazov);
					(*this->zoznamKrajov_)[i] = kraj;
				}

			}
			fclose(vstup_);
			succeded_ = true;
			if (succeded_) { cout << "vsetko sa uspesne zapisalo. " << endl;}
			return succeded_;
		}

	}
	*/

	structures::LinkedList<structures::LinkedList<std::string>*>* Reader::nacitajKraje(std::string nazovSuboru)
	{
		std::vector<std::vector<std::string>> content;
		std::vector<std::string> row;
		std::string line, word;

		std::fstream file(nazovSuboru, std::ios::in);
		if (file.is_open())
		{
			bool firstTime = true;
			while (getline(file, line))
			{
				if (firstTime) {
					firstTime = false;
					continue;
				}
				row.clear();

				std::stringstream str(line);

				while (getline(str, word, ','))
					row.push_back(word);
				content.push_back(row);
			}
		}
		else {
			std::cout << "Could not open the file\n";
		}

		structures::LinkedList<std::string>* texty = new structures::LinkedList<std::string>;
		structures::LinkedList<structures::LinkedList<std::string>*>* result = new structures::LinkedList<structures::LinkedList<std::string>*>;

		// nacitam vsetky texty z csv file
		for (int i = 0; i < content.size(); i++)
		{
			std::string riadok = "";
			for (int j = 0; j < content[i].size(); j++)
			{
				riadok += content[i][j];
			}

			if (riadok == ";;;;;") {
				break;
			}


			riadok += ";"; // ABY SOM MOHOL NESKOR ZISTIT CI UZ JE KONIEC

			texty->add(riadok);
		}


		for (std::string item : *texty) {
			std::string kodUJ = "";
			std::string nazovUJ = "";
			int i = 0;
			// najprv prejdem po prvu ";" v obciach, vyfiltrujem poradove cislo, netreba mi ho, potom sa dostanem na meno obce
			while (item.at(i) != ';') {
				//stlpec A
				i++;
			}
			i++;
			while (item.at(i) != ';') {
				//stlpec B
				i++;
			}
			i++;

			while (item.at(i) != ';') {
				//stlpec C
				nazovUJ += item.at(i);
				i++;
			}
			i++;

			while (item.at(i) != ';') {
				//stlpec D
				i++;
			}
			i++;

			while (item.at(i) != ';') {
				//stlpec E
				i++;
			}
			i++;

			i = i + 5; //chcem preskocit prvych 5 znakov v stlpcochF
			while (item.at(i) != ';') {
				//stlpec F
				kodUJ += item.at(i);
				i++;
			}
			i++;


			structures::LinkedList<std::string>* list = new structures::LinkedList<std::string>;
			list->add(nazovUJ);
			list->add(kodUJ);

			result->add(list);

		}

		delete texty;

		return result;
	}

	/*
	bool nacitajObce(); //sequenceTable
	bool nacitajOkresy(); //sequenceTable
	bool nacitajVzdelanie();//sequenceTable
	bool nacitajVek();//sequenceTable
	
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
	}
	*/