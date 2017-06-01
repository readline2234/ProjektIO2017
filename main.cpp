#include <iostream>
#include <vector>
#include "DataBaseConnector.h"
int main(void) {
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