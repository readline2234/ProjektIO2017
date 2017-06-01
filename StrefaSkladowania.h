#pragma once
#include <string>
class StrefaSkladowania
{
private:
	std::string Kod;
public:
	StrefaSkladowania(std::string kod);
	~StrefaSkladowania();

	std::string GetKod();

	bool Edytuj(std::string kod);
	
	static StrefaSkladowania* Dodaj(std::string kod);
	static bool Usun(StrefaSkladowania *);
private:


};

