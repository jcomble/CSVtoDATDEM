/*
 * tablemaker.h
 *
 *  Created on: 11 mai 2022
 *      Author: jcomble
 */
#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <fstream>
#include "node.h"
#include "traffic.h"
#include "connection.h"
#include "FileChecker.h"
using namespace std;
#ifndef TABLEMAKER_H_
#define TABLEMAKER_H_
class TableMaker : public FileChecker {
	private:
		// test brut du fichier 
		string content;
		// liste qui contient les nodes du csv
		vector<Node> vector_nodes;
		// liste qui contient les traffics du csv
		vector<Traffic> vector_traffics;
		// liste qui contient les connections du csv
		vector<Connection> vector_connections;
		// liste des lignes 
		vector<string> get_lines_vector(const string chaine);
		// return node si la list est de de forme d'une node et null sinon
		Node parse2(vector<string> vect);
		// a partir du contenue il construit la list des nodes, traffics, connection et les affecte au attrs 
		int build_tables();
	public:
		void set_content(string content);
		TableMaker();
		~TableMaker();
		TableMaker(string content);
		void nodes_display() const;
		void traffics_display() const;
		void connections_display() const;
		void display() const;
		bool check_valid() const;
		vector<Node> get_nodes() const;
		vector<Traffic> get_traffics() const;
		vector<Connection> get_connections() const;

};

#endif /* TABLEMAKER_H_ */
