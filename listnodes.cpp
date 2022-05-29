/*
 * listnodes.cpp
 *
 *  Created on: 27 mai 2022
 *      Author: jcomble
 */

#include "listnodes.h"

ListNodes::ListNodes() {
}

ListNodes::~ListNodes() {
}

void ListNodes::addNode(Node node) {
	this->list.push_back(node);
}

std::vector<Node> ListNodes::getNodes() {
	return this->list;
}

Node ListNodes::at(int index) {
	if (index >= this->list.size() || index < 0) {
		throw std::invalid_argument("Index hors intervalle.");
	}
	return this->list.at(index);
}

int ListNodes::size() {
	return this->list.size();
}
