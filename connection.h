/*
 * Connection.h
 *
 *  Created on: 9 mai 2022
 *      Author: jcomble
 */
#include "node.h"
#ifndef CONNECTION_H_
#define CONNECTION_H_

/**
 * Classe représentant une connection entre deux noeuds.
 */
class Connection {
	private:
		Node node_debut, node_fin;
	public:
		Connection();
		Connection(const Node id_debut, const Node id_fin);
		const Node get_node_debut() const;
		const Node get_node_fin() const;
};

#endif /* CONNECTION_H_ */
