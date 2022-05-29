#ifndef GRAPHE_H_
#define GRAPHE_H_
#include <fstream>
#include <vector>
#include <iostream>
#include "connection.h"
#include "node.h"
#include <limits.h>
    
class Graphe 
{
private:
    std::vector<Node> liste_nodes;
    std::vector<Connection> liste_connections;
    int dim;
    std::vector<std::vector<int>> chemins_;
    std::vector<bool> mat_vector;

public:
	Graphe(std::vector<Node>,std::vector<Connection>);
	virtual ~Graphe();
    std::vector<Node> get_list_nodes();
    std::vector<Connection> get_liste_connections();
    int get_dim();
    std::vector<bool> get_mat_vector();
    std::vector<std::vector<int>> get_chemin();
    std::vector<int> get_voisin(int id);
    void chemins(int id_debut, int id_fin);
    void chemins(int id_debut, int id_fin, std::vector<int> pile);
    std::vector<int> get_chemin_C();
    std::vector<Node> get_chemin_C_type_node();
};

#endif
