#ifndef _Coordonnees_
#define _Coordonnees_

/**
 * @file coordonnees.h
 * Projet Démineur
 *  @author Lenouvel Louis et Gabriel Esteves
 * @version 23/11/2021
 * @brief Composant d'une coordonnée
 */


/**
 * @brief Type coordonnées
 * invariant : la position doit être valide
*/
struct coordonnees {
	unsigned int x;		//abscisse de la coordonnée 
	unsigned int y;		//ordonnée de la coordonnée
};

#endif
