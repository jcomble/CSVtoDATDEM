/*
 * Connection.cpp
 *
 *  Created on: 9 mai 2022
 *      Author: jcomble
 */

#include "Connection.h"

Connection::Connection(int num_1, int num_2) {
	node_debut = num_1;
	node_fin = num_2;
}

int Connection::get_node_debut() {
	return this->node_debut;
}

int Connection::get_node_fin() {
	return this->node_debut;
}
