#include "traffic.h"
#include "node.h"
#include <istream>
#include <vector>
using namespace std;


Traffic::Traffic(vector<Node> vector_nodes) {
	this->list_traffic = vector_nodes;
}

vector<int> Traffic::get_traffic() {
	return this->list_traffic;
}
