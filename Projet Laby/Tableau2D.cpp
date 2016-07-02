/**
 * @file Tableau2D.cpp
 * Projet Labyrinthe
 * @author BURNER Whitney et DELERIN Maxime 
 * @version 1 30/12/2013
 * @brief Composant de tableau à deux dimensions.
 * Structures de données et algorithmes - DUT1 Paris 5
 */
#include "stdafx.h"
#include <iostream>
using namespace std;

#include "Tableau2D.h"

/** 
 * brief Initialisation d'un Tableau2D vide
 * Le Tableau2D est allouée en mémoire dynamique
 * @see detruire, le Tableau2D est à désallouer en fin d’utilisation
 * @param[in] dimX : dimension horizontale du tableau
 * @param[in] dimY : dimension verticale du tableau
 * @param[in,out] t : le Tableau2D
 */
void initialiser(Tableau2D& t, unsigned int dimX, unsigned dimY ){
	// initialisation du nombre de lignes du labyrinthe
	t.dimX=dimX;
	// initialisation du nombre de colonnes du labyrinthe
	t.dimY=dimY;
	//Allocation d'un tableau de pointeur sur Item2D de dimension dimX
	t.tab=new Item2D*[dimX];

	//Allocation d'un tableau d'Item2D de dimension dimX dans chaque
	// t.tab[i] avec i variant de 0 à dimX
	for( unsigned int i = 0; i < dimX ; i++)
	{
		t.tab[i] = new Item2D[dimY];
		
	}

}

/** 
 * brief Desallocation d'un Tableau2D
 * @see initialiser, le Tableau2D a deja été alloué en mémoire dynamique
 * @param[in,out] t : le Tableau2D
 */
void detruire(Tableau2D& t){
	//Desallocation de tableaux t.tab[i] avec i variant de 0 à dimX
	for( unsigned int i = 0 ; i < t.dimX-1 ; i++ ){

		delete []t.tab[i];
	}
	//Desallocation d'un tableau
	delete []t.tab;

	 t.tab = NULL;
	 t.dimX = NULL;
	 t.dimY = NULL;
}

/** 
 * brief Affichage d'un Tableau2D plein
 * @see initialiser, le Tableau2D a deja été alloué en mémoire dynamique
 * @param[in,out] t : le Tableau2D
 */
void afficher(Tableau2D& t){
	// Pour chaque lignes
	for( unsigned int i=0 ; i < t.dimX ; i++){
		// Pour chaque colonnes
		for ( unsigned int j =0 ; j < t.dimY ; j++ )
		{
			// Affchage de l'element du tableau t.tab[i][j]
			cout << (char)t.tab[i][j] ;
		}
		cout<< endl;
	}

}



