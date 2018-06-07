// ConsoleApplication3.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include "Map.h"
#include "Element.h"
#include "Aeroflot.h"
#include <fstream>
#include <Windows.h>

using namespace std;

//Функция вывода всех элементов на экран

void print(Aeroflot* array, int count, int number) {

	setlocale(LC_ALL, "Russian");

	system("CLS");

	if (number == 0) {

		if (count == 0) { cout << "Заявок не создано" << endl; }

		else {

			for (int i = 0; i < count; i++) {

				cout << (i + 1) << ") ";

				cout << array[i].Fio() << " ";

				cout << array[i].Dstnshn() << " ";
				
				cout << array[i].DeparDate() << " ";

				cout << array[i].Number() << "\n";

			}

		}

	}

	else {

		int k = 0;

		for (int i = 0; i < count; i++) {

			cout << k << ") " << array[i].Fio() << " ";

			cout << array[i].Dstnshn() << " ";
			
			cout << array[i].DeparDate() << " ";

			printf("%d\n", array[i].Number());

			k++;

		}

	}

}



int main()
{

	setlocale(LC_ALL, "Russian");

	char Menu[] = "Menu:\n1) Добавть заявку\n2) Удалить заявку\n3) Вывод заявки по номеру рейса и дате вылета\n4) Выйти\n";

	Map<char* , Aeroflot> arr_aero(4);

	ifstream Enter("C:\\Exp\\Save.txt");

	char simvol[128];

	Enter.get(simvol, 128, ' ');

	char* fio = new char[100];

	char* destn = new char[100];

	int number;

	char* dd = new char[100];

	int i = 0;

	//Получение данных из файла

	while (simvol[0] != '\0') {

		if (i == 4) {

			i = 0;

			Aeroflot aero_save;
			arr_aero.Put(fio, Aeroflot(fio, destn, number, dd));

			if (simvol[0] == '\n') { break; }

		}

		if (i == 0) { strcpy_s(fio, 100, simvol); }

		else if (i == 1) { strcpy_s(destn, 100, simvol); }

		else if (i == 2) { number = atoi(simvol); }

		else if (i == 3) { strcpy_s(dd, 100, simvol); }

		i++;

		Enter.get(simvol[0]);

		int a = 1;

		while (simvol[a] != '\0') {

			simvol[a] = NULL;

			a++;

		}

		Enter.get(simvol, 128, ' ');

		delete[] fio;
		delete[] destn;
		delete[] dd;
	}

	Enter.close();

	while (1)
	{
		system("CLS");

		Aeroflot* aero_flot = nullptr;

		arr_aero.GetALL(aero_flot);

		print(aero_flot, arr_aero.Count(), 0);

		cout << Menu;

		int d;

		cin >> d;

		//Выбор номера функции из меню по средством конструкции switch

		switch (d)
		{
		case 1:
		{
			Aeroflot aero;

			char* _fio = new char[100];

			char* _destn = new char[100];

			char* _dd = new char[100];

			int _num;

			cout << "Введите Фамилию и инициалы: ";

			cin >> _fio;

			cout << "Введите пункт назначения: ";
			
			cin >> _destn;

			cout << "Введите желаюмую дату вылета: ";

			cin >> _dd;

			cout << "Введите номер рейса: ";

			cin >> _num;

			aero.Add(_fio, _destn, _num, _dd);

			arr_aero.Put(_fio, aero);

			delete[] _fio;
			delete[] _destn;
			delete[] _dd;

			break;
		}
		case 2:
		{
			cout << "Выберете № заявки, которую хотите удалить: ";

			int n;

			cin >> n;

			if (n > arr_aero.Count())
			{
				cout << "Выбрана не существующая заявка";

				Sleep(2000);

				break;
			}

			for (int i = 0; i < arr_aero.Count(); i++)
			{
				if ((n - 1) == i)
				{
					Aeroflot h = *arr_aero.Get(i);
					arr_aero.Remove(h);
				}
			}


			break;
		}
		case 3:
		{
			char* _dd = new char[100];

			int _num;

			Map<char*, Aeroflot> tmp(4);

			cout << "Введите номер рейca: ";

			cin >> _num;

			cout << "Введите пункт назначения: ";

			cin >> _dd;

			for (int i = 0; i < arr_aero.Count(); i++)
			{
				Aeroflot t_m_p;
				t_m_p = arr_aero.Get(i);
				if (t_m_p.Search(_dd, _num))
				{
					tmp.Put(_dd, t_m_p);
				}
				
			}

			Aeroflot* _tmp = nullptr;

			tmp.GetALL(_tmp);

			print(_tmp, tmp.Count(), 0);

			Sleep(6000);

			delete[] _dd;
			break;
		}

		//Сохранение в файл

		case 4:
		{
			ofstream Exit("C:\\Exp\\Save.txt");

			Aeroflot* arr_save = nullptr;

			arr_aero.GetALL(arr_save);

			for (int i = 0; i < arr_aero.Count(); i++) {

				Exit << arr_save[i];

			}
			
			Exit << "\n";

			Exit.close();

			return 0;
		}
		default: cout << "Не верный номер";
			break;
		}
	}

	return 0;
}

