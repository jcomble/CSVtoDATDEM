#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <fstream>
#include "node.h"
#include "file.h"
#include "tablemaker.h"

using namespace std;

int main(int argc,char * argv[]){
	// opening input files
	if (argc > 1) {
		ifstream in_file;
		const char *filename = argv[1];
		File file = File(filename);
		if (!file.check_valid()) {
			cout << filename <<" is not opened"<< endl;
			return 2;
		}
		file.display();
		TableMaker tables = TableMaker(file.get_content());
		tables.nodes_display();
		tables.traffics_display();
		tables.connections_display();
		vector<Node> vector_nodes = tables.get_nodes();
		vector<Connection> vector_connections = tables.get_connections();
		vector<Traffic> vector_traffics = tables.get_traffics();
		return 0;
	}
	cout << "No file in args, (main arg1.csv)";
	return 1;
}
