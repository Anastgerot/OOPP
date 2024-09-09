#include <iostream>
#include <vector>
#include "films.h"
#include "Utils.h"
#include "addition.h"

using namespace std;
int main()
{
	addition add;
	add.start();
	vector<films*> movies;
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
			add.AddFilm(movies);
			break;
		case 2:
			add.View_all(movies);
			break;
		case 3:
			add.Clear_Films(movies);
			break;
		case 4:
			add.Save_movies(movies);
			break;
		case 5:
			add.Load_movies(movies);
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
