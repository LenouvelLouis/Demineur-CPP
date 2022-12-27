#pragma once
#ifndef _Coordonnées_
#define _Coordonnées_
/**
 * @file coordonnées.h
 * Projet Démineur
 *  @author Lenouvel Louis et Gabriel Esteves
 * @version 23/11/2021
 * @brief Composant de coordonnées sur un tableau
 */

#include"conteneur.h"

/**
 * @brief Type coordonnées
 * invariant : la position doit être valide
*/
struct coordonnées {
	unsigned int x;	//coordonnées x
	unsigned int y;	//coordonnées y
};

/**
 * @brief Ajoute les mines au conteneur de case
 * @param[out] c : le conteneur de case
 * @param [in] positon : position à convertir en abscisse et ordonnée en fonction de la hauteur et la largeur du conteneur c
 * @param [out] coo : coordonnées avec l'abscisse et l'ordonnée
 */
void cPosition(conteneur& c, unsigned int position, coordonnées& coo);
#endif