#include <iostream>
#include "MenuGlowne.h"

using namespace Project1;

int main()
{
	MenuGlowne ^ menu = gcnew MenuGlowne();
	menu->ShowDialog();

	return 0;
}

