#include <vector>
#include "node.h"

#ifndef TRAFFIC_H_
#define TRAFFIC_H_

using namespace std;
class Traffic
{
    private:
        vector<Node> list_traffic;
    public:
        Traffic(vector<Node> vector_nodes);
        vector<Node> get_traffic();
};

#endif
