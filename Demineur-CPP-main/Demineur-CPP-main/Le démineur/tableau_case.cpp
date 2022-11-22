/**
 * @file tableau_case.cpp
 * Projet D�mineur
 * @author Lenouvel Louis et Gabriel Esteves
 * @version 23/11/2021
 * @brief Composant d'un tableau de case de capacit� extensible
 */

#include"tableau_case.h"
#include<iostream>
using namespace std;

/**
 * @brief Allocation dynamique de la m�moire du tableau de case
 * @param[out] t : le tableau de case
 * @param [in] i : la position o� l'on veut �crire
 */
void allocation(tableau_case& t, unsigned int i) {
	if (t.capacite <= i) {
		int newTaille = (i + 1) * t.extension;		//on initialise une nouvelle taille 
		coordonnees* newT = new coordonnees[newTaille];		//on initialise un nouveau avec la nouvelle taille
		for (int j = 0; j < t.capacite; ++j) {
			newT[j] = t.tabC[j];		//on recopie chaque �l�ment de l'ancien tableau dans le nouveau 
		}
		delete[] t.tabC;		//on supprime l'ancien tableau
		t.tabC = newT;		//on initialise le tableau � partir du nouveau
		t.capacite = newTaille;		//on initalise la taille du tableau avec la nouvelle taille
	}
}



/**
 * @brief v�rifie que l'�l�ment que l'on veut ajouter n'est pas d�j� dans le tableau de case
 * @param[in] t : tableau qui contient les cases masqu�s
 * @param[in] cased : les coordonn�es qui vont �tre utilis� pour la v�rification
 * @param[return] bool : true ou false
 */
bool v�rifier(tableau_case& t, coordonnees& cop) {
	for (int l = 0; l <= t.nbItems; l++) {
		if (cop.x == t.tabC[l].x && cop.y == t.tabC[l].y) {		//on cherche si l'�l�ment est d�j� dans le tableau
			return true;
		}
	}
	return false;
}


