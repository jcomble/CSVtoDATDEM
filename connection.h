/*
 * Connection.h
 *
 *  Created on: 9 mai 2022
 *      Author: jcomble
 */

#ifndef CONNECTION_H_
#define CONNECTION_H_

class Connection {
	private:
		int node_debut, node_fin;
	public:
		Connection(int id_debut, int id_fin);
		int get_node_debut();
		int get_node_fin();
};

#endif /* CONNECTION_H_ */
