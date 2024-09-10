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
			cout << "Ошибка, неправильный ввод, попробуйте еще раз!\n";
			break;
		}
	}
}
