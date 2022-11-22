#ifndef _Tableau_
#define _Tableau_

/**
 * @file tableau_case.h
 * Projet Démineur
 *  @author Lenouvel Louis et Gabriel Esteves
 * @version 23/11/2021
 * @brief Composant d'un tableau de case
 */

#include "coordonnees.h"

/** @brief tableau de case alloués en mémoire dynamique
 *  de capacité extensible suivant un pas d'extension
 */
struct tableau_case {
	unsigned int extension;	//extension du tableau
	unsigned int capacite;	//capacité du tableau
	coordonnees* tabC;	//tableau de case
	unsigned int nbItems;	//nombre d'items du tableau
};

/**
 * @brief Allocation dynamique de la mémoire du tableau de case
 * @param[out] t : le tableau de case
 * @param [in] i : la position où l'on veut écrire
 */
void allocation(tableau_case& t, unsigned int i);

/**
 * @brief vérifie que l'élément que l'on veut ajouter n'est pas déjà dans le tableau de case
 * @param[in] t : tableau qui contient les cases masqués
 * @param[in] cased : les coordonnées qui vont être utilisé pour la vérification
 * @param[return] bool : true ou false
 */
bool vérifier(tableau_case& t, coordonnees& cop);


#endif