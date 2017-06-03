#pragma once

class Zasob
{
private:
	int TowarID;
	int DostawaID;
	int RegalID;
	int Ilosc;
public:
	Zasob(int towarid, int dostawaid, int regalid, int ilosc);
	~Zasob();

	int GetTowarID();
	int GetDostawaID();
	int GetRegalID();
	int GetIlosc();

	bool EdytujTowarID (int towarid);
	bool EdytujDostawaID (int dostawaid);
	bool EdytujRegalID (int regalid);
	bool EdytujIlosc (int ilosc);

	static Zasob* Dodaj(int towarid, int dostawaid, int regalid, int ilosc);
	static bool Usun(Zasob *);
};

