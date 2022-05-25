/*
 * Node.h
 *
 *  Created on: 9 mai 2022
 *      Author: jcomble
 */
#ifndef NODE_H_
#define NODE_H_
class Node {
	private:
        int node_id;
        int node_x;
        int node_y;
    public:
        Node(int id, int x, int y);
        Node();
        int get_X() const;
        int get_Y() const;
        int get_id() const;
};
#endif /* NODE_H_ */
