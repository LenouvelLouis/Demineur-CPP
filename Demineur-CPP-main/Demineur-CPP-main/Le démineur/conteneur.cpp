/**
 * @file conteneur.cpp
 * Projet Démineur
 * @author Lenouvel Louis et Gabriel Esteves
 * @version 23/11/2021
 * @brief Composant de conteneur de case
 */


#include"conteneur.h"
#include<iostream>
#include<iomanip>
#include<cassert>
#pragma warning(disable: 4996)
using namespace std;

/**
 * @brief Initialise un conteneur de case
 * @param[out] c : le conteneur de case
 * @param [in] hauteur : hauteur du conteneur
 * @param [in] largeur: largeur du conteneur
 */
void initialiser(conteneur& c, unsigned int hauteur, unsigned int largeur) {
	c.hauteur = hauteur;
	c.largeur = largeur;
	c.tab = new Case * [hauteur];	//initialisation du conteneur
	for (int i = 0; i < hauteur; i++) {
		c.tab[i] = new Case[largeur]; //dans chaque élément on initialise un tableau pour obtenir un tableau à deux dimensions
		for (int j = 0; j < largeur; j++) {
			c.tab[i][j].statut_case = masque;	//on initialise par défaut les cases comme masqués
			c.tab[i][j].type = vide;	//on initialise par défaut les cases comme vide
			c.tab[i][j].nb_mine = 0;	//on initialise par défaut les cases comme n'ayant pas de mine à coté d'elle
		}
	}
}

/**
 * @brief Ajoute les mines au conteneur de case
 * @param[out] c : le conteneur de case
 * @param [in] nb : le nombre de mine à placer
 */
void ajoutMine(conteneur& c, unsigned int nb) {
	int i = 0, h = 0, j = 0, taille=c.hauteur*c.largeur;
	assert(nb <= taille);
	while (i < nb) { //on ajoute le nombre de mine demandé
		if (h > c.largeur) { //si nous avons dépassons la largeur deu tableau alors nous passons à la ligne suivante et nous revenons au premier élément
			j++;
			h = 0;
		}
		if (c.tab[j][h].statut_case == masque) {	
			c.tab[j][h].type = mine;	//on ajoute une mine
			i++;
		}
		h++;
	}
}

/**
 * @brief melange les mines au conteneur de case de manière aléatoire
 * @param[out] c : le conteneur de case
 * @param [in] nb : le nombre de mine à placer
 * @param [out] coo : coordonnés avec abscisse et ordonnée
 */
void melangerMine(conteneur& c, unsigned int nb, coordonnees& coo) {
	unsigned int début = 0, h = 0, i = 0, j = 0, n = c.largeur * c.hauteur;
	cout << c.hauteur << " " << c.largeur << " " << nb << " ";
	while(i<nb) {	//on mélange toutes les mines dans le conteneur
		if (h > c.largeur) { //si nous avons dépassons la largeur deu tableau alors nous passons à la ligne suivante et nous revenons au premier élément
			j++;
			h = 0;
		}
		début = rand() % n;		//on cherche une nouvelle position
		cPosition(c, début, coo);		//nous récupérons les coodonnées
		if(c.tab[coo.x][coo.y].type!=mine){		//on vérifie d'abord que ce n'est pas une mine 
			c.tab[coo.x][coo.y].type = c.tab[j][h].type;	//sinon on attribue la mine à une nouvelle case dans le tableau
			c.tab[j][h].type = vide;	//et l'ancienne case devient de type vide pour éviter les doublons
			h++;
			i++;
			cout << début << " ";
		}
	}
}




/**
 * @brief ajoute les nombres de mines dans les cases
 * @param[out] c : le conteneur de case
 * @param [in] x : hauteur de la case
 * @param [in] x : largeur de la case
 */
void ajouter_nbMine(conteneur& c, int x, int y) {
	for (int i = x - 1; i <= x + 1; i++) {
		for (int j = y - 1; j <= y + 1; j++) {
			if (i >= 0 && i <= c.hauteur - 1 && j >= 0 && j <= c.largeur - 1) { // si la case est compris dans le conteneur c
				c.tab[i][j].nb_mine++; // augmenter le nombre de mine
			}
		}

	}
}

/**
 * @brief cherche toutes les mines mines dans le conteneur c
 * @param[out] c : le conteneur de case
 */
void chercher_mine(conteneur& c) {
	for (unsigned int i = 0; i < c.hauteur; i++) {
		for (unsigned int j = 0; j < c.largeur; j++) {
			if (c.tab[i][j].type == mine) {
				ajouter_nbMine(c, i, j); // ajouter les nombres de mines autour de chaque mine trouvé
			}
		}
	}
}

/**
 * @brief convertis une position avec l'abscisse et l'ordonnée
 * @param[out] c : le conteneur de case
 * @param[in] x : hauteur de la case
 * @param[in] y : largeur de la case
 * @param[return] position : position convertis
 */
int recup(const conteneur& c, unsigned int x, unsigned int y) {
	unsigned int position;
	x = x * c.largeur;		//nous recalculons son abscisse
	position = x + y;		//nous recalculons sa position
	return position;
}

/**
 * @brief affiche le conteneur de case
 * @param[in] c : le conteneur de case
 */
void afficher(const conteneur& c) {
	int compteur = 0, i = 0;
	while (i < c.hauteur) {		//on affiche toutes les lignes de notre conteneur 
		if (compteur % 2 == 0) {		//une fois sur deux nous affichons une ligne de "___" grâce à un compteur
			for (int j = 0; j < c.largeur; j++) {		//nous affichons la ligne de "___"
				cout << " "<< "___";
			}
			++compteur;
			cout << endl;
		}
		else {
			for (int j = 0; j < c.largeur; j++) {		//nous affichons chaque élément de la ligne de notre conteneur
				if (c.tab[i][j].statut_case == masque) {
					if (j == 0) {
						cout << setiosflags(ios::right) << setw(1) << "| " << ".";		//on affiche un "." pour chaque case masquée
					}
					else
						cout << setiosflags(ios::right) << setw(1) << " | " << ".";
				}
				else if (c.tab[i][j].statut_case == drapeau) {
					if (j == 0) {
						cout << setiosflags(ios::right) << setw(1) << "| " << "x";		//on affiche un "X" pour chaque case  marquée d'un drapeau
					}
					else 
						cout << setiosflags(ios::right) << setw(1) << " | " << "x";
				}
				else if (c.tab[i][j].statut_case == demasque) {
					if (c.tab[i][j].type == vide) {
						if (c.tab[i][j].nb_mine == 0) {
							if (j == 0) {
								cout << setiosflags(ios::right) << setw(1) << "| " << " "; //on affiche un " " pour chaque case démasquée et vide 
							}
							else
								cout << setiosflags(ios::right) << setw(1) << " | " << " ";
						}
						else {
							if (j == 0) {
								cout << setiosflags(ios::right) << setw(1) << "| " << c.tab[i][j].nb_mine;		//on affiche un chiffre pour chaque case démasquée s'il y a une mine à coté
							}
							else
								cout << setiosflags(ios::right) << setw(1) << " | " << c.tab[i][j].nb_mine;
						}
					}
					if (c.tab[i][j].type == mine) {
						if (j == 0) {
							cout << setiosflags(ios::right) << setw(1) << "| " << "m";		//on affiche un "m" pour chaque case démasquée qui est une mine
						}
						else 
							cout << setiosflags(ios::right) << setw(1) << " | " << "m";
					}
				}

			}
			++compteur;
			i++;
			cout << " |" << endl;
		}
	}
	for (int j = 0; j < c.largeur; j++) {		//on affiche une dernière ligne de "___"
		cout << " " << "___";
	}
	cout << endl;
}

/**
 * @brief détermine si la partie est perdu
 * @param[in] c : le conteneur de case
 */
bool perdu(const conteneur& c) {
	for (int i = 0; i < c.hauteur; i++) {
		for (int j = 0; j < c.largeur; j++) {
			if (c.tab[i][j].statut_case == demasque && c.tab[i][j].type == mine) {		//si une case est de type mine et démasquée alors l'utilisateur a perdu
				return true;
			}
			else if (c.tab[i][j].statut_case == drapeau && c.tab[i][j].type == vide) {		//si une case est de type vide et marquée par un drapeau alors l'utilisateur a perdu
				return true;
			}
		}
	}
	return false;
}

/**
 * @brief détermine si la partie est gagné
 * @param[in] c : le conteneur de case
 */
bool gagne(const conteneur& c) {
	if (perdu(c) == false) {	//si la partie est perdu alors l'utilisateur n'a pas gagné
		return false;
	}
	else {
		for (int i = 0; i < c.hauteur; i++) {
			for (int j = 0; j < c.largeur; j++) {
				if (c.tab[i][j].statut_case == masque && c.tab[i][j].type == vide) {	//si une case est de type vide et masquée alors l'utilisateur n'a toujours pas gagnée
					return false;
				}
			}
		}
	}
}

/**
 * @brief créer la map avec la commande 5 à partir d'un texte représentant un conteneur
 * @param[out] c : le conteneur de case
 */
void creer_map(conteneur& c) {
	unsigned int hauteur = 0, largeur = 0, compteur = 0, nb = 0, dep = 2;
	const int TAILLE = 5 * c.largeur;
	cin >> std::ws; // ignore le \n qui suit les 3 entiers
	cin.ignore(TAILLE, '\n'); // ignore la ligne de séparation " ___ ___ ..."
	char valeur[5];
	while (hauteur < c.hauteur) {
		cin.get(valeur, 5);	//on lit 5 éléments par 5 éléments
		if (valeur[2] == '|') {		//si on lit "|" au deuxième élément de ce que l'on a scanné alors on modifie le lieu de lecture car sinon on subit le décalage après chaque ligne
			dep = 0;
		}
		if (dep < 4) {		//on ne lit que si le lieu de lecture est inférieur à 4 car à cause du décalage le lieu de lecture ne fonctionne qu'avec 0,1,2 et 3
			switch (valeur[dep]) {
			case ' ':
				c.tab[hauteur][largeur].statut_case = demasque;		
				c.tab[hauteur][largeur].type = vide;
				largeur++;
				break;
			case '.':
				c.tab[hauteur][largeur].statut_case = masque;
				largeur++;
				break;
			case 'x':
				c.tab[hauteur][largeur].statut_case = drapeau;
				largeur++;
				break;
			case '_':
				break;
			default:		//par défaut si aucun des éléments lu ne correspond à une condition c'est forcément un chiffre donc nous le convertissons
				sscanf(&valeur[dep], "%d", &nb);		//nous convertissons donc l'éléments en int
				c.tab[hauteur][largeur].nb_mine = nb;
				c.tab[hauteur][largeur].statut_case = demasque;
				largeur++;
				break;
			}
		}
		if (largeur >= c.largeur) {
			hauteur++;
			largeur = 0;
			cin.ignore(TAILLE, '\n'); // ignore le \n qui fini la ligne
			cin.ignore(TAILLE, '\n'); // ignore la ligne de séparation " ___ ___ ..."
		}
	}
}

/*
 * @brief démasque toutes les mines du conteneur c si le joueur a perdu
 * @param[out] c : le conteneur de case
 */
void afficher_amine(conteneur& c) {
	for (int i = 0; i < c.hauteur; i++) {
		for (int j = 0; j < c.largeur; j++) {
			if (c.tab[i][j].type == mine) {		//dès que nous trouvons une mine nous la démasquons 
				c.tab[i][j].statut_case = demasque;
			}
		}
	}
}


/*
 * @brief executes les différents commandes rentrées par l'utilisateur
 * @param[out] c : le conteneur de case
 * @param[out] coo : coordonnées utilisés pour les différents appelles de fonction
 * @param[out] t : tableau de cases démasquées
 */
void jouer(conteneur& c, coordonnees& coo, tableau_case& t) {
	unsigned int commande, hauteur, largeur, mine, position_mine, nb_coup, position_action;
	char coup_joueur[30];
	char action;
	cin >> commande;		//commande rentrée par l'utilisateur
	switch (commande) {		//on regarde quelle commande a été rentrée
	case 1:			//On produit un problème à partir du nombre de ligne, de collones et de mines
		cin >> hauteur >> largeur >> mine;	
		c.mine = mine;
		initialiser(c, hauteur, largeur);
		ajoutMine(c, c.mine);
		melangerMine(c, c.mine, coo);
		chercher_mine(c);
		break;
	case 2:			//On produit une grille  à partir d’un problème et d’un historique de coups
		cin >> hauteur >> largeur >> mine;		
		initialiser(c, hauteur, largeur);
		for (unsigned int i = 0; i < mine; i++) {
			cin >> position_mine;
			placerMine(c, position_mine, coo);
		}
		chercher_mine(c);
		cin >> nb_coup;
		for (unsigned int i = 0; i < nb_coup; i++) {
			cin >> coup_joueur;
			sscanf(coup_joueur, "%c %d", &action, &position_action);
			coup(c, action, position_action, coo, t);
		}
		cout << hauteur << " " << largeur << endl;
		afficher(c);
		break;
	case 3:		//On détermine si la partie est gagnée à partir d'un problème et d'un historique de coups
		cin >> hauteur >> largeur >> mine;
		initialiser(c, hauteur, largeur);
		for (unsigned int i = 0; i < mine; i++) {
			cin >> position_mine;
			placerMine(c, position_mine, coo);
		}
		chercher_mine(c);
		cin >> nb_coup;
		for (unsigned int i = 0; i < nb_coup; i++) {
			cin >> coup_joueur;
			sscanf(coup_joueur, "%c %d", &action, &position_action);
			coup(c, action, position_action, coo, t);
		}
		if (gagne(c) == 0) {
			cout << "game not won";
		}
		else
			cout << "Game won";
		break;
	case 4:		//On détermine si la partie est perdu à partir d'un problème et d'un historique de coups
		cin >> hauteur >> largeur >> mine;
		initialiser(c, hauteur, largeur);
		for (unsigned int i = 0; i < mine; i++) {
			cin >> position_mine;
			placerMine(c, position_mine, coo);
		}
		cin >> nb_coup;
		for (unsigned int i = 0; i < nb_coup; i++) {
			cin >> coup_joueur;
			sscanf(coup_joueur, "%c %d", &action, &position_action);
			coup(c, action, position_action, coo, t);
		}
		chercher_mine(c);
		if (perdu(c) == 1) {
			cout << "game lost";
		}
		else
			cout << "game not lost";
		break;
	case 5:		//On produit un nouveau coup à partir d'une grille donnée
		cin >> hauteur >> largeur;
		initialiser(c, hauteur, largeur);
		creer_map(c);
		case_masque(c, t);
		coupAleatoire(c, t);
		break;
	default:	//la commande n'existe pas
		cout << "commande non reconnue" << endl;
		break;
	}
}


/**
 * @brief Ajoute les mines au conteneur de case
 * @param[out] c : le conteneur de case
 * @param [in] positon : position à convertir en abscisse et ordonnée en fonction de la hauteur et la largeur du conteneur c
 * @param [out] coo : coordonnées avec l'abscisse et l'ordonnée
 */
void cPosition(conteneur& c, unsigned int position, coordonnees& coo) {
	coo.x = (position - (position % c.largeur)) / c.largeur; // abscisse de la position
	coo.y = position % c.largeur; // ordonnée de la position
}


/**
 * @brief place les mines au conteneur de case en fonction des positions entrées
 * @param[out] c : le conteneur de case
 * @param [in] nb : le nombre de mine à placer
 * @param [out] coo : coordonnés avec abscisse et ordonnée
 */
void placerMine(conteneur& c, unsigned int position, coordonnees& coo) {
	cPosition(c, position, coo); // coordonnées convertis pour les placer dans le tableau
	c.tab[coo.x][coo.y].type = mine; // changement du type de la case (mine) en fonction des coordonnées
}

/**
 * @brief ajoute toutes les coordonnées des cases vides dans le tableau de case
 * @param[in] c : le conteneur de case
 * @param[out] t : tableau qui contient les cases vide
 * @param[out] cased : les coordonnées qui vont être utilisé pour l'implémentation dans le tableau de case
 */
void case_vide(conteneur& c, tableau_case& t, coordonnees& cased) {
	int x, y;
	t.nbItems = 1;
	t.capacite = 1;
	t.extension = 2;
	coordonnees cop;
	t.tabC = new coordonnees[t.capacite];		//on initialise le tableau
	unsigned int i = 0;
	t.tabC[i].x = cased.x;		//on implémente un premier élément qui est la case vide que l'on a démasqué
	t.tabC[i].y = cased.y;		//on implémente un premier élément qui est la case vide que l'on a démasqué
	while (i <= t.nbItems) {		//on vérifie pour chaque case vide du tableau
		y = t.tabC[i].y;
		x = t.tabC[i].x;
		for (int j = x - 1; j <= x + 1; j++) {
			for (int h = y - 1; h <= y + 1; h++) {		//on parcourt toutes les cases autour d'elle y compris elle même 
				if (j >= 0 && j <= c.hauteur - 1 && h >= 0 && h <= c.largeur - 1 && c.tab[j][h].type == vide && c.tab[j][h].nb_mine == 0) {		//on vérifie si les coordonnées sont valide et si la case est bien une case vide sans chiffre
					cop.x = j;		//alors on convertie le x trouvé x de type coordonnées
					cop.y = h;		//alors on convertie le y trouvé y de type coordonnées
					if (vérifier(t, cop) == false) {		//on vérifie avant d'ajouter que l'élément n'est pas déjà dedans
						allocation(t, t.nbItems);		//on vérifie que l'on dépasse pas la capacité du tableau 
						t.tabC[t.nbItems].x = cop.x;		//alors on ajoute les coordonnées trouvées dans notre tableau de case
						t.tabC[t.nbItems].y = cop.y;		//alors on ajoute les coordonnées trouvées dans notre tableau de case
						t.nbItems++;		//on passe à l'élément suivant
					}
				}
			}
		}
		i++;
	}
}

/*
 * @brief démasque toutes les cases vides présentent dans le tableau
 * @param[out] c : le conteneur de case
 * @param[in] t : le tableau de case
 */
void vider(conteneur& c, tableau_case& t) {
	unsigned int x, y;
	for (int i = 0; i < t.capacite; i++) {		//on parcourt toutes les cases du tableau 
		y = t.tabC[i].y;
		x = t.tabC[i].x;
		for (unsigned int j = x - 1; j <= x + 1; j++) {
			for (unsigned int h = y - 1; h <= y + 1; h++) {		//on parcourt toutes les cases autour de l'élément du tableau y compris lui même 
				if (j >= 0 && j <= c.hauteur - 1 && h >= 0 && h <= c.largeur - 1 && c.tab[j][h].type == vide) {		//on vérifie si les coordonnées sont valide et si la case est bien une case vide
					c.tab[j][h].statut_case = demasque;		//on démasque la case
				}
			}
		}
	}
}
/*
 * @brief executes les différents coup rentrées par l'utilisateur
 * @param[out] c : le conteneur de case
 * @param[in] action1 : action de l'utilisateur (masqué ou démasqué)
 * @param[in] position : case choisit pour faire l'action
 * @param[in] coo : coordonnées qui sont utilisés pour les vérifications de la fonction
 * @param[in] t : tableau de cases à démasquées
 */
void coup(conteneur& c, char action1, unsigned int position, coordonnees& coo, tableau_case& t) {
	unsigned int ligne, colonne;
	if (action1 == 'M') {
		cPosition(c, position, coo); // converti de la position en coordonnées x et y
		if (c.tab[coo.x][coo.y].type == mine) {
			c.tab[coo.x][coo.y].statut_case = drapeau;
		}
		else if (c.tab[coo.x][coo.y].type == vide) { //si la case marqué est vide alors on a perdu
			afficher_amine(c);		//donc nous affichons toutes les mines 
			c.tab[coo.x][coo.y].statut_case = drapeau;
		}
	}
	else if (action1 == 'D') {
		cPosition(c, position, coo); // converti de la position en coordonnées x et y
		c.tab[coo.x][coo.y].statut_case = demasque;
		if (c.tab[coo.x][coo.y].type == vide) {	
			case_vide(c, t, coo);		//nous vidons toutes les cases autour
			vider(c, t);
		}
		else if (c.tab[coo.x][coo.y].type == mine) { // si la case démasqué est une mine alors on a perdu
			afficher_amine(c); // affichage de toutes les mines
		}
	}
	else
		cout << "Commande non reconnue" << endl;
}

/**
 * @brief stock les cases masqués dans un tableau
 * @param[in] c : le conteneur de case
 * @param[out] t : tableau de case masqué
 */
void case_masque(const conteneur& c, tableau_case& t) {
	unsigned int indice = 0;
	t.nbItems = 1;
	t.capacite = 1;
	t.extension = 2;
	t.tabC = new coordonnees[t.capacite];		//on initialise le tableau 
	coordonnees cop;
	for (unsigned int i = 0; i < c.hauteur; i++) {
		for (unsigned int j = 0; j < c.largeur; j++) {	
			if (i >= 0 && i <= c.hauteur - 1 && j >= 0 && j <= c.largeur - 1 && c.tab[i][j].statut_case == masque) {
				cop.x = i;
				cop.y = j;
				allocation(t, t.nbItems);		//on vérifie que l'on dépasse pas la capacité du tableau 
				t.tabC[indice].x = cop.x;		//alors on ajoute la case dans le tableau
				t.tabC[indice].y = cop.y;
				indice++;
				t.nbItems++;		//on augmente le nombre d'items 
			}
		}
	}
}

/**
 * @brief propose un coup aléatoire possible sur une case masqué
 * @param[out] c : le conteneur de case
 * @param[in] t : tableau qui contient les cases masqués
 */
void coupAleatoire(const conteneur& c, tableau_case& t) {
	unsigned int case_a, action;
	case_a = rand() % t.nbItems - 1;		//on choisit une case aléatoirement dans le tableau de case masquées
	action = rand() % 2;		//on choisit une des deux actions possible aléatoirement (1 = démasqué et 0 = masqué=)
	if (t.nbItems - 1 == 0) {
		cout << "Aucun coup possible" << endl;
	}
	else if (action == 1) {
		cout << 'D' << recup(c, t.tabC[case_a].x, t.tabC[case_a].y);
	}
	else if (action == 0) {
		cout << 'M' << recup(c, t.tabC[case_a].x, t.tabC[case_a].y);
	}
}
