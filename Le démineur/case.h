#ifndef _Case_
#define _Case_

/**
 * @file case.h
 * Projet D�mineur
 *  @author Lenouvel Louis et Gabriel Esteves
 * @version 23/11/2021
 * @brief Composant de case sur un conteneur
 */

/** @brief type Etat pour chaque �tat possible de la case
 */
enum  Etat { masque, demasque, drapeau };

/** @brief Type type pour chaque type de case diff�rent
 */
enum type { vide, mine };


/** @brief type Case
* contenant le nombre de mine
* avec le statut de la case et son type
 */
struct Case {
	unsigned int nb_mine;	//nombre de mine pr�sent � c�t� de la case
	Etat statut_case;	//etat de la case
	type type;	//type de la case
};
#endif