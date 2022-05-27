/*
 * File.cpp
 *
 *  Created on: 9 mai 2022
 *      Author: jcomble
 */

#include "file.h"

File::File(const char *filename) {
	read_content(filename);
}

File::~File() {

}
File::File() {
	this->content = "";
}

bool File::check_extension(const char *filename){
	int file_length = strlen(filename);
	return file_length < 4
			|| filename[file_length - 4] != '.'
			|| filename[file_length - 3] != 'c'
			|| filename[file_length - 2] != 's'
			|| filename[file_length - 1] != 'v';
}

bool File::update_nodes(std::vector<std::string> *vect, std::vector<int> *vector_numero) {
	std::vector<std::string> tmp_vect = *vect;
	std::vector<int> tmp_vect_num= *vector_numero;
	std::string tmp_string_numero = tmp_vect.at(0);
	int length = tmp_string_numero.length();
	int tmp_numero = atoi(tmp_string_numero.substr(5, length - 6).c_str());
	for (int elem : tmp_vect_num) {
		if (elem == tmp_numero) {
			std::cout << "Noeud " << tmp_numero << " deja defini!" << std::endl;
			return false;
			break;
		}
	}
	tmp_vect_num.push_back(tmp_numero);
	*vector_numero = tmp_vect_num;
	return true;
}

bool File::check_existing_nodes(std::vector<std::string> *vect, std::vector<int> *vector_numero) {
	bool check = false;
	for (const std::string elem : *vect) {
		int length = elem.length();
		int tmp_numero = atoi(elem.substr(5, length - 6).c_str());
		check = false;
		for (int tmp_int : *vector_numero) {
			if (tmp_numero == tmp_int) {
				check = true;
				break;
			}
		}
		if (!check) {
			std::cout << "Noeud " << tmp_numero << " non défini!" << std::endl;
			break;
		}
	}
	return check;
}

bool File::check_valid_line(std::string *line,
							int *count,
							std::vector<int> *vector_numero,
							int count_error_number_line) {

	int tmp_count = *count;
	std::vector<std::string> vect = get_vector(*line);
	bool check = true;
	short type = check_vect(vect);
	if (tmp_count == 0 && type == 1) {
		tmp_count = 1;
	} else if (tmp_count == 1 && type == 3) {
		tmp_count = 2;
	} else if (tmp_count == 2 && type == 5) {
		tmp_count = 3;
	} else if (tmp_count == 1 && type == 2) {
		check = update_nodes(&vect, vector_numero);
	} else if (type == 4 && ((tmp_count == 2 && vect.size() >= 2) || (tmp_count == 3 && vect.size() == 2))) {
		check = check_existing_nodes(&vect, vector_numero);
	} else if (type != 7) {
		std::cout << "Erreur ligne " << count_error_number_line << "!" << std::endl;
		check = false;
	}
	*count = tmp_count;
	return check;
}

void File::read_content(const char *filename) {
	this->content = "";
	std::ifstream in_file;
	in_file.open(filename);
	int file_length = strlen(filename);
	if (check_extension(filename)){
		std::cout << "Mauvaise extension de fichier!" << std::endl;
		return;
	}
	if (!in_file.is_open()) {
		std::cout << "Fichier non ouvert!" << std::endl;
		return;
	}
	if (in_file.eof()) {
		std::cout << "Fichier vide!" << std::endl;
		return;
	}
	std::string line;
	std::vector<int> vector_numero;
	int count = 0;
	int error_line_number = 0;
	while (!in_file.eof()) {
		error_line_number += 1;
		getline(in_file, line);
		if (!check_valid_line(&line, &count, &vector_numero, error_line_number)) {
			this->content = "";
			break;
		}
		this->content.append(line + "\n");
	}
	in_file.close();
}

std::string File::get_content() const {
	return this->content;
}

bool File::check_valid() const {
	return this->content != "";
}

void File::display() const {
	std::cout << "File(\"" << this->content << "\")" << std::endl;
}
