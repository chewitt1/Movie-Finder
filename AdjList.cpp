#include "AdjList.h"
void AdjList::add(Movie to, Movie from) {
	adjList.push_back(pair<Movie, vector<Movie>>(to, vector<Movie>()));
	adjList[0].second.push_back(to);
}

void AdjList::insert(Movie to) {//modified for my purposes (one long path)
	if (front.first.title.compare("") != 0) {
		if (!isEdge(front.first, to)) {
			adjList[0].second.push_back(to);
		}
	}
	else {
		adjList.push_back(pair<Movie, vector<Movie>>(to,vector<Movie>()));
		front = adjList[0];
	}
}

void AdjList::insertEdge(Movie from, Movie to) {//theoretical
	if (!adjList.empty()) {
		if (!isEdge(from, to)) { add(from, to); }
	}
	else{ add(from, to); }
}

bool AdjList::isEdge(Movie from, Movie to) {
	if (!adjList.empty()) {
		for (pair<Movie, vector<Movie>>& a : adjList) {
			if (a.first.title.compare(from.title) == 0) {
				vector<Movie> d = a.second;
				for (Movie& b : d) {
					if (b.title.compare(to.title) == 0) {
						return true;
					}
				}
			}
		}
	}
	return false;
}

vector<Movie> AdjList::getAdjacent(Movie vertex) {//theoretical
	vector<Movie> out;
	set<string> in;
	if (!adjList.empty()) {
		for (pair<Movie, vector<Movie>>& a : adjList) {
			if (a.first.title.compare(vertex.title) == 0) {
				for (Movie& b : a.second) {
					if (in.find(b.title) != in.end()) {
						out.push_back(b);
						in.insert(b.title);
					}
				}
			}
			else{
				for (Movie& b : a.second) {
					if (b.title.compare(vertex.title) == 0) {
						if (in.find(b.title) != in.end()) {
							out.push_back(b);
							in.insert(b.title);
							break;
						}
					}
				}
			}
		}

	}
	return out;
}

vector<pair<Movie, vector<Movie>>> AdjList::getAdjList() {
	return adjList;
}