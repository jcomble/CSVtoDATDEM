#include "view.hpp"
#include <limits.h>

view::view(TableMaker table) {
    this -> tabl = table;
}

TableMaker view::get_TableMaker() {
    return this-> tabl;
}

void view::write_ranges(std::vector<Node> vector_nodes, std::ofstream &out_dat_file, std::ofstream &out_dem_file) {
	int minX = INT_MAX, minY = INT_MAX, maxX = INT_MIN, maxY = INT_MIN;
	for (Node tmp_node : vector_nodes) {
		int tmp_X = tmp_node.get_X();
		int tmp_Y = tmp_node.get_Y();
		if (minX > tmp_X) {
			minX = tmp_X;
		}
		if (minY > tmp_Y) {
			minY = tmp_Y;
		}
		if (maxX < tmp_X) {
			maxX = tmp_X;
		}
		if (maxY < tmp_Y) {
			maxY = tmp_Y;
		}
	}
	int minrangeX, minrangeY, maxrangeX, maxrangeY;
	if (15 * (maxX - minX) / 100 < 3 ) {
		minrangeX = minX - 3, maxrangeX = maxX + 3;
	} else {
		minrangeX = minX - 15 * (maxX - minX) / 100, maxrangeX = maxX + 15 * (maxX - minX) / 100;
	}
	if (15 * (maxY - minY) / 100 < 3) {
		minrangeY = minY - 3;
		maxrangeY = maxY + 3;
	} else {
		minrangeY = minY - 15 * (maxY - minY) / 100;
		maxrangeY = maxY + 15 * (maxY - minY) / 100;
	}
	out_dem_file << "set xrange [" << minrangeX << ":" << maxrangeX <<"]" << std::endl;
	out_dem_file << "set yrange [" << minrangeY << ":" << maxrangeY <<"]" << std::endl;
}

void view::build(){
	std::vector<Node> vector_nodes = get_TableMaker().get_nodes();
	std::vector<Connection> vector_connections = get_TableMaker().get_connections();
    std::ofstream out_dat_file;
    std::ofstream out_dem_file;
    out_dat_file.open("output_nodes.dat");
    out_dem_file.open("output_nodes.dem");
    if (out_dat_file.is_open() && out_dem_file.is_open()) {
        out_dem_file <<"set title 'Graph'" << std::endl;
        for (Node tmp_node : vector_nodes) {
        	out_dem_file << "set label \"Node" << tmp_node.get_id() << "\"  at " << tmp_node.get_X() << "," << tmp_node.get_Y() << std::endl;
        }

        write_ranges(vector_nodes, out_dat_file, out_dem_file);
        out_dem_file << "plot \"output_nodes.dat\" every :::0::" << vector_connections.size() - 1<< " with lp, \"\" every :::0::0 with points;" << std::endl;
        out_dem_file << "pause -1 \" (-> return)\"" << std::endl;
        for (Connection tmp_connection : vector_connections) {
        	Node debut = tmp_connection.get_node_debut();
        	Node fin = tmp_connection.get_node_fin();
        	out_dat_file << debut.get_X() << "  " << debut.get_Y() << std::endl;
        	out_dat_file << fin.get_X() << "  " << fin.get_Y() << std::endl << std::endl;
        }
    }
    out_dat_file.close();
}

view::~view(){
};
