/*
 * File.cpp
 *
 *  Created on: 9 mai 2022
 *      Author: jcomble
 */

#include "file.h"
#include <fstream>
#include <iostream>
#include <vector>
#include "node.h"
using namespace std;

File::File(const char *filename) {
	read_content(filename);
}

File::~File() {
	this->content = "";
}

void File::read_content(const char *filename) {
	this->content = "";
	ifstream in_file;
	in_file.open(filename);
	if (in_file.is_open()){
		string line;
		bool check = true;
		int count = 0;
		vector<int> vector_numero;
		while (!in_file.eof()) {
			getline(in_file, line);
			this->content.append(line + "\n");
			vector<string> vect = get_vector(line);
			short type = check_vect(vect);
			cout << line << endl;
			if (type == 7) {
				;
			} else if (count == 0 && type == 1) {
				count = 1;
			} else if (count == 1 && type == 3) {
				count = 2;
			} else if (count == 2 && type == 5) {
				count = 3;
			} else if (count == 1 && type == 2) {
				string tmp_string_numero = vect.at(0);
				int length = tmp_string_numero.length();
				int tmp_numero = atoi(tmp_string_numero.substr(5, length - 6).c_str());
				for (int elem : vector_numero) {
					if (elem == tmp_numero) {
						check = false;
						break;
					}
				}
				vector_numero.push_back(tmp_numero);
			} else if (type == 4 && (count == 2 || (count == 3 && vect.size() == 2))) {
				for (const string elem : vect) {
					int length = elem.length();
					int tmp_numero = atoi(elem.substr(5, length - 6).c_str());
					check = false;
					for (int tmp_int : vector_numero) {
						if (tmp_numero == tmp_int) {
							check = true;
							break;
						}
					}
					if (!check) {
						break;
					}
				}
			} else {
				check = false;
			}
			if (!check) {
				this->content = "";
				break;
			}
		}
	} else {
		this->content = "";
	}
	in_file.close();
}

string File::get_content(){
	return this->content;
}

short File::check_vect(vector<string> vect) {
	if (vect.size() == 1 && vect.at(0) == "") {
		return 7;
	}
	if (vect.size() == 3 && vect.at(0) == "\"Node\"" && vect.at(1) == "" && vect.at(2) == "") {
		return 1;
	} else if (vect.size() == 3 && is_named_node(vect.at(0)) && isNumber(vect.at(1)) && isNumber(vect.at(2))) {
		return 2;
	} else if (vect.size() == 3 && vect.at(0) == "\"traffic\"" && vect.at(1) == "" && vect.at(2) == "") {
		return 3;
	} else if (vect.size() == 3 && vect.at(0) == "\"connection\"" && vect.at(1) == "" && vect.at(2) == "") {
		return 5;
	} else {
		bool check = true;
		for (const string elem : vect) {
			if (!is_named_node(elem)) {
				check = false;
				break;
			}
		}
		if (check) {
			return 4;
		}
	}
	return 6;
}

bool File::isNumber(string chaine) {
	int length = chaine.length();
	bool check = true;
	if (length == 0) {
		check = false;
	}
	for (int i = 0; i < length; i++) {
		if ('0' > chaine[i] || chaine[i] > '9') {
			check = false;
		 	break;
		}
	}
	return check;
}

bool File::is_named_node(string chaine) {
	int length = chaine.length();
	if (length < 6) {
		return false;
	}
	if (chaine.substr(0, 5) != "\"Node" || chaine.substr(length - 1, 1) != "\"" || !isNumber(chaine.substr(5, length - 6))) {
		return false;
	}
	return true;
}

vector<string> File::get_vector(const string chaine) {
	vector<string> vect;
	string copy_chaine = chaine;
	while (copy_chaine.find(",") != string::npos) {
		string tmp_string = copy_chaine.substr(0, copy_chaine.find(","));
		vect.push_back(tmp_string);
		copy_chaine = copy_chaine.substr(copy_chaine.find(",") + 1, copy_chaine.length() - tmp_string.length() - 1);
	}
	vect.push_back(copy_chaine);
	return vect;
}

bool File::check_valid() {
	return this->content == "";
}
