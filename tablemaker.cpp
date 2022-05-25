/*
 * tablemaker.cpp
 *
 *  Created on: 11 mai 2022
 *      Author: jcomble
 */

#include "tablemaker.h"
#include "node.h"
#include "connection.h"
#include "traffic.h"
#include <vector>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <iostream>

using namespace std;

TableMaker::TableMaker(string content) {
	set_content(content);
	build_tables();
}

TableMaker::TableMaker() {
	this->content = "";
};
TableMaker::~TableMaker(){};




void TableMaker::set_content(string content) {
	this->content = content;
}

vector<string> TableMaker::get_lines_vector(string chaine) {
	vector<string> vect;
	string copy_chaine = chaine;
	while (copy_chaine.find("\n") != string::npos) {
		string tmp_string = copy_chaine.substr(0, copy_chaine.find("\n"));
		vect.push_back(tmp_string);
		copy_chaine = copy_chaine.substr(copy_chaine.find("\n") + 1, copy_chaine.length() - tmp_string.length() - 1);
	}
	vect.push_back(copy_chaine);
	return vect;
}

int TableMaker::build_tables() {
	vector<Node> tmp_vector_nodes;
	vector<Traffic> tmp_vector_traffics;
	vector<Connection> tmp_vector_connections;
	int length = this->content.length();
	vector<string> tmp_vector_lines = get_lines_vector(this->content);
	bool check = true;
	int count = 0;
	vector<int> vector_numero;
	vector<Node> nodeArray;
	for (string line : tmp_vector_lines) {
		vector<string> vect = get_vector(line);
		short type = check_vect(vect);
		if (type == 7) {
			;
		} else if (count == 0 && type == 1) {
			count = 1;
		} else if (count == 1 && type == 3) {
			count = 2;
		} else if (count == 2 && type == 5) {
			count = 3;
		} else if (count == 1 && type == 2) {
			string tmp_string_numero = vect.at(0);
			int length = tmp_string_numero.length();
			int tmp_numero = atoi(tmp_string_numero.substr(5, length - 6).c_str());
			for (int elem : vector_numero) {
				if (elem == tmp_numero) {
					check = false;
					break;
				}
			}
			Node tmp_node = parse2(vect);
			tmp_vector_nodes.push_back(tmp_node);
			vector_numero.push_back(tmp_numero);
		} else if (type == 4 && (count == 2 || (count == 3 && vect.size() == 2))) {
			vector<Node> tmp_list_node_traffic;
			vector<Node> tmp_list_node_connection;
			for (const string elem : vect) {
				int length = elem.length();
				int tmp_numero = atoi(elem.substr(5, length - 6).c_str());
				check = false;
				for (Node tmp_node : tmp_vector_nodes) {
					if (tmp_numero == tmp_node.get_id()) {
						check = true;
						if (count == 2) {
							tmp_list_node_traffic.push_back(tmp_node);
						} else {
							tmp_list_node_connection.push_back(tmp_node);
						}
						break;
					}
				}
				if (!check) {
					break;
				}
			}
			if (count == 2) {
				Traffic tmp_traffic = Traffic(tmp_list_node_traffic);
				tmp_vector_traffics.push_back(tmp_traffic);
			} else {
				Connection tmp_connection = Connection(tmp_list_node_connection.at(0), tmp_list_node_connection.at(1));
				tmp_vector_connections.push_back(tmp_connection);
			}
		} else {
			check = false;
		}
		if (!check) {
			this->vector_nodes.clear();
			this->vector_traffics.clear();
			this->vector_connections.clear();
			break;
		}
	}
	if (check) {
		this->vector_nodes = tmp_vector_nodes;
		this->vector_traffics = tmp_vector_traffics;
		this->vector_connections = tmp_vector_connections;
		return 0;
	}
	return 1;
}

Node TableMaker::parse2(vector<string> vect) {
	int num_node = atoi(vect[0].substr(5, vect[0].length() - 6).c_str());
	int node_x = atoi(vect[1].c_str());
	int node_y = atoi(vect[2].c_str());
	Node node = Node(num_node, node_x, node_y);
	return node;
}

vector<Node> TableMaker::get_nodes() const {
	return this->vector_nodes;
}

vector<Traffic> TableMaker::get_traffics() const {
	return this->vector_traffics;
}

vector<Connection> TableMaker::get_connections() const {
	return this->vector_connections;
}

void TableMaker::nodes_display() const {
	string result_display = "[";
	int length = this->vector_nodes.size();
	for (int iterator = 0; iterator < length; iterator++) {
		Node tmp_node = this->vector_nodes.at(iterator);
		result_display.append("(\"Node" + to_string(tmp_node.get_id()) + "\", " + to_string(tmp_node.get_X()) + ", " + to_string(tmp_node.get_Y()) + ")");
		if (iterator != length - 1) {
			result_display.append(",\n");
		}
	}
	result_display.append("]");
	cout << result_display << endl;
}

void TableMaker::traffics_display() const {
	string result_display = "[";
	int length_traffics = this->vector_traffics.size();
	for (int iterator = 0; iterator < length_traffics; iterator++) {
		result_display.append("(");
		Traffic tmp_traffic = this->vector_traffics.at(iterator);
		vector<Node> tmp_nodes = tmp_traffic.get_traffic();
		int length_nodes = tmp_nodes.size();
		for (int iterator2 = 0; iterator2 < length_nodes; iterator2++){
			Node tmp_node = tmp_nodes.at(iterator2);
			result_display.append("\"Node" + to_string(tmp_node.get_id()) + "\"");
			if (iterator2 != length_nodes - 1) {
				result_display.append("->");
			}
		}
		result_display.append(")");
		if (iterator != length_traffics - 1) {
			result_display.append(",\n");
		}
	}
	result_display.append("]");
	cout << result_display << endl;
}

void TableMaker::connections_display() const {
	string result_display = "[";
		int length_connections = this->vector_connections.size();
		for (int iterator = 0; iterator < length_connections; iterator++) {
			Connection tmp_connections = this->vector_connections.at(iterator);
			Node node1 = tmp_connections.get_node_debut();
			Node node2 = tmp_connections.get_node_fin();
			result_display.append("(\"Node" + to_string(node1.get_id()) + "\"--\"Node" + to_string(node2.get_id()) + "\")");
			if (iterator != length_connections - 1) {
				result_display.append(",\n");
			}
		}
		result_display.append("]");
		cout << result_display << endl;
}

void TableMaker::display() const {
	nodes_display();
	connections_display();
	traffics_display();
}

bool TableMaker::check_valid() const {
	return (this->vector_connections.size() != 0 && this->vector_nodes.size() != 0
			&& this->vector_traffics.size() != 0);
}
