#pragma once
#include <string>
class Regal
{
private:
	std::string Kod;
	int Pojemnosc;
	int StrefaSkladowaniaID;
public:
	Regal(std::string kod,int pojemnosc, int strefaskladowaniaid);
	~Regal();

	std::string GetKod();
	int GetPojemnosc();
	int GetStrefaSkladowaniaID();

	bool EdytujKod(std::string kod); 
	bool EdytujPojemnosc(int pojemnosc);
	bool EdytujStrefaSkladowaniaID(int strefaskladowaniaid);

	static Regal* Dodaj(std::string kod, int pojemnosc, int strefaskladowaniaid);
	static bool Usun(Regal *);
};

