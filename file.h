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
public:
	File(const char *filename);
	virtual ~File();
	bool check_valid();
	void read_content(const char *filename);
	string get_content();
};

#endif /* FILE_H_ */
