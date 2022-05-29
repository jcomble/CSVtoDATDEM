/*
 * chemin.h
 *
 *  Created on: 28 mai 2022
 *      Author: jcomble
 */
#include "listnodes.h"
#ifndef CHEMIN_H_
#define CHEMIN_H_

class Chemin {
private:
	Node noeud_debut;
	Node noeud_fin;
	std::vector<ListNodes> deplacements;
public:
	std::vector<ListNodes> get_deplacement();
	void add_deplacement(ListNodes deplacement);
	ListNodes at(int index);
	int size();
	Node getfin();
	Node getdebut();
	Chemin();
	virtual ~Chemin();
};

#endif /* CHEMIN_H_ */
