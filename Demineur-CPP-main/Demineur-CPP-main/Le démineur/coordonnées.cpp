


#include"coordonn�es.h"
using namespace std;

/**
 * @brief Ajoute les mines au conteneur de case
 * @param[out] c : le conteneur de case
 * @param [in] positon : position � convertir en abscisse et ordonn�e en fonction de la hauteur et la largeur du conteneur c
 * @param [out] coo : coordonn�es avec l'abscisse et l'ordonn�e
 */
void cPosition(conteneur& c, unsigned int position, coordonn�es& coo) {
	coo.x = (position - (position % c.largeur)) / c.largeur; // abscisse de la position
	coo.y = position % c.largeur; // ordonn�e de la position
}