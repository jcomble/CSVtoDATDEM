/*
 * listnodes.h
 *
 *  Created on: 27 mai 2022
 *      Author: jcomble
 */

#include <vector>
#include "node.h"
#include <stdexcept>
#include <iostream>

#ifndef LISTNODES_H_
#define LISTNODES_H_

class ListNodes {
	private:
		std::vector<Node> list;
	public:
		Node at(int index);
		ListNodes();
		int size();
		virtual ~ListNodes();
		void addNode(Node node);
		std::vector<Node> getNodes();
};

#endif /* LISTNODES_H_ */
