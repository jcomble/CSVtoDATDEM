#ifndef VIEW_H_
#define VIEW_H_
#include <fstream>
#include <vector>
#include <iostream>
#include "tablemaker.h"

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
    void graphdisplay(std::ofstream& out_dem_file);
    void trafficdisplay(std::ofstream& out_dem_file);
};

#endif /* FILE_H_ */
