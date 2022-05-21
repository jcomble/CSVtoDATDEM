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
#include "Connection.h"

using namespace std;
#ifndef TABLEMAKER_H_
#define TABLEMAKER_H_

class TableMaker {
	private:
		string content;
		vector<Node> vector_nodes;
		vector<Traffic> vector_traffics;
		vector<Connection> vector_connections;
		vector<string> get_vector(const string chaine);
		vector<string> get_lines_vector(const string chaine);
		bool is_named_node(string chaine);
		bool isNumber(string chaine);

	public:
		void set_content(string content);
		TableMaker();
		~TableMaker();
		TableMaker(string content);
		void nodes_display();
		void traffics_display();
		void connections_display();
		Node parse2(vector<string> vect);
		int build_tables();
		vector<Node> get_nodes();
		vector<Traffic> get_traffics();
		vector<Connection> get_connections();
		short check_vect(vector<string> vect);
		vector<int> parse4(vector<string> vect);
		void write_type_2(Node nodeArray [], vector<string> vect, ofstream *out_dat_file, ofstream *out_dem_file);
		void write_type_4(Node nodeArray [], vector<string> vect, ofstream *out_dat_file, ofstream *out_dem_file);
};

#endif /* TABLEMAKER_H_ */
