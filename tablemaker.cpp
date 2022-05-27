/*
 * tablemaker.cpp
 *
 *  Created on: 11 mai 2022
 *      Author: jcomble
 */

#include "tablemaker.h"

TableMaker::TableMaker(std::string content) {
	set_content(content);
	build_tables();
}

TableMaker::TableMaker(File file) {
	if (file.get_content().empty() || !file.check_valid()){
		std::cout << "Mauvais fichier!" << std::endl;
		return;
	}
	set_content(file.get_content());
	build_tables();
}

TableMaker::TableMaker() {
	this->content = "";
};

TableMaker::~TableMaker(){
};

void TableMaker::set_content(std::string content) {
	this->content = content;
}

std::vector<std::string> TableMaker::get_lines_vector(std::string chaine) {
	std::vector<std::string> vect;
	std::string copy_chaine = chaine;
	while (copy_chaine.find("\n") != std::string::npos) {
		std::string tmp_string = copy_chaine.substr(0, copy_chaine.find("\n"));
		vect.push_back(tmp_string);
		copy_chaine = copy_chaine.substr(copy_chaine.find("\n") + 1, copy_chaine.length() - tmp_string.length() - 1);
	}
	vect.push_back(copy_chaine);
	return vect;
}

void TableMaker::vectors_clear() {
	this->vector_nodes.clear();
	this->vector_traffics.clear();
	this->vector_connections.clear();
}

bool TableMaker::update_nodes(std::vector<std::string> *vect, std::vector<Node> *vector_nodes){
	std::vector<std::string> tmp_vect = *vect;
	std::vector<Node> tmp_vector_nodes = *vector_nodes;
	std::string tmp_string_numero = tmp_vect.at(0);
	int length = tmp_string_numero.length();
	int tmp_numero = atoi(tmp_string_numero.substr(5, length - 6).c_str());
	for (Node elem : tmp_vector_nodes) {
		if (elem.get_id() == tmp_numero) {
			return false;
			break;
		}
	}
	Node tmp_node = parse2(tmp_vect);
	tmp_vector_nodes.push_back(tmp_node);
	*vector_nodes = tmp_vector_nodes;
	return true;
}

bool TableMaker::update_traffics(std::vector<std::string> *vect,
					std::vector<Node> *vector_nodes,
					std::vector<Traffic> *vector_traffics){

	std::vector<Traffic> tmp_vector_traffics = *vector_traffics;
	std::vector<Node> tmp_list_node_traffic;
	for (const std::string elem : *vect) {
		int length = elem.length();
		int tmp_numero = atoi(elem.substr(5, length - 6).c_str());
		bool check = false;
		for (Node tmp_node : *vector_nodes) {
			if (tmp_numero == tmp_node.get_id()) {
				check = true;
				tmp_list_node_traffic.push_back(tmp_node);
				break;
			}
		}
		if (!check) {
			return false;
		}
	}
	Traffic tmp_traffic = Traffic(tmp_list_node_traffic);
	tmp_vector_traffics.push_back(tmp_traffic);
	*vector_traffics = tmp_vector_traffics;
	return true;
}

bool TableMaker::update_connections(std::vector<std::string> *vect,
					std::vector<Node> *vector_nodes,
					std::vector<Connection> *vector_connections){

	std::vector<Connection> tmp_vector_connections = *vector_connections;
	std::vector<Node> tmp_list_node_connection;
	for (const std::string elem : *vect) {
		int length = elem.length();
		int tmp_numero = atoi(elem.substr(5, length - 6).c_str());
		bool check = false;
		for (Node tmp_node : *vector_nodes) {
			if (tmp_numero == tmp_node.get_id()) {
				check = true;
				tmp_list_node_connection.push_back(tmp_node);
				break;
			}
		}
		if (!check) {
			break;
		}
	}
	Connection tmp_connection = Connection(tmp_list_node_connection.at(0),
								tmp_list_node_connection.at(1));
	tmp_vector_connections.push_back(tmp_connection);
	*vector_connections = tmp_vector_connections;
	return true;
}

bool TableMaker::check_valid_line(std::string *line,
								int *count,
								std::vector<Node> *tmp_vector_nodes,
								std::vector<Traffic> *tmp_vector_traffics,
								std::vector<Connection> *tmp_vector_connections,
								int error_line_number) {

	int tmp_count = *count;
	std::vector<std::string> vect = get_vector(*line);
	bool check = true;
	short type = check_vect(vect);
	if (tmp_count == 0 && type == 1) {
		tmp_count = 1;
	} else if (tmp_count == 1 && type == 3) {
		tmp_count = 2;
	} else if (tmp_count == 2 && type == 5) {
		tmp_count = 3;
	} else if (tmp_count == 1 && type == 2) {
		check = update_nodes(&vect, tmp_vector_nodes);
	} else if (type == 4 && tmp_count == 2 && vect.size() >= 2) {
		check = update_traffics(&vect, tmp_vector_nodes, tmp_vector_traffics);
	} else if (type == 4 && tmp_count == 3 && vect.size() == 2) {
		check = update_connections(&vect, tmp_vector_nodes, tmp_vector_connections);
	} else if (type != 7) {
		check = false;
	}
	*count = tmp_count;
	return check;
}

int TableMaker::build_tables() {
	std::vector<Node> tmp_vector_nodes;
	std::vector<Traffic> tmp_vector_traffics;
	std::vector<Connection> tmp_vector_connections;
	std::vector<std::string> tmp_vector_lines = get_lines_vector(this->content);
	bool check = true;
	int count = 0;
	int error_line_number = 0;
	for (std::string line : tmp_vector_lines) {
		error_line_number += 1;
		check = check_valid_line(&line, &count, &tmp_vector_nodes, &tmp_vector_traffics, &tmp_vector_connections, error_line_number);
		if (!check) {
			vectors_clear();
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

Node TableMaker::parse2(std::vector<std::string> vect) {
	int num_node = atoi(vect[0].substr(5, vect[0].length() - 6).c_str());
	int node_x = atoi(vect[1].c_str());
	int node_y = atoi(vect[2].c_str());
	Node node = Node(num_node, node_x, node_y);
	return node;
}

std::vector<Node> TableMaker::get_nodes() const {
	return this->vector_nodes;
}

std::vector<Traffic> TableMaker::get_traffics() const {
	return this->vector_traffics;
}

std::vector<Connection> TableMaker::get_connections() const {
	return this->vector_connections;
}

void TableMaker::nodes_display() const {
	std::string result_display = "[";
	int length = this->vector_nodes.size();
	for (int iterator = 0; iterator < length; iterator++) {
		Node tmp_node = this->vector_nodes.at(iterator);
		result_display.append("(\"Node" + std::to_string(tmp_node.get_id()) + "\", " + std::to_string(tmp_node.get_X()) + ", " + std::to_string(tmp_node.get_Y()) + ")");
		if (iterator != length - 1) {
			result_display.append(",\n");
		}
	}
	result_display.append("]");
	std::cout << result_display << std::endl;
}

void TableMaker::traffics_display() const {
	std::string result_display = "[";
	int length_traffics = this->vector_traffics.size();
	for (int iterator = 0; iterator < length_traffics; iterator++) {
		result_display.append("(");
		Traffic tmp_traffic = this->vector_traffics.at(iterator);
		std::vector<Node> tmp_nodes = tmp_traffic.get_traffic();
		int length_nodes = tmp_nodes.size();
		for (int iterator2 = 0; iterator2 < length_nodes; iterator2++){
			Node tmp_node = tmp_nodes.at(iterator2);
			result_display.append("\"Node" + std::to_string(tmp_node.get_id()) + "\"");
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
	std::cout << result_display << std::endl;
}

void TableMaker::connections_display() const {
	std::string result_display = "[";
		int length_connections = this->vector_connections.size();
		for (int iterator = 0; iterator < length_connections; iterator++) {
			Connection tmp_connections = this->vector_connections.at(iterator);
			Node node1 = tmp_connections.get_node_debut();
			Node node2 = tmp_connections.get_node_fin();
			result_display.append("(\"Node" + std::to_string(node1.get_id()) + "\"--\"Node" + std::to_string(node2.get_id()) + "\")");
			if (iterator != length_connections - 1) {
				result_display.append(",\n");
			}
		}
		result_display.append("]");
		std::cout << result_display << std::endl;
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
