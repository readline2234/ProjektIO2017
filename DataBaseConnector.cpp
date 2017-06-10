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
	strcpy(buff, "SELECT regal.Kod, regal.Pojemnosc FROM mydb.strefa_skladowania JOIN mydb.regal ON(strefa_skladowania.ID = regal.Strefa_skladowania_ID) WHERE strefa_skladowania.Kod = '");
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

	std::vector<std::string> selectDostawyID;
	std::vector<std::string> selectTowarID;
	std::vector<std::string> selectIlosc;

	this->Connect();
	MYSQL_RES* result = GetResult(dostawy);
	if (result != NULL) {
		int num_fields = mysql_num_fields(result);
		MYSQL_ROW row;
		std::string data;
		while ((row = mysql_fetch_row(result)))
		{
			data = row[0];
			selectDostawyID.push_back(data);
			data = row[1];
			selectTowarID.push_back(data);
			data = row[2];
			selectIlosc.push_back(data);
		}
		mysql_free_result(result);
	}
	char buff[500];
	int status = 0;
	for (int i = 0; i < selectDostawyID.size(); i++) {
		strcpy(buff, "INSERT INTO zasob(Towar_ID, Dostawa_ID, Regal_ID, Ilosc) VALUES('");
		strcat(buff, selectTowarID.at(i).c_str());//towar id
		strcat(buff, "', '");
		strcat(buff, selectDostawyID.at(i).c_str());//dostawa id
		strcat(buff, "', '");
		strcat(buff, KodRegalu.c_str());
		strcat(buff, "', '");
		strcat(buff, selectIlosc.at(i).c_str());//ilosc
		strcat(buff, "');");
		status = mysql_query(mysqlConnection, buff);
		if (status != 0) {
			std::cout<<"ERROR: DodajDostaweDoRegalu("<< KodDostawy <<","<< KodRegalu<<")\n Dodawanie do zasobow.";
			return;
		}
	}
	strcpy(buff, "UPDATE mydb.dostawa\
	SET dostawa.Rozmeiszczona = '1'\
	WHERE dostawa.Kod = '");
	strcat(buff, KodDostawy.c_str());
	strcat(buff, "';");
	status = mysql_query(mysqlConnection,buff);
	if (status != 0) {
		std::cout << "ERROR: DodajDostaweDoRegalu(" << KodDostawy << "," << KodRegalu << ")\n Ustawienie dostawy na status 'Rozmeiszczona = 1'.";
		return;
	}
	this->Disconnect();
}

void DataBaseConnector::GetZasobyFromStrefa(std::vector<Zasob*> vecZas, std::vector<std::vector<Cecha*>> vecCech, std::string KodStrefa)
{
	char buff[200];
	strcpy(buff, "SELECT \
	regal.Kod as Regal,\
		kategoria.Nazwa as Kategoria,\
		towar.Producent,\
		towar.Model,\
		towar.ID as ID_towaru,\
		cecha.Nazwa as Cecha,\
		zasob.Ilosc\
		FROM\
		mydb.zasob\
		join mydb.towar on(zasob.Towar_ID = towar.ID)\
		join mydb.kategoria on(towar.Kategoria_ID = kategoria.ID)\
		join mydb.regal on(regal.ID = zasob.Regal_ID)\
		join mydb.towar_cecha on(towar_cecha.Towar_ID = towar.ID)\
		join mydb.cecha on(cecha.ID = towar_cecha.Cecha_ID)\
		join mydb.strefa_skladowania on(regal.Strefa_skladowania_ID = strefa_skladowania.ID)\
	where strefa_skladowania.Kod in('");
	strcat(buff, KodStrefa.c_str());
	strcat(buff, "'); ");

	this->Connect();
	MYSQL_RES* result = GetResult(buff);
	if (result != NULL) {
		int num_fields = mysql_num_fields(result);
		MYSQL_ROW row;
		std::string data;
		std::string towarID=NULL;
		while ((row = mysql_fetch_row(result)))
		{
			towarID = row[0];
			
		}
		mysql_free_result(result);
	}


	this->Disconnect();
}

MYSQL_RES* DataBaseConnector::GetResult(const char * SQL_QUERY)
{
	if (mysql_query(mysqlConnection, SQL_QUERY))
	{
		fprintf(stderr, "ERROR: %s\n",SQL_QUERY);
	}
	else {
		MYSQL_RES *result = mysql_store_result(mysqlConnection);
		if (result == NULL)	{
			fprintf(stderr, "ERROR: RESULT\n");
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
