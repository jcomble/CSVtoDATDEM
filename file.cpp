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

}
File::File() {
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
		int count_error_number_line = 0;
		while (!in_file.eof()) {
			count_error_number_line += 1;
			getline(in_file, line);
			this->content.append(line + "\n");
			vector<string> vect = get_vector(line);
			short type = check_vect(vect);
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
						cout << "Noeud " << tmp_numero << " non défini!" << endl;
						check = false;
						break;
					}
				}
				vector_numero.push_back(tmp_numero);
			} else if (type == 4 && ((count == 2 && vect.size() >= 2) || (count == 3 && vect.size() == 2))) {
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
						cout << "Noeud " << tmp_numero << " non défini!" << endl;
						break;
					}
				}
			} else {
				cout << "Erreur ligne " << count_error_number_line << "!" << endl;
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

string File::get_content() const {
	return this->content;
}

bool File::check_valid() const {
	return this->content != "";
}

void File::display() const {
	cout << "File(\"" << this->content << "\")" << endl;
}
