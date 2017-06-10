#pragma once
#include <stdio.h>
#include <mysql.h>
#include <vector>
#include "StrefaSkladowania.h"
class DataBaseConnector
{
private: 
	static DataBaseConnector* _instance;

	MYSQL* mysqlConnection;
	const char* serverAdres;
	const char* user;
	const char* password;
	const char* database;

	DataBaseConnector(const char* serverAdress, const char* user, const char* password, const char* database);
	~DataBaseConnector();
public:
	static DataBaseConnector* CreateInstance(const char* serverAdress, const char* user, const char* password, const char* database);
	static DataBaseConnector* GetInstance();
	static void DestroyInstance();

	void GetStrefySkladowania(std::vector<StrefaSkladowania*>* vec);

	//potrzebne do "Dodawanie dostawy do strefy skladowania":

	//void GetDostawy(std::vector<Dostawa*>* vec);
	//zwraca wektor wszystkich dostaw

	//void GetRegalyFromStrefaSkladowania(std::vector<Regal*>*, StrefaSkladowania* strefa); 
	//bierze wskaznik na strefe zwraca wektor z wszystkimi regalami w tej strefie

	//void DodajDostaweDoRegalu(Dostawa * dostawa, Regal * regal); 
	//bierze dostawe i regal, dodaje dostawe do regalu

	//void GetDostawa(Dostawa *, int Kod);
	//zwraca obiekt na podstawie kodu

	//void GetRegalRegal *, ?String? Kod); 
	//zwraca obiekt na podstawie kodu


	//potrzebne do "Przesuniecie wewnatrzmagazynwoe": NIE DOKOÑCZONE JESZCZE
	//
	//musisz zwróciæ dane o towar i zasoby, nie wiem jak to rozwiazac
	//*GetZasobyFromStrefa(StrefaSkladowania * strefa)

private:
	bool Connect();
	void Disconnect();
};
