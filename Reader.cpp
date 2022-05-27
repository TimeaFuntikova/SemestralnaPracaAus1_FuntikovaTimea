#include "Reader.h"

namespace structures {

	void Reader::nacitajData()
	{
		zoznamKrajov_ = nacitajKraje("C:\\Users\\timka\\source\\repos\\SemestralnaPracaAus1_FuntikovaTimea\\data\\kraje.csv");
		zoznamObci_ = nacitajObce("C:\\Users\\timka\\source\\repos\\SemestralnaPracaAus1_FuntikovaTimea\\data\\obce.csv");
		zoznamOkresov_ = nacitajOkresy("C:\\Users\\timka\\source\\repos\\SemestralnaPracaAus1_FuntikovaTimea\\data\\okresy.csv");
		tabulkaVek_ = nacitajVek("C:\\Users\\timka\\source\\repos\\SemestralnaPracaAus1_FuntikovaTimea\\data\\vek.csv");
		tabulkaVzdelanie_ = nacitajVzdelanie("C:\\Users\\timka\\source\\repos\\SemestralnaPracaAus1_FuntikovaTimea\\data\\vzdelanie.csv");
		/* nacitat vsetko do sequence table*/


		//TODO: uvolnit pamat na spravnom mieste v programe
		//spravovavat v programe a po ukonceni zavolat totok:
		uvolniPamat(); //zatial len pre kraje -->aj gettre ak budem uvolnovat pamat v inej triede
	}

	/// <summary>
	/// zavolat inde nez v reader.cpp
	/// </summary>
	void Reader::uvolniPamat()
	{
		delete zoznamKrajov_;
		delete zoznamObci_;
		delete zoznamOkresov_;
		delete tabulkaVek_;
		delete tabulkaVzdelanie_;

		std::cout << "__________________________" << std::endl;
		std::cout << "Pamat sa uvolnila uspesne." << std::endl;
	}

	/*toto zavolat az po ncitani dat --> resp main - zavola sa reader -> hned sa nacitaju data -> getery
	by mali fungovat spravne --> dat prec funkciu uvoli pamat ale potom v spracovavani programu*/
	LinkedList<LinkedList<std::string>*>* Reader::getZoznamKrajov() { return zoznamKrajov_; }
	SortedSequenceTable<std::string, Vek*>* Reader::getTabulkaVek() { return tabulkaVek_; }
	SortedSequenceTable<std::string, Vzdelanie*>* Reader::getTabulkaVzdelanie() { return tabulkaVzdelanie_; }
	LinkedList<LinkedList<std::string>*>* Reader::getZoznamKObci() { return zoznamObci_; }
	LinkedList<LinkedList<std::string>*>* Reader::getZoznamKOkresov() { return zoznamOkresov_; }

	void Reader::pripravNaCitanie(std::string fileName)
	{
		content_;
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
				content_.push_back(row);
			}
		}
		else
		{
			std::cout << "File is opened or corrupted. Close the file an re-run the app.";
		}
	}
	LinkedList<LinkedList<std::string>*>* Reader::nacitajKraje(std::string fileName)
	{
		pripravNaCitanie(fileName);
		texty_ = new LinkedList<std::string>();
		LinkedList<LinkedList<std::string>*>* zoznamKraje = new LinkedList<LinkedList<std::string>*>();
			for (int i = 0; i < content_.size(); i++)
			{
				for (int j = 0; j < content_[i].size(); j++)
				{
					riadok_+= content_[i][j];
				}
				if (riadok_ == ";;;;;") {
					break;
				}
				riadok_ += ";" ;
				texty_->add(riadok_);
			}
			for (std::string item : *texty_) 
			{
				int i = 0;
				//preskocim az na F stpec kde su prve potrebne data:
				//[0]A, [1]B, [2]C, [3]D, 4[E] [5]F
				for (int i = 0; i < 5; i++)
				{
					while (item.at(i) != ';')
					{
						i++;
					}
					i++;
				}
				i = i + 5; //nechcem prvych 5 znakov 
				while (item.at(i) != ';') 
				{
					kod_ += item.at(i);
					i++;
				}
				i++;
				LinkedList<std::string>* zoznam = new LinkedList<std::string>();
				zoznam->add(nazov_);
				zoznam->add(kod_);
				zoznamKraje->add(zoznam);

				LinkedList<std::string>* itemsToDel = new LinkedList<std::string>();
				for (std::string item : *zoznam) {
					//std::cout << item << std::endl;
					itemsToDel->add(item);
				}
				delete itemsToDel;
				delete zoznam;
			}
			delete texty_;
			std::cout << "Kraje sa nacitali uspesne." << std::endl;
			nazov_ = "";
			kod_ = "";
			riadok_ = "";
			content_.clear();
			return zoznamKraje;
		}
	LinkedList<LinkedList<std::string>*>* Reader::nacitajObce(std::string fileName)
	{
		pripravNaCitanie(fileName);
		texty_ = new LinkedList<std::string>();
		LinkedList<LinkedList<std::string>*>* zoznamObci = new LinkedList<LinkedList<std::string>*>();
		for (int i = 0; i < content_.size(); i++)
		{
			for (int j = 0; j < content_[i].size(); j++)
			{
				riadok_ += content_[i][j];
			}
			if (riadok_ == ";;;;;") {
				break;
			}
			texty_->add(riadok_);
		}
		for (std::string item : *texty_) 
		{
			int i = 0;
			//chcem len kod a nazov obce - skip 1. stplca a nacitam len 2 a 3:
			while (item.at(i) != ';')
			{
				i++;
			}
			i++;
			while (item.at(i) != ';')
			{
				kod_ += item.at(i);
				i++;
			}
			i++;

			while (item.at(i) != ';')
			{
				nazov_ += item.at(i);
				i++;
			}

			LinkedList<std::string>* zoznam = new LinkedList<std::string>();
			zoznam->add(nazov_);
			zoznam->add(kod_);
			zoznamObci->add(zoznam);

			LinkedList<std::string>* itemsToDel = new LinkedList<std::string>();
			for (std::string item : *zoznam) {
				//std::cout << item << std::endl;
				itemsToDel->add(item);
			}
			delete itemsToDel;
			delete zoznam;
		}
		delete texty_;
		std::cout << "Obce sa nacitali uspesne." << std::endl;
		nazov_ = "";
		kod_ = "";
		riadok_ = "";
		content_.clear();
		return zoznamObci;
	}
	LinkedList<LinkedList<std::string>*>* Reader::nacitajOkresy(std::string fileName) 
	{
		pripravNaCitanie(fileName);
		texty_ = new LinkedList<std::string>();

		LinkedList<LinkedList<std::string>*>* zoznamOkresy = new LinkedList<LinkedList<std::string>*>();
		for (int i = 0; i < content_.size(); i++)
		{
			for (int j = 0; j < content_[i].size(); j++)
			{
				riadok_ += content_[i][j];
			}
			if (riadok_ == ";;;;;")
			{
				break;
			}
			texty_->add(riadok_);
		}
		for (std::string item : *texty_) 
		{
			int i = 0;
			while (item.at(i) != ';') 
			{
				i++;
			}
			i++;
			while (item.at(i) != ';') 
			{
				kod_ += item.at(i);
				i++;
			}
			i++;
			while (item.at(i) != ';') 
			{
				nazov_ += item.at(i);
				i++;
			}
			LinkedList<std::string>* zoznam = new LinkedList<std::string>();
			zoznam->add(nazov_);
			zoznam->add(kod_);
			zoznamOkresy->add(zoznam);
			LinkedList<std::string>* itemsToDel = new LinkedList<std::string>();
			for (std::string item : *zoznam) 
			{
				//std::cout << item << std::endl;
				itemsToDel->add(item);
			}
			delete itemsToDel;
			delete zoznam;
		}
		delete texty_;
		riadok_ = "";
		std::cout << "Okresy sa nacitali uspesne." << std::endl;
		nazov_ = "";
		kod_ = "";
		content_.clear();
		return zoznamOkresy;  //vratí sa mi smerník na pole smerníkov na stringy ulozene v LL -->priradiť pri nacitavani
	}
		
	//____________________
	// SEFOVANIE VEKU....
	//___________________

	/*tu treba stringy ukladat ako pointre -- teda aj texty (obsahy csv musia byt pointre...*/


	//PO JEDNOM ROVNO VKLADAT -->REFACT.
	SortedSequenceTable<std::string, Vek*>* Reader::nacitajVek(std::string fileName)
	{
		pripravNaCitanie(fileName);

		textySTRPointer_ = new LinkedList<std::string*>();
		SortedSequenceTable<std::string, Vek*>* tabulkaVek = new SortedSequenceTable<std::string, Vek*>();
		for (int i = 0; i < content_.size(); i++)
		{
			riadokPointer_ = new std::string();

			for (int j = 0; j < content_[i].size(); j++)
			{
				*riadokPointer_ += content_[i][j];
			}
			*riadokPointer_ += ";";
			textySTRPointer_->add(riadokPointer_);
		}

		int pocitadlo = 0;

		for (std::string* item : *textySTRPointer_)
		{
			pocitadlo++;
			if (pocitadlo == 2928)
			{
				break;
			}

			kod_ = "";

			Array<int>* vekMuzi = new Array<int>(101);
			Array<int>* vekZeny = new Array<int>(101);

			//kod:
			int i = 0;
			std::string item2 = *item;

			while (item2.at(i) != ';') {
				kod_ += item2.at(i);
				i++;
			}
			i++;

			//preskocim nazov
			while (item2.at(i) != ';') {
				i++;
			}
			i++;

			//muzi:
			for (int j = 0; j < 101; j++)
			{
				std::string vekPocetStr = "";
				while (item2.at(i) != ';')
				{
					vekPocetStr += item2.at(i);
					i++;
				}
				vekMuzi->at(j) = stoi(vekPocetStr); //funkcia na konverziu string-->int
				i++;
			}

			//zeny:
			for (int j = 0; j < 101; j++)
			{
				std::string vekPocetStr = "";
				while (item2.at(i) != ';')
				{
					vekPocetStr += item2.at(i);
					i++;
				}
				vekZeny->at(j) = stoi(vekPocetStr);
				i++;
			}

			//std::cout << "i got here and the reading is just fine " << std::endl;
			Vek* vekVysledok = new Vek(); //constructor?

			for (int i = 0; i < 101; i++)
			{
				vekVysledok->pridajVek(pohlavie_enum::MUZ, i, vekMuzi->at(i));
				//std::cout << "trying to add the cout of:  "
					//+ std::to_string(i) + " to the count of men in an specific array." << std::endl;

				vekVysledok->pridajVek(pohlavie_enum::ZENA, i, vekZeny->at(i));
				//std::cout << "trying to add the cout of:  "
					//+ std::to_string(i) + " to the count of women in an specific array." << std::endl;
			}

			tabulkaVek->insert(kod_, vekVysledok);
			//std::cout << "Do table sa vlozilo :  "
				//+ std::to_string(i) + " ." << std::endl;

			delete vekMuzi;
			delete vekZeny;
		}
			for (int i = 0; i < textySTRPointer_->size(); i++)
			{
				delete textySTRPointer_->at(i);
			}

		delete textySTRPointer_;
		kod_ = "";
		//delete riadokPointer_;
		// = nullptr;
		textySTRPointer_ = nullptr;
		content_.clear();

		std::cout << "Vek sa nacital uspesne." << std::endl;
		return tabulkaVek;
	}

		//________________________
		// SEFOVANIE Vzdelania..
		//________________________
		SortedSequenceTable<std::string, Vzdelanie*>* Reader::nacitajVzdelanie(std::string fileName)
		{
			pripravNaCitanie(fileName);
			LinkedList<std::string>* texty = new LinkedList<std::string>;
			SortedSequenceTable<std::string, Vzdelanie*>* tabulkaVzdelanie = new SortedSequenceTable<std::string, Vzdelanie*>();

			// nacitam vsetky texty z csv file
			for (int i = 0; i < content_.size(); i++)
			{
				std::string riadok = "";
				for (int j = 0; j < content_[i].size(); j++)
				{
					riadok += content_[i][j];
				}

				riadok += ";"; // pre zistovanie ukoncenia neskor
				texty->add(riadok);
			}

			for (std::string item : *texty) {
				std::string kodUJ = "";
				Array<int>* vzdelanie = new Array<int>(8);

				int i = 0;
				while (item.at(i) != ';') {
					kodUJ += item.at(i);
					i++;
				}
				i++;

				while (item.at(i) != ';') {
					i++;
				}
				i++;

				for (int j = 0; j < 8; j++)
				{
					std::string vzdelaniePocetStr = "";
					while (item.at(i) != ';') {
						vzdelaniePocetStr += item.at(i);
						i++;
					}
					vzdelanie->at(j) = stoi(vzdelaniePocetStr);
					i++;
				}
				Vzdelanie* vzdelanieObjekt = new Vzdelanie();
				//std::cout << "VYtvoril som smerník na vzdelaniaObjekt vek s poctom najdenych ludi: " + std::to_string(i) << std::endl;

				vzdelanieObjekt->priradDoVzdelania(vzdelanie_enum::BEZ_UKONCENEHO_VZDELANIA, vzdelanie->at(0));
				vzdelanieObjekt->priradDoVzdelania(vzdelanie_enum::ZAKLADNE, vzdelanie->at(1));
				vzdelanieObjekt->priradDoVzdelania(vzdelanie_enum::UCNOVSKE, vzdelanie->at(2));
				vzdelanieObjekt->priradDoVzdelania(vzdelanie_enum::STREDNE, vzdelanie->at(3));
				vzdelanieObjekt->priradDoVzdelania(vzdelanie_enum::VYSSIE, vzdelanie->at(4));
				vzdelanieObjekt->priradDoVzdelania(vzdelanie_enum::VYSOKOSKOLSKE, vzdelanie->at(5));
				vzdelanieObjekt->priradDoVzdelania(vzdelanie_enum::BEZ_VZDELANIA, vzdelanie->at(6));
				vzdelanieObjekt->priradDoVzdelania(vzdelanie_enum::NEZISTENE, vzdelanie->at(7));
				tabulkaVzdelanie->insert(kodUJ, vzdelanieObjekt);

				//std::cout << "Uspesne som vlozi do sst tabulky: vzdelanie s poctom : " + std::to_string(i) << std::endl;

				//std::cout << tabulkaVzdelanie->find(kodUJ) << std::endl;
				//std::cout << "V tabulke su data s klucom: " + kodUJ + " a poctom vzdelanych ludi: " + std::to_string(i) << std::endl;

				delete vzdelanie;
			}
			delete texty;
			std::cout << "Vzdelanie sa nacitalo uspesne." << std::endl;

			return tabulkaVzdelanie;
		}
}
