#include "traffic.h"

Traffic::Traffic(std::vector<Node> vector_nodes) {
	this->list_traffic = vector_nodes;
}

std::vector<Node> Traffic::get_traffic() {
	return this->list_traffic;
}
