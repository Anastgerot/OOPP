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
        cout << "������ �����������" << endl;
    }
    else
    {
        cout << "��� ����������� ������:" << endl;
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
    cout << "��� ������ �������." << endl;
}
void filmoteka::Save_movies()
{
    if (movies.empty())
    {
        cout << "��� ������ ��� ����������" << endl;
        return;
    }

    string filename;
    cout << "������� �������� �����: ";
    cin.ignore();
    getline(cin, filename);

    ofstream fout;
    fout.open((filename + ".txt"), ios::trunc);
    if (fout.is_open())
    {
        fout << movies.size() << endl;
        for (const auto& movie : movies)
        {
            fout << *movie << endl;
        }
        cout << "������ ������� ��������� � ���� " << filename << ".txt" << endl;
    }
    else
    {
        cout << "�� ������ ���� � ����� ������. " << filename << " ���������� ��������� ������." << endl;
    }
    fout.close();
}
void filmoteka::Load_movies()
{
    int count_movies = 0;
    ifstream fin;
    string filename;
    cout << "������� �������� �����, �� �������� ���������� ������� ������: ";
    cin.ignore();
    getline(cin, filename);
    fin.open((filename + ".txt"), ios::in);
    if (!fin.is_open())
    {
        cout << "�� ������ ���� � ����� ������. " << filename << " ���������� ������� ������." << endl;
    }
    else
    {
        Clear_Films();

        fin >> count_movies;
        fin.ignore();
        if (!fin) {
            cout << "�������� ������ �����" << endl;
            Clear_Films();
            fin.close();
            return;
        }
        else {
            if (count_movies == 0)
            {
                cout << "�� ������� ������ ��� ����������." << endl;
            }
            else
            {
                for (int i = 0; i < count_movies; i++)
                {
                    films* movie = new films();
                    movies.push_back(movie);
                    fin >> *movie;
                }
            }

        }
 
        fin.close();
    }
}