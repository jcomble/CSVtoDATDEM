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
#include "FileChecker.h"

using namespace std;
class File : public FileChecker {
private:
	string content;
	void read_content(const char *filename);
public:
	File(const char *filename);
	File();
	virtual ~File();
	bool check_valid() const;
	void display() const;
	string get_content() const;
};

#endif /* FILE_H_ */
