/**
 * @file main.cpp
 * Projet Démineur
 * @author Lenouvel Louis et Gabriel Esteves
 * @version 23/11/2021
 */


#include<cstdio>
#include<iomanip>
#include "tableau_case.h"
#include "conteneur.h"
using namespace std;



/* Test du jeu*/
int main() {
	srand(time(NULL));
	coordonnees coo;
	conteneur c;
	tableau_case t;
	jouer(c, coo, t);
}