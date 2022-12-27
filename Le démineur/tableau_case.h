#ifndef _Tableau_
#define _Tableau_

/**
 * @file tableau_case.h
 * Projet D�mineur
 *  @author Lenouvel Louis et Gabriel Esteves
 * @version 23/11/2021
 * @brief Composant d'un tableau de case
 */

#include "coordonnees.h"

/** @brief tableau de case allou�s en m�moire dynamique
 *  de capacit� extensible suivant un pas d'extension
 */
struct tableau_case {
	unsigned int extension;	//extension du tableau
	unsigned int capacite;	//capacit� du tableau
	coordonnees* tabC;	//tableau de case
	unsigned int nbItems;	//nombre d'items du tableau
};

/**
 * @brief Allocation dynamique de la m�moire du tableau de case
 * @param[out] t : le tableau de case
 * @param [in] i : la position o� l'on veut �crire
 */
void allocation(tableau_case& t, unsigned int i);

/**
 * @brief v�rifie que l'�l�ment que l'on veut ajouter n'est pas d�j� dans le tableau de case
 * @param[in] t : tableau qui contient les cases masqu�s
 * @param[in] cased : les coordonn�es qui vont �tre utilis� pour la v�rification
 * @param[return] bool : true ou false
 */
bool v�rifier(tableau_case& t, coordonnees& cop);


#endif