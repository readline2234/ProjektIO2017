#include "StrefaSkladowania.h"



StrefaSkladowania::StrefaSkladowania(std::string kod)
{
	this->Kod = kod;
}


StrefaSkladowania::~StrefaSkladowania()
{
}

std::string StrefaSkladowania::GetKod()
{
	return this->Kod;
}

bool StrefaSkladowania::Edytuj(std::string kod)
{
	this->Kod = kod;
	//HERE: wyswil zapytanie do DB
	return true;
}

StrefaSkladowania* StrefaSkladowania::Dodaj(std::string kod)
{
	//StrefaSkladowania* s = new StrefaSkladowania();
	//HERE: query do DB
	return nullptr;
}

bool StrefaSkladowania::Usun(StrefaSkladowania *)
{
	return false;
}
