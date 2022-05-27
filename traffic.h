#include <vector>
#include "node.h"

#ifndef TRAFFIC_H_
#define TRAFFIC_H_

class Traffic
{
    private:
        std::vector<Node> list_traffic;
    public:
        Traffic(std::vector<Node> vector_nodes);
        std::vector<Node> get_traffic();
};

#endif
