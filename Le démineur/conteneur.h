#ifndef _Conteneur_
#define _Conteneur_

/**
 * @file conteneur.h
 * Projet D�mineur
 *  @author Lenouvel Louis et Gabriel Esteves
 * @version 23/11/2021
 * @brief Composant d'un conteneur de case
 */

#include "case.h"
#include"tableau_case.h"

/** @brief Conteneur de case en deux dimensions
 *  de capacit� d�finit par largeur et hauteur
 * contenant un nombre de mine d�finit par l'utilisateur
 */
struct conteneur {
	unsigned int hauteur;	//hauteur du conteneur
	unsigned int largeur;	//largeur du conteneur
	unsigned int mine;	//nombre de mine du conteneur
	Case** tab;	//conteneur � deux dimensions 
};

/**
 * @brief Initialise un conteneur de case
 * @param[out] c : le conteneur de case
 * @param [in] hauteur : hauteur du conteneur
 * @param [in] largeur: largeur du conteneur
 */
void initialiser(conteneur& c, unsigned int hauteur, unsigned int largeur);

/**
 * @brief Ajoute les mines au conteneur de case
 * @param[out] c : le conteneur de case
 * @param [in] nb : le nombre de mine � placer
 */
void ajoutMine(conteneur& c, unsigned int nb);

/**
 * @brief melange les mines au conteneur de case de mani�re al�atoire
 * @param[out] c : le conteneur de case
 * @param [in] nb : le nombre de mine � placer
 * @param [out] coo : coordonn�s avec abscisse et ordonn�e
 */
void melangerMine(conteneur& c, unsigned int nb, coordonnees& coo);

/**
 * @brief ajoute les nombres de mines dans les cases
 * @param[out] c : le conteneur de case
 * @param [in] x : hauteur de la case
 * @param [in] x : largeur de la case
 */
void ajouter_nbMine(conteneur& c, int x, int y);

/**
 * @brief cherche toutes les mines mines dans le conteneur c
 * @param[out] c : le conteneur de case
 */
void chercher_mine(conteneur& c);

/**
 * @brief convertit une position avec l'abscisse et l'ordonn�e
 * @param[in] c : le conteneur de case
 * @param[in] x : hauteur de la case
 * @param[in] y : largeur de la case
 * @param[return] position : position convertis
 */
int recup(const conteneur& c, unsigned int x, unsigned int y);

/**
 * @brief affiche le conteneur de case
 * @param[in] c : le conteneur de case
 */
void afficher(const conteneur& c);

/**
 * @brief d�termine si la partie est perdu
 * @param[in] c : le conteneur de case
 */
bool perdu(const conteneur& c);

/**
 * @brief d�termine si la partie est gagn�
 * @param[in] c : le conteneur de case
 */
bool gagne(const conteneur& c);

/**
 * @brief cr�er la map avec la commande 5 � partir d'un texte repr�sentant un conteneur
 * @param[out] c : le conteneur de case
 */
void creer_map(conteneur& c);

/*
 * @brief d�masque toutes les mines du conteneur c si le joueur a perdu
 * @param[out] c : le conteneur de case
 */
void afficher_amine(conteneur& c);

/*
 * @brief executes les diff�rents commandes rentr�es par l'utilisateur
 * @param[out] c : le conteneur de case
 * @param[out] coo : coordonn�es utilis�s pour les diff�rents appelles de fonction
 * @param[out] t : tableau de cases d�masqu�es
 */
void jouer(conteneur& c, coordonnees& coo, tableau_case& t);

/**
 * @brief Ajoute les mines au conteneur de case
 * @param[out] c : le conteneur de case
 * @param [in] positon : position � convertir en abscisse et ordonn�e en fonction de la hauteur et la largeur du conteneur c
 * @param [out] coo : coordonn�es avec l'abscisse et l'ordonn�e
 */
void cPosition(conteneur& c, unsigned int position, coordonnees& coo);

/**
 * @brief place les mines au conteneur de case en fonction des positions entr�es
 * @param[out] c : le conteneur de case
 * @param [in] nb : le nombre de mine � placer
 * @param [out] coo : coordonn�s avec abscisse et ordonn�e
 */
void placerMine(conteneur& c, unsigned int position, coordonnees& coo);

/**
 * @brief ajoute toutes les coordonn�es des cases vides dans le tableau de case
 * @param[in] c : le conteneur de case
 * @param[out] t : tableau qui contient les cases vide
 * @param[out] cased : les coordonn�es qui vont �tre utilis� pour l'impl�mentation dans le tableau de case
 */
void case_vide(conteneur& c, tableau_case& t, coordonnees& cased);

/*
 * @brief d�masque toutes les cases vides pr�sentent dans le tableau
 * @param[out] c : le conteneur de case
 * @param[in] t : le tableau de case
 */
void vider(conteneur& c, tableau_case& t);

/*
 * @brief executes les diff�rents coup rentr�es par l'utilisateur
 * @param[out] c : le conteneur de case
 * @param[in] action1 : action de l'utilisateur (masqu� ou d�masqu�)
 * @param[in] position : case choisit pour faire l'action
 * @param[in] coo : coordonn�es qui sont utilis�s pour les v�rifications de la fonction
 * @param[in] t : tableau de cases � d�masqu�es
 */
void coup(conteneur& c, char action1, unsigned int position, coordonnees& coo, tableau_case& t);

/**
 * @brief stock les cases masqu�s dans un tableau
 * @param[in] c : le conteneur de case
 * @param[out] t : tableau de case masqu�
 */
void case_masque(const conteneur& c, tableau_case& t);

/**
 * @brief propose un coup al�atoire possible sur une case masqu�
 * @param[out] c : le conteneur de case
 * @param[in] t : tableau qui contient les cases masqu�s
 */
void coupAleatoire(const conteneur& c, tableau_case& t);

#endif