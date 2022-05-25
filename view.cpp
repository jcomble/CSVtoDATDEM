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

    int size;
    size = vector_nodes.size();

    ofstream out_dat_file;
    ofstream out_dem_file;

    out_dat_file.open("output_nodes.dat");
    out_dem_file.open("output_nodes.dem");

    if (out_dat_file.is_open() && out_dem_file.is_open())
    {
        out_dem_file <<"set title 'Node'"<< endl;
        for (int i=0;i<size;i++)
        {
            out_dat_file << vector_nodes.at(i).get_X() << "  " << vector_nodes.at(i).get_Y() << endl;
            out_dem_file << "set label \"Node " << i << "\"  at " << vector_nodes.at(i).get_X()-0.5 << "," << vector_nodes.at(i).get_Y()-0.5<< endl;
 
        }

        out_dem_file << "plot \"output_nodes.dat\""<< endl;
        out_dem_file << "pause -1 \" (-> return)\"" << endl;

    }
    out_dat_file.close();

    }

    view::~view(){};



