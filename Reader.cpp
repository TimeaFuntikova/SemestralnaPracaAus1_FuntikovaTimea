#include "Reader.h"



namespace structures {
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

		Reader::Reader()
		{
			std::string path = "C:\\Users\\timka\\source\\repos\\SemestralnaPracaAus1_FuntikovaTimea\\data\\kraje.csv";
			nacitajKraje(path);
		}

		*/
		//PREROBIC -- LL + memleaky dokopat
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

			structures::LinkedList<std::string>* liness = new structures::LinkedList<std::string>();
			structures::LinkedList<structures::LinkedList<std::string>*>* result = new structures::LinkedList<structures::LinkedList<std::string>*>();

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


				riadok += ";";

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

				structures::LinkedList<std::string>* zoznam = new structures::LinkedList<std::string>;
				zoznam->add(nazovUJ);
				zoznam->add(kodUJ);
				result->add(zoznam);

				for (std::string item : *zoznam) {
					std::cout << item << std::endl;
				}
				delete zoznam;

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

LinkedList<LinkedList<std::string>*>* Reader::nacitajObce(std::string fileName)
	{
		//structures::DoubleLinkedList<LinkedList<std::string>*>* nacitajObce(std::string nazovSuboru) {

		std::vector<std::vector<std::string>> content;
		std::vector<std::string> row;
		std::string line, word;

		std::fstream file(fileName, std::ios::in);
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

		LinkedList<std::string>* contentWords = new LinkedList<std::string>();
		LinkedList<LinkedList<std::string>*>* vysledok = new LinkedList<LinkedList<std::string>*>();

		// nacitanie vsetkych udajov pricom sa do uvahy beru ;
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
			contentWords->add(riadok);
		}


		for (std::string item : *contentWords) {
			std::string kodUJ = "";
			std::string nazovUJ = "";
			int i = 0;

			//chcem len kod a nazov obce, takze preskocim prvu informaciu a ponecham si len dve nasledujuce:
			while (item.at(i) != ';')
			{
				i++;
			}
			i++;

			while (item.at(i) != ';')
			{
				kodUJ += item.at(i);
				i++;
			}
			i++;

			while (item.at(i) != ';')
			{
				nazovUJ += item.at(i);
				i++;
			}

			LinkedList<std::string>* zoznam = new LinkedList<std::string>();
			zoznam->add(nazovUJ);
			zoznam->add(kodUJ);
			vysledok->add(zoznam);

			for (std::string item : *zoznam) {
				std::cout << item << std::endl;
			}
			delete zoznam;

		}
		delete contentWords;
		
		return vysledok;
	}
}
