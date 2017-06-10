#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <mysql.h>
#include <vector>
#include "StrefaSkladowania.h"
#include "Dostawa.h"
#include "Regal.h"
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
	
	//zwraca wektor wszystkich dostaw
	void GetDostawy(std::vector<Dostawa*>* vec);

	//potrzebne do "Dodawanie dostawy do strefy skladowania":
	
	//bierze wskaznik na strefe zwraca wektor z wszystkimi regalami w tej strefie
	void GetRegalyFromStrefaSkladowania(std::vector<Regal*>*, std::string KodStrefa);

	//bierze dostawe i regal, dodaje dostawe do regalu
	//
	//?niby jak mam to zrobic?
	void DodajDostaweDoRegalu(std::string KodDostawy, std::string KodRegalu);

	//potrzebne do "Przesuniecie wewnatrzmagazynwoe": NIE DOKOÑCZONE JESZCZE
	//
	//musisz zwróciæ dane o towar i zasoby, nie wiem jak to rozwiazac
	//*GetZasobyFromStrefa(StrefaSkladowania * strefa)

private:
	MYSQL_RES* GetResult(const char* SQL_QUERY);
	bool Connect();
	void Disconnect();
};
