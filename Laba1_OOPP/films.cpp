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
ifstream& operator >> (ifstream& fin, films& movie)
{
	getline(fin, movie.title);
	fin >> movie.year;
	fin.ignore();
	getline(fin, movie.genre);
	fin >> movie.rating;
	fin.ignore();
	getline(fin, movie.country);
	getline(fin, movie.director);
	fin >> movie.is_available;
	fin.ignore();
	cout << movie.title << " ������� ������ �� �����!" << endl;
	return fin;
}
ofstream& operator << (ofstream& fout, const films& movie)
{
	fout << movie.title << endl
		<< movie.year << endl
		<< movie.genre << endl
		<< movie.rating << endl
		<< movie.country << endl
		<< movie.director << endl
		<< movie.is_available << endl;
	return fout;
}