#include "EdgeList.h"

bool EdgeList::isEdge(Movie from, Movie to) {
	for (pair<Movie, Movie>& a : eList) {
		if (a.first.title.compare(from.title) == 0) {
			if (a.second.title.compare(to.title) == 0) {
				return true;
			}
		}
	}
	return false;
}

void EdgeList::insert(Movie to) {
	if (!eList.empty()) {
		eList.push_back(pair<Movie, Movie>(last, to));	}
	else {
		eList.push_back(pair<Movie, Movie>(last, to));//first node is empty placeholder
	}
	last = to;
}

void EdgeList::insertEdge(Movie from, Movie to) {
	bool add = true;
	if (!eList.empty()) {
		if (isEdge(from, to)) { add = false; }
	}
	if (add) {
		eList.push_back(pair<Movie, Movie>(from, to));
		last = to;
	}
}

vector<Movie> EdgeList::getAdjacent(Movie vertex) {
	vector<Movie> mov;
	set<string> d;
	for (pair<Movie, Movie>& a : eList) {
		if (a.first.title.compare(vertex.title) == 0) {
			if (d.find(a.second.title) != d.end()) {
				mov.push_back(a.second);
				d.insert(a.second.title);
			}
		}
		if (a.second.title.compare(vertex.title) == 0) {
			if (d.find(a.first.title) != d.end()) {
				mov.push_back(a.first);
				d.insert(a.first.title);
			}
		}
	}
	return mov;
}

vector<pair<Movie, Movie>> EdgeList::getEdgeList() {
	return eList;
}