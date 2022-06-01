/*
 * Node.cpp
 *
 *  Created on: 9 mai 2022
 *      Author: jcomble
 */

#include "node.h"

/**
 * Constructeur d'un noeud représenté par son numéro et ses coordonnées.
 */
Node::Node(int id, int x, int y) {
    this->node_id = id;
    this->node_x = x;
    this->node_y = y;
}

/**
 * Constructeur par défaut d'argument.
 */
Node::Node() {
    this->node_id = 0;
    this->node_x = 0;
    this->node_y = 0;
}

/**
 * Getter de l'abscisse du noeud.
 */
int Node::get_X() const {
    return this->node_x;
}

/**
 * Getter de l'ordonnée du noeud.
 */
int Node::get_Y() const {
    return this->node_y;
}

/**
 * Getter du numéro du noeud.
 */
int Node::get_id() const {
    return this->node_id;
}
