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

using namespace std;
#ifndef TABLEMAKER_H_
#define TABLEMAKER_H_

class TableMaker {
	private:
		// test brut du fichier 
		string content;
		// liste qui contient les nodes du csv
		vector<Node> vector_nodes;
		// liste qui contient les traffics du csv
		vector<Traffic> vector_traffics;
		// liste qui contient les connections du csv
		vector<Connection> vector_connections;
		// return une liste qui sera  une node , traffic , connection 
		vector<string> get_vector(const string chaine);
		// liste des lignes 
		vector<string> get_lines_vector(const string chaine);
		// verifier si c'est de la forme d'une node
		bool is_named_node(string chaine);
		// int(chaine )==int
		bool isNumber(string chaine);
		// qst 2 td
		short check_vect(vector<string> vect);
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

		vector<Node> get_nodes() const;
		vector<Traffic> get_traffics() const;
		vector<Connection> get_connections() const;

};

#endif /* TABLEMAKER_H_ */
