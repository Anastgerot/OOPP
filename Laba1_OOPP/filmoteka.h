#pragma once
#include <iostream>
#include <vector>
#include "Utils.h"
#include "films.h"

class filmoteka
{
private:
	vector<films*> movies;
public:
	~filmoteka() { Clear_Films(); }
	void start();
	void AddFilm();
	void View_all();
	void Clear_Films();
	void Save_movies();
	void Load_movies();
};

