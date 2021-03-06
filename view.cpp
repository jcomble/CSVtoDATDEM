#include "view.hpp"

/**
 * Constructeur prenant un TableMaker en argument.
 */
view::view(TableMaker table) {
    this -> tabl = table;
}

/**
 * Getter du TableMaker.
 */
TableMaker view::get_TableMaker() {
    return this-> tabl;
}

/**
 * Ajoute au .dem les ranges forçant au graphe de s'espacer des bordures tel que:
 * 70% de la longueur et de la largeur de l'affichage soit du graphe.
 * S'il y a alignement parfait en longueur ou largeur, 3 unités espaceront le graph des bordures
 * dans ce(s) cas.
 */
void view::write_ranges(std::vector<Node> vector_nodes, std::ofstream &out_dat_file, std::ofstream &out_dem_file) {
	float minX = INT_MAX, minY = INT_MAX, maxX = INT_MIN, maxY = INT_MIN;
	for (Node tmp_node : vector_nodes) {
		int tmp_X = tmp_node.get_X();
		int tmp_Y = tmp_node.get_Y();
		minX = minX > tmp_X ? tmp_X : minX;
		minY = minY > tmp_Y ? tmp_Y : minY;
		maxX = maxX < tmp_X ? tmp_X : maxX;
		maxY = maxY < tmp_Y ? tmp_Y : maxY;
	}
	float minrangeX = maxX - minX == 0. ? minX - 3 : minX - 15 * (maxX - minX) / 100.;
	float maxrangeX = maxX - minX == 0. ? maxX + 3 : maxX + 15 * (maxX - minX) / 100.;
	float minrangeY = maxY - minY == 0. ? minY - 3 : minY - 15 * (maxY - minY) / 100.;
	float maxrangeY = maxY - minY == 0. ? maxY + 3 : maxY + 15 * (maxY - minY) / 100.;
	out_dem_file << "set xrange [" << minrangeX << ":" << maxrangeX <<"]" << std::endl;
	out_dem_file << "set yrange [" << minrangeY << ":" << maxrangeY <<"]" << std::endl;
}

/**
 * Écrit dans le .dem les instructions pour le titre du graph, les étiquettes,
 * Le placement des points et des arêtes, de la légende et de la pause après affichage.
 * Écrit dans le .dat les coordonnées des noeuds puis les coordonnées nécessaire
 * à la création des segments.
 */
void view::writegraph(std::ofstream& out_dem_file, std::ofstream& out_dat_file, std::vector<Node> vector_nodes, std::vector<Connection> vector_connections) {
	out_dem_file << "set title 'Graph'" << std::endl;
	for (Node tmp_node : vector_nodes) {
		out_dat_file << tmp_node.get_X() << "  " << tmp_node.get_Y() << std::endl;
		out_dem_file << "set label \"Node" << tmp_node.get_id() << "\"  at " << tmp_node.get_X() << "," << tmp_node.get_Y() << std::endl;
	}
	out_dat_file << std::endl;
	write_ranges(vector_nodes, out_dat_file, out_dem_file);
	out_dem_file << "plot \"graph.dat\" every :::1::" << vector_connections.size() << " with lp title \"Aretes\", \"\" every :::0::0 with points title \"Noeuds\";" << std::endl;
	out_dem_file << "pause -1 \" Graph: (Appuyez sur Enter pour continuer) \"" << std::endl;
	for (Connection tmp_connection : vector_connections) {
		Node debut = tmp_connection.get_node_debut();
		Node fin = tmp_connection.get_node_fin();
		out_dat_file << debut.get_X() << "  " << debut.get_Y() << std::endl;
		out_dat_file << fin.get_X() << "  " << fin.get_Y() << std::endl << std::endl;
	}
}

/**
 * Méthode pour écrire le .dem si le .dat a bien pu être ouvert.
 */
void view::graphdisplay(std::ofstream& out_dem_file) {
	std::vector<Node> vector_nodes = this->tabl.get_nodes();
	std::vector<Connection> vector_connections = this->tabl.get_connections();
	std::ofstream out_dat_file;
	out_dat_file.open("graph.dat");
	if (!out_dat_file.is_open()) {
		std::cout << "Erreur ecriture fichier dat" << std::endl;
		return;
	}
	writegraph(out_dem_file, out_dat_file, vector_nodes, vector_connections);
	out_dat_file.close();
}

/**
 * Écrit dans le .dem les instructions pour le titre de l'étape dans le traffic,
 * les étiquettes. Le placement des points et des arêtes, de la légende et de la pause après affichage.
 * Écrit dans le .dat les coordonnées des noeuds puis les coordonnées nécessaire
 * à la création des segments.
 */
void view::writetraffics(std::ofstream& out_dem_file,
		Node nodeA,
		Node nodeB,
		std::string filename,
		std::vector<Node> result_chemin,
		std::vector<Node> tmp_traffic,
		int length_tmp_traffic) {

	std::ofstream out_dat_file;
	out_dat_file.open(filename);
	if (!out_dat_file.is_open()) {
		std::cout << "Erreur ecriture fichier dat" << std::endl;
		return;
	}
	int length_deplacement = result_chemin.size();
	std::vector<Node> vector_nodes = this->tabl.get_nodes();
	for (Node tmp_node : vector_nodes) {
			out_dat_file << tmp_node.get_X() << "  " << tmp_node.get_Y() << std::endl;
	}
	out_dat_file << std::endl;
	for (int iterator_deplacement = 0; iterator_deplacement < length_deplacement - 1; iterator_deplacement++) {
		Node nodeC = result_chemin.at(iterator_deplacement);
		Node nodeD = result_chemin.at(iterator_deplacement + 1);
		out_dat_file << nodeC.get_X() << "  " << nodeC.get_Y() << std::endl;
		out_dat_file << nodeD.get_X() << "  " << nodeD.get_Y() << std::endl << std::endl;
	}
	out_dem_file << "set title ' etape : Node"
			<< std::to_string(nodeA.get_id())
			<< " -> Node"
			<< std::to_string(nodeB.get_id())
			<< "' "
			<< std::endl;
	out_dem_file << "plot \""
			<< filename
			<< "\" every :::1::"
			<< length_deplacement - 1
			<< " with lp title \"Aretes\", \"\" every :::0::0 with points title \"Noeuds\";"
			<< std::endl;
	out_dem_file << "pause -1 \" Objectif : Node" + std::to_string(tmp_traffic.at(0).get_id())
					+ " -> Node" + std::to_string(tmp_traffic.at(length_tmp_traffic - 1).get_id())
					+ ", etape : Node" + std::to_string(nodeA.get_id())
					+ " -> Node" + std::to_string(nodeB.get_id())
					+ " (Appuyez sur Enter pour continuer) \"" << std::endl;
	out_dat_file.close();
}

/**
 * Méthode pour écrire le .dem si le .dat a bien pu être ouvert et pour chaque traffic
 * et étape dans le traffic, pour générer un .dat correspondant au chemin à parcourir
 * durant l'étape.
 */
void view::trafficdisplay(std::ofstream& out_dem_file) {
	std::vector<Node> vector_nodes = this->tabl.get_nodes();
	std::vector<Connection> vector_connections = this->tabl.get_connections();
	std::vector<std::vector<Node>> vector_traffics = this->tabl.get_traffics();
	Graphe graph = Graphe(vector_nodes, vector_connections);
	int length_vector_traffics = vector_traffics.size();
	for (int iterator_traffics = 0; iterator_traffics < length_vector_traffics; iterator_traffics++) {
		std::vector<Node> tmp_traffic = vector_traffics.at(iterator_traffics);
		int length_tmp_traffic = tmp_traffic.size();
		for (int iterator_tmp_traffic = 0 ; iterator_tmp_traffic < length_tmp_traffic - 1; iterator_tmp_traffic++) {
			Node nodeA = tmp_traffic.at(iterator_tmp_traffic);
			Node nodeB = tmp_traffic.at(iterator_tmp_traffic + 1);
			std::vector<Node> result_chemin = graph.get_chemin_C_type_node(nodeA, nodeB);
			const std::string filename = "traffic_N" + std::to_string(iterator_traffics) + "_D" + std::to_string(iterator_tmp_traffic) + ".dat";
			writetraffics(out_dem_file, nodeA, nodeB, filename, result_chemin, tmp_traffic, length_tmp_traffic);
		}
	}
}

/**
 * Méthode pour construire les .dem et .dat
 */
void view::build() {
	std::ofstream out_dem_file;
	out_dem_file.open("output_graph_and_traffics.dem");
	if (!out_dem_file.is_open()) {
		std::cout << "Erreur ouverture fichier dem" << std::endl;
		return;
	}
    graphdisplay(out_dem_file);
    trafficdisplay(out_dem_file);
    out_dem_file.close();
}

view::~view(){
};
