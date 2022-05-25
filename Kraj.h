#pragma once
#include <cstdio>
#include <string>


class Kraj
	{
	private:
		int num_ = 0;
		std::string nazovKraja_;
	public:
		Kraj(int num, std::string nazovKraja);
		//Kraj(Kraj& source);
		//Kraj& operator=(Kraj& zdroj) = delete;

		std::string getNazovKraja();
		int getNum();
		virtual ~Kraj() = default;

  };


