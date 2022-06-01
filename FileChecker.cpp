/*
 * FileChecker.cpp
 *
 *  Created on: 24 mai 2022
 *      Author: jcomble
 */

#include "FileChecker.h"

/**
 * Constructeur par défaut d'argument
 */
FileChecker::FileChecker() {
}

/**
 * Destructeur
 */
FileChecker::~FileChecker() {
}

/**
 * Split par ',' une chaine de caractère en un vecteur de string.
 */
std::vector<std::string> FileChecker::get_vector(const std::string chaine) {
	std::vector<std::string> vect;
	std::string copy_chaine = chaine;
	while (copy_chaine.find(",") != std::string::npos) {
		std::string tmp_string = copy_chaine.substr(0, copy_chaine.find(","));
		vect.push_back(tmp_string);
		copy_chaine = copy_chaine.substr(copy_chaine.find(",") + 1, copy_chaine.length() - tmp_string.length() - 1);
	}
	vect.push_back(copy_chaine);
	return vect;
}

/**
 * Détermine si une chaîne de caractère est une représentation d'un nombre entier naturel.
 */
bool FileChecker::isNumber(std::string chaine) {
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

/**
 * Détermine si une chaîne de caractère est de la forme "Node[0-9][0-9]*"
 */
bool FileChecker::is_named_node(std::string chaine) {
	int length = chaine.length();
	if (length < 6) {
		return false;
	}
	if (chaine.substr(0, 5) != "\"Node" || chaine.substr(length - 1, 1) != "\"" || !isNumber(chaine.substr(5, length - 6))) {
		return false;
	}
	return true;
}

/**
 * Détermine quel type de ligne il s'agit:
 * 1) "Node",,
 * 2) "Node1",12,34
 * 3) "traffic",,
 * 4) "Node1","Node2",...
 * 5) "connection",,
 * 6) Aucun des cas précédents
 * 7) Une ligne vide.
 */
short FileChecker::check_vect(std::vector<std::string> vect) {
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
		for (const std::string elem : vect) {
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
