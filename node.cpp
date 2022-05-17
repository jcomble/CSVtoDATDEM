/*
 * Node.cpp
 *
 *  Created on: 9 mai 2022
 *      Author: jcomble
 */

#include "node.h"

Node::Node(int id, int x, int y) {
    node_id = id;
    node_x = x;
    node_y = y;
}

Node::Node() {
    node_id = 0;
    node_x = 0;
    node_y = 0;
}

int Node::get_X() {
    return node_x;
}

int Node::get_Y() {
    return node_y;
}

int Node::get_id() {
    return node_id;
}
