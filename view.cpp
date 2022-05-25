#include "view.hpp"
#include <fstream>
#include <vector>
#include <iostream>
#include "tablemaker.h"
#include <string>


view::view(TableMaker table){

    this -> tabl = table;

}

TableMaker view::get_TableMaker(){
    return this-> tabl;
}
void view::build(){

    vector<Node> vector_nodes;
    vector_nodes = get_TableMaker().get_nodes();

    ofstream out_dat_file;
    ofstream out_dem_file;

    out_dat_file.open("output_nodes.dat");
    out_dem_file.open("output_nodes.dem");

    if (out_dat_file.is_open() && out_dem_file.is_open()) {
        out_dem_file <<"set title 'Node'"<< endl;
        for (Node tmp_node : vector_nodes)
        {
        	out_dat_file << tmp_node.get_X() << "  " << tmp_node.get_Y() << endl;
        	out_dem_file << "set label \"Node" << tmp_node.get_id << "\"  at " << tmp_node.get_X()-0.5 << "," << tmp_node.get_Y()-0.5<< endl;
        }
        out_dem_file << "plot \"output_nodes.dat\""<< endl;
        out_dem_file << "pause -1 \" (-> return)\"" << endl;
    }
    out_dat_file.close();
}
view::~view(){};
