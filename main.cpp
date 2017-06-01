#include <iostream>
#include "MenuGlowne.h"
#include <vector>
#include "DataBaseConnector.h"
using namespace Project1;

int main(void)
{
	std::vector<StrefaSkladowania*> vec;
	DataBaseConnector* db = DataBaseConnector::CreateInstance("192.168.0.104", "mike", "qwerty123", "mysql");
	db->GetStrefySkladowania(&vec);
	for (int i = 0; i < vec.size(); i++)
	{
		std::cout << "Strefa: " << vec[i]->GetKod() << std::endl;
	}

	MenuGlowne ^ menu = gcnew MenuGlowne();
	menu->ShowDialog();

	//Dostawa1 ^ test = gcnew Dostawa1();
	//test->ShowDialog();

	system("pause");
	return 0;
}

