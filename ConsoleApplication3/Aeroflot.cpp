#include "stdafx.h"
#include "Aeroflot.h"


Aeroflot::Aeroflot()
{
	
}

Aeroflot::Aeroflot(char* fio, char* dst, int num, char* dd)
{
	for (int i = 0; i < 100; i++)  FIO[i] = fio[i];

	for (int i = 0; i < 100; i++) dstnshn[i] = dst[i];

	for (int i = 0; i < 100; i++)depar_date[i] = dd[i];

	this->number = num;
}



void Aeroflot::Add(char* fio, char* dst, int num, char* dd)
{
	for (int i = 0; i < 100; i++) this->FIO[i] = fio[i];

	for (int i = 0; i < 100; i++) this->dstnshn[i] = dst[i];

	for (int i = 0; i < 100; i++) this->depar_date[i] = dd[i];

	this->number = num;
}

Aeroflot::~Aeroflot()
{
}

int Aeroflot::operator==(Aeroflot& tmp)
{
	if (((strcmp(tmp.FIO, FIO)) == 0) &
		((strcmp(tmp.dstnshn, dstnshn)) == 0) &
		((strcmp(tmp.depar_date, depar_date)) == 0) &
		(tmp.number == number)) return 1;
	
	else return 0;
		
}


Aeroflot Aeroflot::operator=(Aeroflot* tmp)
{
	for (int i = 0; i < 100; i++) this->FIO[i] = tmp->FIO[i];

	for (int i = 0; i < 100; i++) this->dstnshn[i] = tmp->dstnshn[i];

	for (int i = 0; i < 100; i++) this->depar_date[i] = tmp->depar_date[i];

	this->number = tmp->number;

	return *this;
}


Aeroflot* Aeroflot::Search(char* dd, int num)
{
	if ((strcmp(this->depar_date, dd) == 0) & (this->number == num)) return this;

	else
	{
		return NULL;
	}
}

