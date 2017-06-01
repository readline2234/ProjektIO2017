#pragma once
#include <mysql.h>
class DataBaseConnector
{
private: 
	static DataBaseConnector* _instance;

	DataBaseConnector();
	~DataBaseConnector();
public:
	static DataBaseConnector* CreateInstance();
	static DataBaseConnector* GetInstance();
	static void DestroyInstance();

private:

};

/*
#include <mysql.h>
MYSQL mysql;

mysql_init(&mysql); // incjalizacja

if (mysql_real_connect(&mysql, "127.0.0.1", "root", "qwerty123", "mysql", 0, NULL, 0))
printf("Po³¹czenie z baz¹ danych MySQL nawi¹zano poprawnie!\n");
else
printf("B³¹d po³¹czenia z baz¹ MySQL: %d, %s\n", mysql_errno(&mysql), mysql_error(&mysql));

mysql_close(&mysql); // zamknij po³¹czenie
*/