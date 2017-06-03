#pragma once

class TowarCecha
{
private:
	int TowarID;
	int CechaID;
public:
	TowarCecha(int towarid, int cechaid);
	~TowarCecha();

	int GetTowarID();
	int GetCechaID();

	bool EdytujTowarID (int towarid);
	bool EdytujCechaID (int cechaid);

	static TowarCecha* Dodaj(int towarid, int cechaid);
	static bool Usun(TowarCecha *);
};

