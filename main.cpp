#include <iostream>
#include "MenuGlowne.h"
#include <vector>
#include "DataBaseConnector.h"
using namespace Project1;

int main(void)
{
	MenuGlowne ^ menu = gcnew MenuGlowne();
	menu->ShowDialog();

	std::vector<StrefaSkladowania*> vec;
	DataBaseConnector* db = DataBaseConnector::CreateInstance("127.0.0.1", "root", "qwerty123", "mysql");
	db->GetStrefySkladowania(&vec);
	for (int i = 0; i < vec.size(); i++)
	{
		std::cout << "Strefa: " << vec[i]->GetKod() << std::endl;
	}

	system("pause");
	return 0;
}

