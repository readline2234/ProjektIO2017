#include <iostream>
#include "MenuGlowne.h"
#include <vector>
#include "DataBaseConnector.h"
#include "Przesuniecie1.h"

using namespace Project1;

int main(void)
{


	std::vector<StrefaSkladowania*> vec;
	//DataBaseConnector* db = DataBaseConnector::CreateInstance("192.168.0.104", "mike", "qwerty123", "mysql");
	DataBaseConnector* db = DataBaseConnector::CreateInstance("127.0.0.1", "root", "qwerty123", "mysql");
	/*db->GetStrefySkladowania(&vec);
	for (int i = 0; i < vec.size(); i++)
	{
		std::cout << "Strefa: " << vec[i]->GetKod() << std::endl;
	}
	std::vector<Regal*> vec2;
	db->GetRegalyFromStrefaSkladowania(&vec2,"A2");
	for (int i = 0; i < vec2.size(); i++)
	{
		std::cout << "Regal: " << vec2[i]->GetKod() << std::endl;
	}
	std::vector<Zasob*> vecZas;
	std::vector<std::vector<Cecha*>> vecCech;
	db->GetZasobyFromStrefa(&vecZas, &vecCech, "A1");
	*/
	//db->PrzesunZasobNaRegal(2, "S3", 46);

	//MenuGlowne ^ menu = gcnew MenuGlowne();
	//menu->ShowDialog();

	//Dostawa1 ^ test = gcnew Dostawa1();
	//test->ShowDialog();

	//Przesuniecie1 ^ test = gcnew Przesuniecie1();
	//test->ShowDialog();

	system("pause");
	return 0;
}

