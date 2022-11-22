


#include"coordonnées.h"
using namespace std;

/**
 * @brief Ajoute les mines au conteneur de case
 * @param[out] c : le conteneur de case
 * @param [in] positon : position à convertir en abscisse et ordonnée en fonction de la hauteur et la largeur du conteneur c
 * @param [out] coo : coordonnées avec l'abscisse et l'ordonnée
 */
void cPosition(conteneur& c, unsigned int position, coordonnées& coo) {
	coo.x = (position - (position % c.largeur)) / c.largeur; // abscisse de la position
	coo.y = position % c.largeur; // ordonnée de la position
}