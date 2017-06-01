#include "DataBaseConnector.h"

DataBaseConnector* DataBaseConnector::_instance=NULL;


DataBaseConnector::DataBaseConnector(const char* serverAdress, const char* user, const char* password, const char* database)
{
	this->serverAdres = serverAdress;
	this->user = user;
	this->password = password;
	this->database = database;
	mysql_init(&mysql);
}

DataBaseConnector::~DataBaseConnector()
{
}

DataBaseConnector * DataBaseConnector::CreateInstance(const char* serverAdress, const char* user, const char* password, const char* database)
{
	if (_instance == NULL) {
		_instance = new DataBaseConnector(serverAdress, user, password, database);
	}
	return _instance;
}

DataBaseConnector * DataBaseConnector::GetInstance()
{
	return _instance;
}

void DataBaseConnector::DestroyInstance()
{
	delete _instance;
	_instance = NULL;
}

bool DataBaseConnector::Connect()
{
	if (mysql_real_connect(&mysql, serverAdres, user, password, database, 0, NULL, 0)) {
		return true;
	}
	else {
		printf("B³¹d po³¹czenia z baz¹ MySQL: %d, %s\n", mysql_errno(&mysql), mysql_error(&mysql));
		return false;
	}
}

void DataBaseConnector::Disconnect()
{
	mysql_close(&mysql);
}
