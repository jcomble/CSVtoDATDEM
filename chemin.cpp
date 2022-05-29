/*
 * chemin.cpp
 *
 *  Created on: 28 mai 2022
 *      Author: jcomble
 */

#include "chemin.h"

Chemin::Chemin() {

}

Chemin::~Chemin() {
	// TODO Auto-generated destructor stub
}

void Chemin::add_deplacement(ListNodes deplacement) {
	this->deplacements.push_back(deplacement);
}

std::vector<ListNodes> Chemin::get_deplacement() {
	return this->deplacements;
}

ListNodes Chemin::at(int index) {
	if (index >= this->deplacements.size() || index < 0) {
		throw std::invalid_argument("Index hors intervalle.");
	}
	return this->deplacements.at(index);
}

int Chemin::size() {
	return this->deplacements.size();
}

Node Chemin::getdebut() {
	return this->noeud_debut;
}

Node Chemin::getfin() {
	return this->noeud_fin;
}
