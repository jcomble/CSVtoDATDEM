/*
 * Trafficschecker.h
 *
 *  Created on: 27 mai 2022
 *      Author: jcomble
 */
#include "tablemaker.h"
#include "listnodes.h"

#ifndef TRAFFICSCHECKER_H_
#define TRAFFICSCHECKER_H_

class Trafficschecker {
private:
	std::vector<ListNodes> chemins;
public:
	Trafficschecker();
	Trafficschecker(TableMaker table);
	std::vector<ListNodes> getchemins();
	virtual ~Trafficschecker();
};

#endif /* TRAFFICSCHECKER_H_ */
