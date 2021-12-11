#pragma once
#include<iostream>
#include<string>
#include <vector>

using namespace std;

class Movie
{
	public:
		string title, lang;
		vector<string> genre, type;
		int date, runtime;
		float rating;
		Movie() : title(""), lang(""),date(0), runtime(0), rating(0.0) {};
		Movie(string line);
};

