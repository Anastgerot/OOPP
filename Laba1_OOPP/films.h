#pragma once
#include <iostream>
using namespace std;

class films
{
public:
	string title = "";
	int year = 0;
	string genre = "";
	double rating = 0;
	string country = "";
	string director = "";
	bool is_available = false;
	friend ostream& operator << (ostream& out, const films& fl);
	friend istream& operator >>  (istream& in, films& fl);
};

