/*
 * Node.cpp
 *
 *  Created on: 9 mai 2022
 *      Author: jcomble
 */

#include "node.h"

Node::Node(int id, int x, int y) {
    this->node_id = id;
    this->node_x = x;
    this->node_y = y;
}

Node::Node() {
    this->node_id = 0;
    this->node_x = 0;
    this->node_y = 0;
}

int Node::get_X() {
    return this->node_x;
}

int Node::get_Y() {
    return this->node_y;
}

int Node::get_id() {
    return this->node_id;
}
