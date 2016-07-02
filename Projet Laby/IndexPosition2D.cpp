/**
 * @file IndexPosition.h
 * Projet Labyrinthe
 * @author BURNER Whitney et DELERIN Maxime 
 * @version 1 30/12/2013
 * @brief Composant des index de position d'une case.
 * Structures de données et algorithmes - DUT1 Paris 5
 */

#include "stdafx.h"
#include <iostream>
#include <fstream>

//#include <valarray>
#include <stdlib.h>

#include "IndexPosition2D.h"

using namespace std;
/** 
 * brief Initialisation d'un IndexPosition2D vide
 * @see detruire, l' IndexPosition2D est à désallouer en fin d’utilisation
 * @param[in] i : entier positif égal a 0 pour l'abscisse
 * @param[in] j : entier positif égal a 0 pour les ordonnees
 * @param[in,out] index : l'IndexPosition2D
 
*/
void initialisation(IndexPosition2D& index, unsigned int i, unsigned int j) {
	// Les coordonnées d'index deviennent [0;0]
	index.x=i;
	index.y=j;
}

/** 
 * brief Determination de la connexité de deux IndexPosition2D 
 * @param[in] i1 : Le premier IndexPosition2D
 * @param[in] i2 : Le deuxieme IndexPosition2D
*/
bool estConnexe(const IndexPosition2D& i1, const IndexPosition2D& i2) {
	// Si les deux cases sont sur la meme ligne et sont dans des colonnes cote a cote
	// Ou si les deux cases sont dans la meme colonne et sont sur des lignes
	// cote a cote : Les deux IndexPosition sont connexe
	if((((i1.y - i2.y == 1) || (i2.y - i1.y) ==1) && i2.x - i1.x == 0 ) || 
		(((i1.x - i2.x == 1) || (i2.x - i1.x) ==1) && i2.y - i1.y == 0 )){
		return ( true );
	}
	
	return ( false );
}

/** 
 * brief Affichage d'un IndexPositon2D a l'ecran
 * @param[in] index : l'IndexPosition2D a afficher
*/
void afficher( IndexPosition2D& index ){

	cout << "[" << index.x << ", " << index.y << "] ";

}


