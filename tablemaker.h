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
#include "connection.h"
#include "FileChecker.h"
#include "file.h"

#ifndef TABLEMAKER_H_
#define TABLEMAKER_H_
class TableMaker : public FileChecker {
	private:
		std::string content;
		std::vector<Node> vector_nodes;
		std::vector<std::vector<Node>> vector_traffics;
		std::vector<Connection> vector_connections;
		void vectors_clear();
		bool check_valid_line(std::string *line,
							int *count,
							std::vector<Node> *tmp_vector_nodes,
							std::vector<std::vector<Node>> *tmp_vector_traffics,
							std::vector<Connection> *tmp_vector_connections,
							int error_line_number);
		bool update_traffics(std::vector<std::string> *vect,
							std::vector<Node> *vector_nodes,
							std::vector<std::vector<Node>> *vector_traffics);
		bool update_connections(std::vector<std::string> *vect,
							std::vector<Node> *vector_nodes,
							std::vector<Connection> *vector_connections);
		std::vector<std::string> get_lines_vector(const std::string chaine);
		Node parse2(std::vector<std::string> vect);
		bool update_nodes(std::vector<std::string> *vect, std::vector<Node> *vector_nodes);
		int build_tables();
	public:
		void set_content(std::string content);
		TableMaker();
		~TableMaker();
		TableMaker(File file);
		TableMaker(std::string content);
		void nodes_display() const;
		void traffics_display() const;
		void connections_display() const;
		void display() const;
		bool check_valid() const;
		std::vector<Node> get_nodes() const;
		std::vector<std::vector<Node>> get_traffics() const;
		std::vector<Connection> get_connections() const;

};

#endif /* TABLEMAKER_H_ */
