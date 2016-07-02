/**
 * @file Labyrinthe2D.cpp
 * Projet Labyrinthe
 * @author BURNER Whitney et DELERIN Maxime 
 * @version 1 30/12/2013
 * @brief Composant d'un labyrinthe à deux dimensions.
 * Structures de données et algorithmes - DUT1 Paris 5
 */
#include "stdafx.h"
#include <iostream>
#include <string> 
#include <fstream>

#include "Labyrinthe2D.h"

using namespace std;


/** 
 * brief Initialisation d'un Labyrinthe2D vide
 * Le Labyrinthe2D est allouée en mémoire dynamique
 * @see detruire, le Labyrinthe2D est à désallouer en fin d’utilisation
 * @param[in,out] f : flux de sortie
 * @param[in,out] t : le Labyrinthe2D
*/


void initialiser(Labyrinthe2D& l, std::ifstream& f){char car;
	unsigned int xmax,ymax;

	// On lit sur la premiere ligne la premiere chaine qui correspond au
	// nombre de ligne
	////////////f.getline(c, n, delim);
	f >> xmax ;
	f >> ymax ;

		// On initialise le tableau tab2D du labyrinthe l
		initialiser(l.tab2D, xmax, ymax );

		// Tant que x est plus petit que le nombre de ligne du labyrinthe
		// Donc tant que l'on a pas lu toute les lignes du labyrinthe

			// Tant que y est inferieur au nombre de colonne
			// Donc tant que l'on a pas parcouru toute la ligne
			for ( unsigned int x = 0 ; x < xmax ; x++){
				for( unsigned int y = 0 ; y < ymax; y++){

					f >> car ;
					l.tab2D.tab[x][y] = (Item2D)car;
					
					if(l.tab2D.tab[x][y] == MINOTAURE ){
					initialisation(l.minotaure, x, y);
					}
					// Si on passe sur la case de l'entrée du labyrinthe on recupère
					// ses coordonnées
					if(l.tab2D.tab[x][y] == THESEE ){
						initialisation(l.entree, x, y);
					}	

				}

	}
}

		

	
/** 
 * brief Desallocation d'un Labyrinthe2D 
 * @see initialiser, le Labyrinthe2D a deja été alloué en mémoire dynamique
 * @param[in,out] t : le Labyrinthe2D
*/

void detruire(Labyrinthe2D& l){
	detruire(l.tab2D);
	//delete []l.tab2D;
	l.entree.x = NULL ;
	l.entree.y = NULL ;
	l.minotaure.x = NULL ;
	l.minotaure.y = NULL ;
}

/** 
 * brief Affichage d'un Labyrinthe2D 
 * @see initialiser, le Labyrinthe2D a deja été alloué en mémoire dynamique
 * @param[in,out] t : le Labyrinthe2D
*/
void afficher (Labyrinthe2D& l){
	afficher(l.tab2D); 

}

