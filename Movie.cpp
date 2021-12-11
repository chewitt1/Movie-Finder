#include "Movie.h"

Movie::Movie(string line) {
	//TITLE
	size_t i = line.find_first_of('\t');
	title = line.substr(0, i);

	line = line.substr(i);
	string check = line.substr(0, 12);
	size_t c = check.find("Null");
	if (c != string::npos) {
		i = c + 5;
	}

	else{
		//GET VALS
		size_t f = line.find_first_of('\'');
		line = line.substr(f);

		//GENRES
		i = line.find_first_of('\"') + 1;
		string gVals = line.substr(0, i);

		size_t found = gVals.find("Action");
		if (found != string::npos) {
			genre.push_back("Action");
		}
		found = gVals.find("Comedy");
		if (found != string::npos) {
			genre.push_back("Comedy");
		}
		found = gVals.find("Drama");
		if (found != string::npos) {
			genre.push_back("Drama");
		}
		found = gVals.find("Fantasy");
		if (found != string::npos) {
			genre.push_back("Fantasy");
		}
		found = gVals.find("Horror");
		if (found != string::npos) {
			genre.push_back("Horror");
		}
		found = gVals.find("Mystery");
		if (found != string::npos) {
			genre.push_back("Mystery");
		}
		found = gVals.find("Romance");
		if (found != string::npos) {
			genre.push_back("Romance");
		}
		found = gVals.find("Thriller");
		if (found != string::npos) {
			genre.push_back("Thriller");
		}

		//TYPES	
		found = gVals.find("Documentary");
		if (found != string::npos) {
			type.push_back("Documentary");
		}
		found = gVals.find("Animation");
		if (found != string::npos) {
			type.push_back("Animation");
		}
	}
	
	//DATE
	line = line.substr(i + 1);
	i = line.find_first_of('\t');
	try {
		date = stoi(line.substr(i - 4, i));
	}
	catch (std::out_of_range&) {
		date = 0;
	}

	//RATING
	line = line.substr(i + 1);
	i = line.find_first_of('\t') + 1;
	try {
		rating = stof(line.substr(0, i));
	}
	catch (std::out_of_range&) {
		rating = 0;
	}

	//RUNTIME
	line = line.substr(i);
	i = line.find_first_of('\t');
	try {
		runtime = stoi(line.substr(0, i));
	}
	catch (std::invalid_argument&) {
		runtime = 0;
	}
	catch (std::out_of_range&) {
		rating = 0;
	}

	if (runtime > 70) {
		type.push_back("Feature");
	}

	//LANGUAGE
	line = line.substr(i + 1);
	lang = line;

}