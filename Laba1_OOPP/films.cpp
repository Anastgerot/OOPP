#include "films.h"
#include "Utils.h"
#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

using namespace std;

istream& operator >> (istream& in, films& fl)
{
	cout << "Введите название фильма: ";
	in >> ws;
	getline(in, fl.title);
	cout << "Введите год выпуска: ";
	fl.year = GetCorrectNumber(1895, 2024);
	cout << "Введите жанры: ";
	in >> ws;
	getline(in, fl.genre);
	cout << "Введите рейтинг фильма: ";
	fl.rating = GetCorrectNumber(0.0, 10.0);
	cout << "Введите страну: ";
	in >> ws;
	getline(in, fl.country);
	cout << "Введите режиссера: ";
	in >> ws;
	getline(in, fl.director);
	cout << "Фильм в прокате? (1 - Да, 0 - Нет): ";
	fl.is_available = GetCorrectNumber(0, 1);
	cout << "Ваш фильм успешно добавлен" << endl;
	return in;
}
ostream& operator << (ostream& out, const films& fl)
{
	out << "Фильм:\n";
	out << "Название фильма: " << fl.title << endl
		<< "Год выпуска: " << fl.year  << endl
		<< "Жанры: " << fl.genre << endl
		<< "Рейтинг: " << fl.rating << endl
		<< "Страна: " << fl.country << endl
		<< "Режиссер: " << fl.director << endl
		<< "Фильм в прокате? (1 - Да, 0 - Нет): " << fl.is_available << endl;
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
	cout << movie.title << " успешно скачан из файла!" << endl;
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