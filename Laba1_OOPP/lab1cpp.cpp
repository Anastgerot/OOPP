#include <iostream>
#include <vector>
#include "films.h"
#include "Utils.h"
#include "filmoteka.h"

using namespace std;
int main()
{
	filmoteka film;
	film.start();
	while (true) 
	{
		int choice;
		cout << "�������� ����� �� ������:" << endl;
		cout << "1. �������� �����" << endl;
		cout << "2. ������� ��� ����������� ������" << endl;
		cout << "3. ������� ��� ����������� ������" << endl;
		cout << "4. ������� � ���� ��� ����������� ������" << endl;
		cout << "5. ��������� �� ����� ��� ������" << endl;
		cout << "0. �����" << endl;
		cout << "��������� �����: ";
		choice = GetCorrectNumber(0, 5);
		switch (choice)
		{
		case 1:
			film.AddFilm();
			break;
		case 2:
			film.View_all();
			break;
		case 3:
			film.Clear_Films();
			break;
		case 4:
			film.Save_movies();
			break;
		case 5:
			film.Load_movies();
			break;
		case 0:
			return 0;
			break;
		default:
			cout << "������, ������������ ����, ���������� ��� ���!\n";
			break;
		}
	}
}
