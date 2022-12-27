#pragma once
#ifndef _Coordonn�es_
#define _Coordonn�es_
/**
 * @file coordonn�es.h
 * Projet D�mineur
 *  @author Lenouvel Louis et Gabriel Esteves
 * @version 23/11/2021
 * @brief Composant de coordonn�es sur un tableau
 */

#include"conteneur.h"

/**
 * @brief Type coordonn�es
 * invariant : la position doit �tre valide
*/
struct coordonn�es {
	unsigned int x;	//coordonn�es x
	unsigned int y;	//coordonn�es y
};

/**
 * @brief Ajoute les mines au conteneur de case
 * @param[out] c : le conteneur de case
 * @param [in] positon : position � convertir en abscisse et ordonn�e en fonction de la hauteur et la largeur du conteneur c
 * @param [out] coo : coordonn�es avec l'abscisse et l'ordonn�e
 */
void cPosition(conteneur& c, unsigned int position, coordonn�es& coo);
#endif