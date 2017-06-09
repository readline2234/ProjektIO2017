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

	//potrzebne do "Dodawanie dostawy do strefy skladowania"
	//std::vector<Regal * > * GetRegalyFromStrefaSkladowania(StrefaSkladowania * strefa); //bierze wskaznik na strefe zwraca wektor z wszystkimi regalami w tej strefie
	//void DodajDostaweDoRegalu(Dostawa * dostawa, Regal * regal); //bierze dostawe i regal, nic nie zwraca (ew. bool'a)

	//potrzebne do "Przesuniecie wewnatrzmagazynwoe"
	//musisz zwróciæ dane o towar i zasoby, nie wiem jak to rozwiazac
	//*GetZasobyFromStrefa(StrefaSkladowania * strefa)

private:
	bool Connect();
	void Disconnect();
};
