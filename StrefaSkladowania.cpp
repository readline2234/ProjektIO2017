#include "StrefaSkladowania.h"



StrefaSkladowania::StrefaSkladowania()
{
}


StrefaSkladowania::~StrefaSkladowania()
{
}

bool StrefaSkladowania::Edytuj(std::string kod)
{
	this->Kod = kod;
	//HERE: wyswil zapytanie do DB
	return true;
}

StrefaSkladowania* StrefaSkladowania::Dodaj(std::string kod)
{
	StrefaSkladowania* s = new StrefaSkladowania();
	//HERE: query do DB
	return s;
}

bool StrefaSkladowania::Usun(StrefaSkladowania *)
{
	return false;
}
