/*
 * FileChecker.h
 *
 *  Created on: 24 mai 2022
 *      Author: jcomble
 */

#ifndef FILECHECKER_H_
#define FILECHECKER_H_
#include <vector>
#include <iostream>

class FileChecker {
protected:
	FileChecker();
	virtual ~FileChecker();
	virtual bool check_valid() const = 0;
	virtual void display() const = 0;
	std::vector<std::string> get_vector(const std::string chaine);
	bool isNumber(std::string chaine);
	bool is_named_node(std::string chaine);
	short check_vect(std::vector<std::string> vect);
};

#endif /* FILECHECKER_H_ */
