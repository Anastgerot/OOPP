#include "filmoteka.h"
#include <iostream>
#include <string>
#include <locale>
#include <windows.h>
#include <fstream>
#include <vector>
#include "Utils.h"
#include "films.h"

using namespace std;

void filmoteka::start()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    locale::global(locale("Russian"));
}
void filmoteka::AddFilm()
{
    films* fl1 = new films();
    cin >> *fl1;
    movies.push_back(fl1);
}
void filmoteka::View_all()
{
    if (movies.empty())
    {
        cout << "Данные отсутствуют" << endl;
    }
    else
    {
        cout << "Все добавленные фильмы:" << endl;
        for (const auto& movie : movies) {
            cout << *movie << endl;
        }
    }
}
void filmoteka::Clear_Films()
{
    for (auto& movie : movies) {
        delete movie; 
    }
    movies.clear();
    cout << "Все фильмы удалены." << endl;
}

void filmoteka::Save_movies()
{
    if (movies.empty())
    {
        cout << "Нет данных для сохранения" << endl;
        return;
    }

    string filename;
    cout << "Введите название файла: ";
    cin.ignore();
    getline(cin, filename);

    ofstream fout;
    fout.open((filename + ".txt"), ios::trunc);
    if (fout.is_open())
    {
        fout << movies.size() << endl;
        for (const auto& movie : movies)
        {
            fout << (*movie).title << endl
                << (*movie).year << endl
                << (*movie).genre << endl
                << (*movie).rating << endl
                << (*movie).country << endl
                << (*movie).director << endl
                << (*movie).is_available << endl;
        }
        fout.close();
        cout << "Фильмы успешно сохранены в файл " << filename << ".txt" << endl;
    }
    else
    {
        cout << "Не найден файл с таким именем. " << filename << " Невозможно сохранить данные." << endl;
    }
}

void filmoteka::Load_movies()
{
    int count_movies = 0;
    ifstream fin;
    string filename;
    cout << "Введите название файла, из которого необходимо считать данные: ";
    cin.ignore();
    getline(cin, filename);
    fin.open((filename + ".txt"), ios::in);
    if (!fin.is_open())
    {
        cout << "Не найден файл с таким именем. " << filename << " Невозможно скачать данные." << endl;
    }
    else
    {
        for (auto& movie : movies) {
            delete movie;
        }
        movies.clear();

        fin >> count_movies;
        fin.ignore();
        if (!fin) {
            cout << "Неверный формат файла" << endl;
            Clear_Films();
            fin.close();
            return;
        }
        else {
            if (count_movies == 0)
            {
                cout << "Не найдено данных для скачивания." << endl;
            }
            else
            {
                for (int i = 0; i < count_movies; i++)
                {
                    films* movie = new films();
                    getline(fin, (*movie).title);
                    fin >> (*movie).year;
                    fin.ignore();
                    getline(fin, (*movie).genre);
                    fin >> (*movie).rating;
                    fin.ignore();
                    getline(fin, (*movie).country);
                    getline(fin, (*movie).director);
                    fin >> (*movie).is_available;
                    fin.ignore();

                    movies.push_back(movie);
                    cout << (*movie).title << " успешно скачан!" << endl;
                }
            }

        }
 
        fin.close();
    }
}