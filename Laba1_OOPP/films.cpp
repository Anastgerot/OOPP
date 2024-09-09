#include "films.h"
#include "Utils.h"
#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

using namespace std;

istream& operator >> (istream& in, films& fl)
{
	cout << "������� �������� ������: ";
	in >> ws;
	getline(in, fl.title);
	cout << "������� ��� �������: ";
	fl.year = GetCorrectNumber(1895, 2024);
	cout << "������� �����: ";
	in >> ws;
	getline(in, fl.genre);
	cout << "������� ������� ������: ";
	fl.rating = GetCorrectNumber(0.0, 10.0);
	cout << "������� ������: ";
	in >> ws;
	getline(in, fl.country);
	cout << "������� ���������: ";
	in >> ws;
	getline(in, fl.director);
	cout << "����� � �������? (1 - ��, 0 - ���): ";
	fl.is_available = GetCorrectNumber(0, 1);
	cout << "��� ����� ������� ��������" << endl;
	return in;
}
ostream& operator << (ostream& out, const films& fl)
{
	out << "�����:\n";
	out << "�������� ������: " << fl.title << endl
		<< "��� �������: " << fl.year  << endl
		<< "�����: " << fl.genre << endl
		<< "�������: " << fl.rating << endl
		<< "������: " << fl.country << endl
		<< "��������: " << fl.director << endl
		<< "����� � �������? (1 - ��, 0 - ���): " << fl.is_available << endl;
	return out;
}
