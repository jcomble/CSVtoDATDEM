/*
 * File.h
 *
 *  Created on: 9 mai 2022
 *      Author: jcomble
 */

#ifndef FILE_H_
#define FILE_H_

#include <fstream>
#include <vector>
#include <iostream>
#include <string.h>
#include "FileChecker.h"

/**
 * Classe récupérant le contenu (string) d'un fichier et vérifie si le contenu est valide.
 */
class File : public FileChecker {
private:
	bool check_valid_line(std::string *line, int *count, std::vector<int> *vector_numero, int count_error_number_line);
	void build_content(std::ifstream *in_file);
	bool check_existing_nodes(std::vector<std::string> *vect, std::vector<int> *vector_numero);
	bool update_nodes(std::vector<std::string> *vect, std::vector<int> *vector_numero);
	bool check_extension(const char *filename);
	std::string content;
	void read_content(const char *filename);
public:
	File(const char *filename);
	File();
	virtual ~File();
	bool check_valid() const;
	void display() const;
	std::string get_content() const;
};

#endif /* FILE_H_ */
