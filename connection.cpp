/*
 * Connection.cpp
 *
 *  Created on: 9 mai 2022
 *      Author: jcomble
 */

#include "connection.h"

Connection::Connection(const Node node_1, const Node node_2) {
	this->node_debut = node_1;
	this->node_fin = node_2;
}

Node Connection::get_node_debut() const {
	return this->node_debut;
}

Node Connection::get_node_fin() const {
	return this->node_fin;
}
