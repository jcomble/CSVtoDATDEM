#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <fstream>
#include "node.h"
#include "file.h"
#include "tablemaker.h"
#include "view.hpp"

int main(int argc, char *argv[]) {
	if (argc == 1) {
		std::cout << "No file in args, (main arg1.csv)";
		return 1;
	}
	const char *filename = argv[1];
	File file = File(filename);
	if (!file.check_valid()) {
		std::cout << filename << " is not opened" << std::endl;
		return 2;
	}
	file.display();
	TableMaker tables = TableMaker(file);
	tables.display();
	view view_nodes = view(tables);
	view_nodes.build();
	return 0;
}
