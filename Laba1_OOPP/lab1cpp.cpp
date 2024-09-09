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
		cout << "Выберите номер из списка:" << endl;
		cout << "1. Добавить фильм" << endl;
		cout << "2. Вывести все добавленные фильмы" << endl;
		cout << "3. Удалить все добавленные фильмы" << endl;
		cout << "4. Вывести в файл все добавленные фильмы" << endl;
		cout << "5. Загрузить из файла все фильмы" << endl;
		cout << "0. Выход" << endl;
		cout << "Выбранный номер: ";
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
			cout << "Ошибка, неправильный ввод, попробуйте еще раз!\n";
			break;
		}
	}
}
