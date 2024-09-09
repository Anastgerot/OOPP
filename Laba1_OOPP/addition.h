#pragma once
#include <iostream>
#include <vector>
#include "Utils.h"
#include "films.h"

class addition
{
public:
	void start();
	void AddFilm(vector<films*>& movies);
	void View_all(const vector<films*>& movies);
	void Clear_Films(vector<films*>& movies);
	void Save_movies(const vector<films*>& movies);
	void Load_movies(vector<films*>& movies);
};

