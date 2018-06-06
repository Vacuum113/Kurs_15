#include "stdafx.h"
#include "Aeroflot.h"


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
//
//Aeroflot Aeroflot::Search(char* dd, int num)
//{
//
//}

