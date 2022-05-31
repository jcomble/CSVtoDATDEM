#include "graphe.hpp"

int Graphe::getindex(std::vector<Node> arg_liste_nodes, Node node) {
	int length_liste = arg_liste_nodes.size();
	for (int iterator = 0; iterator < length_liste; iterator++) {
		Node elem = arg_liste_nodes.at(iterator);
		if (elem.get_id() == node.get_id()) {
			return iterator;
		}
	}
	return -1;
}

Graphe::Graphe(std::vector<Node> arg_liste_nodes,
    std::vector<Connection> arg_liste_connections) {
    this -> liste_nodes = arg_liste_nodes;
    this -> liste_connections = arg_liste_connections;
    this -> dim = arg_liste_nodes.size();
    bool mat[dim][dim];
    std::fill(&mat[0][0], &mat[dim][dim], false);
	for (Connection cox : arg_liste_connections) {
		Node debut = cox.get_node_debut();
		Node fin = cox.get_node_fin();
	    int i = getindex(arg_liste_nodes, debut);
		int j = getindex(arg_liste_nodes, fin);
    	mat[i][j] = true;
    	mat[j][i] = true;
	}
    std::vector<bool> vector_matrice;
    for (int i = 0; i<dim; i++) {
        for (int j = 0 ; j < dim ; j++) {
            vector_matrice.push_back(mat[i][j]);
        }
    }
    this -> mat_vector = vector_matrice;
}

Graphe::~Graphe(){
}

std::vector<Node> Graphe::get_list_nodes() {
    return this-> liste_nodes;
}

std::vector<std::vector<int>> Graphe::get_chemin() {
    return this->chemins_;
}

std::vector<Connection> Graphe::get_liste_connections() {
    return this-> liste_connections;
}

int Graphe::get_dim() {
    return this->dim;
}

std::vector<bool> Graphe::get_mat_vector() {
    return this-> mat_vector;
}

std::vector<int> Graphe::get_voisin(int node_numero) {
    int dim = this->get_dim();
    std::vector<bool> vector_mat = this->get_mat_vector();
    std::vector<int> voisin ;
    bool mat[dim][dim];
    std::fill(&mat[0][0],&mat[dim][dim],false);
    for (int i = 0; i < dim; i++) {
        for(int j = 0 ; j < dim ; j++) {
            mat[i][j] = vector_mat.at(i * dim + j);
        }
    }
    for (int i = 0; i < dim; i++) {
        if (mat[node_numero][i] == true) {
            voisin.push_back(i);
        }
    }
    return voisin;
}

void Graphe::chemins(int id_debut, int id_fin) {
	this->chemins_.clear();
    std::vector<int> pile;
    pile.push_back(id_debut);
    chemins(id_debut, id_fin, pile);
}


void Graphe::chemins(int id_debut, int id_fin, std::vector<int> pile) {
    if (id_debut == id_fin) {
        this->chemins_.push_back(pile);
    } else {
        std::vector<int> voisin = this->get_voisin(id_debut);
        for (int id_voisin : voisin) {
            bool check = false;
            for (int i = 0 ; i < pile.size();i++) {
                if (pile.at(i) == id_voisin) {
                    check = true;
                }
            }
            if (!check) {
                pile.push_back(id_voisin);
                chemins(id_voisin, id_fin, pile);
                pile.pop_back();
            }
        }
    }
}

std::vector<int> Graphe::get_chemin_C() {
    std::vector<std::vector<int>> all_path = this->get_chemin();
	int min_size = INT_MAX;
	std::vector<int> chemin_c;
	for (std::vector<int> vect : all_path) {
        if (vect.size() <= min_size) {
			chemin_c = vect;
			min_size = vect.size();
		}
	}
    return chemin_c;
}

std::vector<Node> Graphe::get_chemin_C_type_node(Node debut, Node fin) {
	chemins(getindex(this->liste_nodes, debut), getindex(this->liste_nodes, fin));
    std::vector<int> chemin_int = this->get_chemin_C();
    std::vector<Node> liste_nodes = this->get_list_nodes();
    std::vector<Node> chemin_nodes;
    for (int i : chemin_int) {
    	chemin_nodes.push_back(liste_nodes.at(i));
    }
    return chemin_nodes;
}
