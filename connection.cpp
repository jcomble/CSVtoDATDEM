/*
 * Connection.cpp
 *
 *  Created on: 9 mai 2022
 *      Author: jcomble
 */

#include "connection.h"

/**
 * Constructeur d'une connection entre deux noeuds.
 */
Connection::Connection(const Node node_1, const Node node_2) {
	this->node_debut = node_1;
	this->node_fin = node_2;
}

/**
 * Getter du premier noeud.
 */
const Node Connection::get_node_debut() const {
	return this->node_debut;
}

/**
 * Getter du second noeud.
 */
const Node Connection::get_node_fin() const {
	return this->node_fin;
}

/**
 * Constructeur par défaut d'arguments.
 */
Connection::Connection() {
	this->node_debut = Node();
	this->node_fin = Node();
}
