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


	//PREROBIC -- LL + memleaky dokopat
	structures::LinkedList<structures::LinkedList<std::string>*>* Reader::nacitajKraje(std::string nazovSuboru)
	{
		std::vector<std::vector<std::string>> obsahCSVFile;
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
				obsahCSVFile.push_back(row);
			}
		}
		else {
			std::cout << "Could not open the file\n";
		}

		structures::LinkedList<std::string>* liness = new structures::LinkedList<std::string>;
		structures::LinkedList<structures::LinkedList<std::string>*>* result = new structures::LinkedList<structures::LinkedList<std::string>*>;

		// nacitam vsetky texty z csv file
		for (int i = 0; i < obsahCSVFile.size(); i++)
		{
			std::string riadok = "";
			for (int j = 0; j < obsahCSVFile[i].size(); j++)
			{
				riadok += obsahCSVFile[i][j];
			}

			if (riadok == ";;;;;") {
				break;
			}


			riadok += ";"; // ABY SOM MOHOL NESKOR ZISTIT CI UZ JE KONIEC

			liness->add(riadok);
		}


		for (std::string item : *liness) {
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

		delete liness;

		return result;
	}
	
	/*
	bool nacitajObce(); //sequenceTable
	bool nacitajOkresy(); //sequenceTable
	bool nacitajVzdelanie();//sequenceTable
	bool nacitajVek();//sequenceTable
	*/