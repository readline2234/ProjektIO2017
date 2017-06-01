#pragma once
#include <string>
class StrefaSkladowania
{
private:
	std::string Kod;
	StrefaSkladowania();
public:
	~StrefaSkladowania();

	bool Edytuj(std::string kod);
	
	static StrefaSkladowania* Dodaj(std::string kod);
	static bool Usun(StrefaSkladowania *);
private:


};

