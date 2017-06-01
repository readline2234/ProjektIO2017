#pragma once
#include <stdio.h>
#include <mysql.h>

class DataBaseConnector
{
private: 
	static DataBaseConnector* _instance;

	MYSQL mysql;
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

private:
	bool Connect();
	void Disconnect();
};
