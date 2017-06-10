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
			Dostawa* d = new Dostawa(NULL, ilosc, NULL, false, kod,row[2]);
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
	strcpy(buff, "SELECT regal.ID FROM mydb.regal WHERE Kod = '");
	strcat(buff, KodRegalu.c_str());
	strcat(buff, "';");
	std::string kodReg;
	result = GetResult(buff);
	if (result != NULL) {
		int num_fields = mysql_num_fields(result);
		MYSQL_ROW row;
		row = mysql_fetch_row(result);
		kodReg = row[0];
		mysql_free_result(result);
	}
	else {
		this->ShowERR("DodajDostaweDoRegalu", "Wyszukiwanie regalu.", buff);
		return;
	}

	for (int i = 0; i < selectDostawyID.size(); i++) {
		status = CreateNewZasob(
			selectTowarID.at(i).c_str(),
			selectDostawyID.at(i).c_str(),
			kodReg.c_str(),
			selectIlosc.at(i).c_str()
			);
		if (status != 0) {
			this->Disconnect();
			return;
		}
	}
	strcpy(buff, "UPDATE mydb.dostawa\
	SET dostawa.Rozmeiszczona = b'1'\
	WHERE dostawa.Kod = '");
	strcat(buff, KodDostawy.c_str());
	strcat(buff, "';");
	status = mysql_query(mysqlConnection,buff);
	if (status != 0) {
		this->ShowERR("DodajDostaweDoRegalu", "Ustawienie dostawy na status 'Rozmeiszczona = 1'.", buff);
		this->Disconnect();
		return;
	}
	this->Disconnect();
}

void DataBaseConnector::GetZasobyFromStrefa(std::vector<Zasob*>* vecZas, std::vector<std::vector<Cecha*>>* vecCech, std::string KodStrefa)
{
	char buff[1000];
	strcpy(buff, "SELECT \
		zasob.ID,\
		regal.Kod,\
		kategoria.Nazwa,\
		towar.Producent,\
		towar.Model,\
		cecha.Nazwa,\
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
	strcat(buff, "') order by towar.ID; ");

	this->Connect();
	MYSQL_RES* result = GetResult(buff);
	if (result != NULL) {
		int num_fields = mysql_num_fields(result);
		MYSQL_ROW row;
		std::string data;
		std::string zasobID="0";
		while ((row = mysql_fetch_row(result)))
		{
			if (zasobID != row[0]) {
				zasobID = row[0];
				Regal* regal = new Regal(row[1], NULL, NULL);
				Kategoria* kateg = new Kategoria(row[2]);
				Towar* towar = new Towar(row[3], row[4], kateg);
				std::string il = row[6];
				Zasob* zasob = new Zasob(towar, NULL, regal, atoi(il.c_str()));
				vecZas->push_back(zasob);
				Cecha* cech = new Cecha(row[5], kateg);
				std::vector<Cecha*> v;
				v.push_back(cech);
				vecCech->push_back(v);
			}
			else {
				int lastItem = vecCech->size() - 1;
				if (lastItem < 0) {
					this->ShowERR("GetZasobyFromStrefa", "Wystapi³ bl¹d przy budowaniu vectora klas 'Cecha'",NULL);
					this->Disconnect();
					return;
				}
				Cecha* cech = new Cecha(row[5], NULL);
				vecCech->at(lastItem).push_back(cech);
			}
		}
		mysql_free_result(result);
	}

	this->Disconnect();
}

void DataBaseConnector::PrzesunZasobNaRegal(int zasobID, std::string KodRegal,int ilosc)
{
	char buff[200];
	strcpy(buff, "SELECT Ilosc FROM mydb.zasob\
		WHERE zasob.ID =");
	strcat(buff, std::to_string(zasobID).c_str());
	strcat(buff, ";");

	std::string data;
	this->Connect();
	MYSQL_RES* result = GetResult(buff);
	if (result != NULL) {
		int num_fields = mysql_num_fields(result);
		MYSQL_ROW row;
		row = mysql_fetch_row(result);
		data = row[0];
		mysql_free_result(result);
	}
	else {
		this->ShowERR("PrzesunZasobNaRegal", "Wyszukiwanie zasobu.", buff);
		this->Disconnect();
		return;
	}
	int zasobSize = atoi(data.c_str());
	int status = 0;
	if (zasobSize > ilosc) {
		zasobSize -= ilosc;
		//update ilosc stary zasob
		strcpy(buff, "UPDATE mydb.zasob\
			SET zasob.Ilosc =");
		strcat(buff, std::to_string(zasobSize).c_str());
		strcat(buff, " WHERE zasob.ID = ");
		strcat(buff, std::to_string(zasobID).c_str());
		strcat(buff, ";");
		
		status = mysql_query(mysqlConnection, buff);
		if (status != 0) {
			this->ShowERR("PrzesunZasobNaRegal", "Ustawienie ilosci dla istniejacego zasobu nie powiodlo sie.", buff);
			this->Disconnect();
			return;
		}
		//stworz nowy zasob z nowym regalem
		strcpy(buff, "SELECT Towar_ID, Dostawa_ID FROM mydb.zasob\
		WHERE zasob.ID =");
		strcat(buff, std::to_string(zasobID).c_str());
		strcat(buff, ";");

		std::string towarID;
		std::string dostawaID;

		result = GetResult(buff);
		if (result != NULL) {
			int num_fields = mysql_num_fields(result);
			MYSQL_ROW row;
			row = mysql_fetch_row(result);
			towarID = row[0];
			dostawaID = row[1];
			mysql_free_result(result);
		}
		else {
			this->ShowERR("PrzesunZasobNaRegal", "Wyszukiwanie zasobu.", buff);
			return;
		}
		status = this->CreateNewZasob(towarID.c_str(), dostawaID.c_str(), KodRegal.c_str(), std::to_string(ilosc).c_str());
		if (status != 0) {
			this->Disconnect();
			return;
		}
	}
	else {
		//update stary zasob regal
		strcpy(buff, "UPDATE mydb.zasob\
			SET zasob.Regal_ID =");
		strcat(buff, KodRegal.c_str());
		strcat(buff, " WHERE zasob.ID = ");
		strcat(buff, std::to_string(zasobID).c_str());
		strcat(buff, ";");

		status = mysql_query(mysqlConnection, buff);
		if (status != 0) {
			this->ShowERR("PrzesunZasobNaRegal", "Ustawienie nowego regalu dla istniejacego zasobu nie powiodlo sie.", buff);
			this->Disconnect();
			return;
		}
	}

	this->Disconnect();
}

int DataBaseConnector::CreateNewZasob(const char * towarID, const char * dostawaID, const char * reagalKod, const char * ilosc)
{
	char buff[500];
	strcpy(buff, "INSERT INTO mydb.zasob(Towar_ID, Dostawa_ID, Regal_ID, Ilosc) VALUES('");
	strcat(buff, towarID);
	strcat(buff, "', '");
	strcat(buff, dostawaID);
	strcat(buff, "', '");
	strcat(buff, reagalKod);
	strcat(buff, "', '");
	strcat(buff, ilosc);
	strcat(buff, "');");
	int st = mysql_query(mysqlConnection, buff);
	if (st != 0) {
		this->ShowERR("PrzesunZasobNaRegal", "Utworzenie nowego zasobu nie powiodlo sie.", buff);
	}
	return st;
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

void DataBaseConnector::ShowERR(const char * Function, const char * Message, const char * QUERY)
{
	std::cout << "ERROR: " << Function << "\nMESSAGE: " << Message << "\nQUERY: " << QUERY << std::endl;
}
