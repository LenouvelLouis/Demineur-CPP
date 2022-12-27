#ifndef _Conteneur_
#define _Conteneur_

/**
 * @file conteneur.h
 * Projet Démineur
 *  @author Lenouvel Louis et Gabriel Esteves
 * @version 23/11/2021
 * @brief Composant d'un conteneur de case
 */

#include "case.h"
#include"tableau_case.h"

/** @brief Conteneur de case en deux dimensions
 *  de capacité définit par largeur et hauteur
 * contenant un nombre de mine définit par l'utilisateur
 */
struct conteneur {
	unsigned int hauteur;	//hauteur du conteneur
	unsigned int largeur;	//largeur du conteneur
	unsigned int mine;	//nombre de mine du conteneur
	Case** tab;	//conteneur à deux dimensions 
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
 * @param [in] nb : le nombre de mine à placer
 */
void ajoutMine(conteneur& c, unsigned int nb);

/**
 * @brief melange les mines au conteneur de case de manière aléatoire
 * @param[out] c : le conteneur de case
 * @param [in] nb : le nombre de mine à placer
 * @param [out] coo : coordonnés avec abscisse et ordonnée
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
 * @brief convertit une position avec l'abscisse et l'ordonnée
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
 * @brief détermine si la partie est perdu
 * @param[in] c : le conteneur de case
 */
bool perdu(const conteneur& c);

/**
 * @brief détermine si la partie est gagné
 * @param[in] c : le conteneur de case
 */
bool gagne(const conteneur& c);

/**
 * @brief créer la map avec la commande 5 à partir d'un texte représentant un conteneur
 * @param[out] c : le conteneur de case
 */
void creer_map(conteneur& c);

/*
 * @brief démasque toutes les mines du conteneur c si le joueur a perdu
 * @param[out] c : le conteneur de case
 */
void afficher_amine(conteneur& c);

/*
 * @brief executes les différents commandes rentrées par l'utilisateur
 * @param[out] c : le conteneur de case
 * @param[out] coo : coordonnées utilisés pour les différents appelles de fonction
 * @param[out] t : tableau de cases démasquées
 */
void jouer(conteneur& c, coordonnees& coo, tableau_case& t);

/**
 * @brief Ajoute les mines au conteneur de case
 * @param[out] c : le conteneur de case
 * @param [in] positon : position à convertir en abscisse et ordonnée en fonction de la hauteur et la largeur du conteneur c
 * @param [out] coo : coordonnées avec l'abscisse et l'ordonnée
 */
void cPosition(conteneur& c, unsigned int position, coordonnees& coo);

/**
 * @brief place les mines au conteneur de case en fonction des positions entrées
 * @param[out] c : le conteneur de case
 * @param [in] nb : le nombre de mine à placer
 * @param [out] coo : coordonnés avec abscisse et ordonnée
 */
void placerMine(conteneur& c, unsigned int position, coordonnees& coo);

/**
 * @brief ajoute toutes les coordonnées des cases vides dans le tableau de case
 * @param[in] c : le conteneur de case
 * @param[out] t : tableau qui contient les cases vide
 * @param[out] cased : les coordonnées qui vont être utilisé pour l'implémentation dans le tableau de case
 */
void case_vide(conteneur& c, tableau_case& t, coordonnees& cased);

/*
 * @brief démasque toutes les cases vides présentent dans le tableau
 * @param[out] c : le conteneur de case
 * @param[in] t : le tableau de case
 */
void vider(conteneur& c, tableau_case& t);

/*
 * @brief executes les différents coup rentrées par l'utilisateur
 * @param[out] c : le conteneur de case
 * @param[in] action1 : action de l'utilisateur (masqué ou démasqué)
 * @param[in] position : case choisit pour faire l'action
 * @param[in] coo : coordonnées qui sont utilisés pour les vérifications de la fonction
 * @param[in] t : tableau de cases à démasquées
 */
void coup(conteneur& c, char action1, unsigned int position, coordonnees& coo, tableau_case& t);

/**
 * @brief stock les cases masqués dans un tableau
 * @param[in] c : le conteneur de case
 * @param[out] t : tableau de case masqué
 */
void case_masque(const conteneur& c, tableau_case& t);

/**
 * @brief propose un coup aléatoire possible sur une case masqué
 * @param[out] c : le conteneur de case
 * @param[in] t : tableau qui contient les cases masqués
 */
void coupAleatoire(const conteneur& c, tableau_case& t);

#endif