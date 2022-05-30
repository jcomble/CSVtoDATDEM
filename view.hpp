#ifndef VIEW_H_
#define VIEW_H_
#include <vector>
#include <iostream>
#include "tablemaker.h"
#include <limits.h>
#include "graphe.hpp"

class view {
private:
	TableMaker tabl;
public:
	view(TableMaker tabl);
	virtual ~view();
    void build();
    TableMaker get_TableMaker();
    void write_ranges(std::vector<Node> vector_nodes,
    		std::ofstream &out_dat_file,
			std::ofstream &out_dem_file);
    void writegraph(std::ofstream& out_dem_file,
    				std::ofstream& out_dat_file,
					std::vector<Node> vector_nodes,
					std::vector<Connection> vector_connections);
    void writetraffics(std::ofstream& out_dem_file,
    				Node nodeA,
					Node nodeB,
					std::string filename,
					std::vector<Node> result_chemin,
					std::vector<Node> tmp_traffic,
					int length_tmp_traffic);
    void graphdisplay(std::ofstream& out_dem_file);
    void trafficdisplay(std::ofstream& out_dem_file);
};

#endif /* FILE_H_ */
