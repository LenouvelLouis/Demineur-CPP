/**
 * @file tableau_case.cpp
 * Projet Démineur
 * @author Lenouvel Louis et Gabriel Esteves
 * @version 23/11/2021
 * @brief Composant d'un tableau de case de capacité extensible
 */

#include"tableau_case.h"
#include<iostream>
using namespace std;

/**
 * @brief Allocation dynamique de la mémoire du tableau de case
 * @param[out] t : le tableau de case
 * @param [in] i : la position où l'on veut écrire
 */
void allocation(tableau_case& t, unsigned int i) {
	if (t.capacite <= i) {
		int newTaille = (i + 1) * t.extension;		//on initialise une nouvelle taille 
		coordonnees* newT = new coordonnees[newTaille];		//on initialise un nouveau avec la nouvelle taille
		for (int j = 0; j < t.capacite; ++j) {
			newT[j] = t.tabC[j];		//on recopie chaque élément de l'ancien tableau dans le nouveau 
		}
		delete[] t.tabC;		//on supprime l'ancien tableau
		t.tabC = newT;		//on initialise le tableau à partir du nouveau
		t.capacite = newTaille;		//on initalise la taille du tableau avec la nouvelle taille
	}
}



/**
 * @brief vérifie que l'élément que l'on veut ajouter n'est pas déjà dans le tableau de case
 * @param[in] t : tableau qui contient les cases masqués
 * @param[in] cased : les coordonnées qui vont être utilisé pour la vérification
 * @param[return] bool : true ou false
 */
bool vérifier(tableau_case& t, coordonnees& cop) {
	for (int l = 0; l <= t.nbItems; l++) {
		if (cop.x == t.tabC[l].x && cop.y == t.tabC[l].y) {		//on cherche si l'élément est déjà dans le tableau
			return true;
		}
	}
	return false;
}


