#pragma once
#include <iostream>
#include <vector>
#include "Movie.h"
#include <set>

using namespace std;

class EdgeList {
private:
	vector<pair<Movie, Movie>> eList;
	Movie last;

public:
	EdgeList() {};
	void insert(Movie to);
	void insertEdge(Movie from, Movie to);
	bool isEdge(Movie from, Movie to);
	vector<Movie> getAdjacent(Movie vertex);
	vector<pair<Movie, Movie>> getEdgeList();
};


