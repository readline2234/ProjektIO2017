#include "DataBaseConnector.h"

DataBaseConnector* DataBaseConnector::_instance=NULL;


DataBaseConnector::DataBaseConnector(const char* serverAdress, const char* user, const char* password, const char* database)
{
	this->serverAdres = serverAdress;
	this->user = user;
	this->password = password;
	this->database = database;
	mysqlConnection = mysql_init(NULL);
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

void DataBaseConnector::GetStrefySkladowania(std::vector<StrefaSkladowania*>* vec)
{
	this->Connect();

	MYSQL_RES* result = GetResult("SELECT * FROM mydb.strefa_skladowania;");
	if (result != NULL) {
		int num_fields = mysql_num_fields(result);
		MYSQL_ROW row;

		while ((row = mysql_fetch_row(result)))
		{
			StrefaSkladowania* s = new StrefaSkladowania(row[1]);
			vec->push_back(s);
		}
		mysql_free_result(result);
	}

	this->Disconnect();
}

void DataBaseConnector::GetDostawy(std::vector<Dostawa*>* vec)
{
	this->Connect();

	MYSQL_RES* result = GetResult("SELECT Kod,sum(Ilosc),Data FROM mydb.dostawa where dostawa.Rozmeiszczona = '0' group by Kod;");
	if (result != NULL) {
		int num_fields = mysql_num_fields(result);
		MYSQL_ROW row;

		while ((row = mysql_fetch_row(result)))
		{
			int ilosc = atoi(row[1]);
			int kod = atoi(row[0]);
			Dostawa* d = new Dostawa(NULL, ilosc, NULL, false, kod);
			vec->push_back(d);
		}
		mysql_free_result(result);
	}

	this->Disconnect();
}

void DataBaseConnector::GetRegalyFromStrefaSkladowania(std::vector<Regal*>*vec, std::string KodStrefa)
{
	char buff[200];
	strcpy(buff, "SELECT regal.Kod, regal.Pojemnosc FROM strefa_skladowania JOIN regal ON(strefa_skladowania.ID = regal.Strefa_skladowania_ID) WHERE strefa_skladowania.Kod = '");
	strcat(buff, KodStrefa.c_str());
	strcat(buff, "';");
	
	this->Connect();
	MYSQL_RES* result = GetResult(buff);
	if (result != NULL) {
		int num_fields = mysql_num_fields(result);
		MYSQL_ROW row;

		while ((row = mysql_fetch_row(result)))
		{
			Regal* r = new Regal(row[0], atoi(row[1]),NULL);
			vec->push_back(r);
		}
		mysql_free_result(result);
	}

	this->Disconnect();
}

void DataBaseConnector::DodajDostaweDoRegalu(std::string KodDostawy, std::string KodRegalu)
{
	char dostawy[200];
	strcpy(dostawy, "SELECT dostawa.ID, dostawa.Towar_ID, dostawa.Ilosc FROM mydb.dostawa where dostawa.Kod = '");
	strcat(dostawy, KodDostawy.c_str());
	strcat(dostawy, "';");

	std::vector<char[3][50]> selectDostawy;

	this->Connect();
	MYSQL_RES* result = GetResult(dostawy);
	if (result != NULL) {
		int num_fields = mysql_num_fields(result);
		MYSQL_ROW row;

		while ((row = mysql_fetch_row(result)))
		{
			char dane[3][50];
			strcpy(dane[0], row[0]);
			strcpy(dane[1], row[1]);
			strcpy(dane[2], row[2]);
			selectDostawy.push_back(dane);
		}
		mysql_free_result(result);
	}
	char buff[500];
	for (int i = 0; i < selectDostawy.size(); i++) {
		strcpy(buff, "INSERT INTO zasob(Towar_ID, Dostawa_ID, Regal_ID, Ilosc) VALUES(");
		strcat(buff, selectDostawy[i][1]);//towar id
		strcat(buff, ", ");
		strcat(buff, selectDostawy[i][0]);//dostawa id
		strcat(buff, ", ");
		strcat(buff, KodRegalu.c_str());
		strcat(buff, ", ");
		strcat(buff, selectDostawy[i][2]);//ilosc
		strcat(buff, ");");
		mysql_query(mysqlConnection, buff);
	}

	this->Disconnect();
}

MYSQL_RES* DataBaseConnector::GetResult(const char * SQL_QUERY)
{
	if (mysql_query(mysqlConnection, SQL_QUERY))
	{
		fprintf(stderr, "ERROR IN: StrefaSkladowania ** DataBaseConnector::GetStrefySkladowania() | SELECT");
	}
	else {
		MYSQL_RES *result = mysql_store_result(mysqlConnection);
		if (result == NULL)	{
			fprintf(stderr, "ERROR IN: StrefaSkladowania ** DataBaseConnector::GetStrefySkladowania() | RESULT");
		}
		else {
			return result;
		}
	}
	return NULL;
}

bool DataBaseConnector::Connect()
{
	if (mysql_real_connect(mysqlConnection, serverAdres, user, password, database, 0, NULL, 0)) {
		return true;
	}
	else {
		printf("B³¹d po³¹czenia z baz¹ MySQL: %d, %s\n", mysql_errno(mysqlConnection), mysql_error(mysqlConnection));
		return false;
	}
}

void DataBaseConnector::Disconnect()
{
	mysql_close(mysqlConnection);
	mysqlConnection = mysql_init(NULL);
}
