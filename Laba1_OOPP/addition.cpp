#include "addition.h"
#include <iostream>
#include <string>
#include <locale>
#include <windows.h>
#include <fstream>
#include <vector>
#include "Utils.h"
#include "films.h"

using namespace std;

void addition::start()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    locale::global(locale("Russian"));
}

void addition::AddFilm(vector<films*>& movies)
{
    films* fl1 = new films();
    cin >> *fl1;
    movies.push_back(fl1);
}

void addition::View_all(const vector<films*>& movies)
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

void addition::Clear_Films(vector<films*>& movies)
{
    for (auto& movie : movies) {
        delete movie; 
    }
    movies.clear();
    cout << "Все фильмы удалены." << endl;
}

void addition::Save_movies(const vector<films*>& movies)
{
    if (movies.empty())
    {
        cout << "Нет данных для сохранения" << endl;
        return;
    }

    string filename;
    cout << "Введите название файла: ";
    cin >> filename;

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

void addition::Load_movies(vector<films*>& movies)
{
    int count_movies = 0;
    ifstream fin;
    string filename;
    cout << "Введите название файла, из которого необходимо считать данные: ";
    cin >> filename;
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
        fin.close();
    }
}