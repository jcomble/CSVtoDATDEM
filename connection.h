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
		const Node node_debut, node_fin;
	public:
		Connection(const Node id_debut, const Node id_fin);
		Node get_node_debut() const;
		Node get_node_fin() const;
};

#endif /* CONNECTION_H_ */
