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
	if (mysql_query(mysqlConnection, "SELECT * FROM mydb.strefa_skladowania;"))
	{
		fprintf(stderr, "ERROR IN: StrefaSkladowania ** DataBaseConnector::GetStrefySkladowania() | SELECT");
	}
	else {
		MYSQL_RES *result = mysql_store_result(mysqlConnection);
		if (result == NULL)
		{
			fprintf(stderr, "ERROR IN: StrefaSkladowania ** DataBaseConnector::GetStrefySkladowania() | RESULT");
		}
		else {
			int num_fields = mysql_num_fields(result);

			MYSQL_ROW row;

			while ((row = mysql_fetch_row(result)))
			{
				/*for (int i = 0; i < num_fields; i++)
				{
					printf("%s ", row[i] ? row[i] : "NULL");
				}
				printf("\n");*/
				StrefaSkladowania* s = new StrefaSkladowania(row[1]);
				vec->push_back(s);
			}
			mysql_free_result(result);
		}
	}
	this->Disconnect();
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
}
