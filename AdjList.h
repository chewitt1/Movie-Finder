#pragma once
#include "Movie.h"
#include <map>
#include <set>
class AdjList
{
private:
    vector<pair<Movie, vector<Movie>>> adjList;
    pair<Movie, vector<Movie>> front;
public:
    void add(Movie to, Movie from);
    void insert(Movie to);
    void insertEdge(Movie from, Movie to);
    bool isEdge(Movie from, Movie to);
    vector<Movie> getAdjacent(Movie vertex);
    vector<pair<Movie, vector<Movie>>> getAdjList();
};


