/*
 * Connection.h
 *
 *  Created on: 9 mai 2022
 *      Author: jcomble
 */
#include "node.h"
#ifndef CONNECTION_H_
#define CONNECTION_H_

class Connection {
	private:
		Node node_debut, node_fin;
	public:
		Connection(Node id_debut, Node id_fin);
		Node get_node_debut();
		Node get_node_fin();
};

#endif /* CONNECTION_H_ */
