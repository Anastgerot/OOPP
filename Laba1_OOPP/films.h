#pragma once
#include <iostream>
using namespace std;

class films
{
private:
	string title = "";
	int year = 0;
	string genre = "";
	double rating = 0;
	string country = "";
	string director = "";
	bool is_available = false;
public:
	friend ostream& operator << (ostream& out, const films& fl);
	friend istream& operator >>  (istream& in, films& fl);
	friend ofstream& operator << (ofstream& fout, const films& movie);
	friend ifstream& operator >> (ifstream& fin, films& movie);
};

