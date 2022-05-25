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

using namespace std;
class File {
private:
	string content;
	vector<std::string> get_vector(const string chaine);
	bool isNumber(string chaine);
	bool is_named_node(string chaine);
	short check_vect(vector<string> vect);
	void read_content(const char *filename);
public:
	File(const char *filename);
	virtual ~File();
	bool check_valid() const;
	void display() const;
	string get_content() const;
};

#endif /* FILE_H_ */
