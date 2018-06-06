#pragma once

#include <iostream>

using namespace std;

class Aeroflot
{
private:

		char depar_date[100];
		int  number;
		char dstnshn[100];
		char FIO[100];

public:
	
	Aeroflot() {};
	
	Aeroflot(char*, char*, int, char*);

	~Aeroflot();

	void Add(char*, char*, int, char*);

	char* DeparDate() { return depar_date; }

	char* Fio() { return FIO; }

	char* Dstnshn() { return dstnshn; }

	int Number() { return number; }

	Aeroflot Search(char*, int);

	friend ostream &operator<<(ostream &out, Aeroflot& d)
	{
		out << d.FIO<< " " << d.dstnshn << " " << d.number << " " << d.depar_date << " ";

		return out;
	}

};


