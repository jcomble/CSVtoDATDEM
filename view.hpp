#ifndef VIEW_H_
#define VIEW_H_
#include <fstream>
#include <vector>
#include <iostream>
#include "tablemaker.h"
using namespace std;

    
class view {
private:
	TableMaker tabl;


public:
	view(TableMaker tabl);
	virtual ~view();
    void build();
    TableMaker get_TableMaker();
	
};

#endif /* FILE_H_ */
