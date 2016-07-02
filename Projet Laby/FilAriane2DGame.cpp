/**
 * @file FilAriane2DGame.cpp
 * Projet Labyrinthe
 * @author BURNER Whitney et DELERIN Maxime 
 * @version 1 30/12/2013
 * @brief Composant du jeu de role FilAriane.
 * Structures de donn�es et algorithmes - DUT1 Paris 5
 */

#include "stdafx.h"
#include <iostream>
#include <string> 
#include <fstream>
#include <iomanip>
 

using namespace std;

#include "FilAriane2DGame.h"
#include "Liste.h"
#include "Pile.h"

/**
 * brief Initialisation d'un FilAriane2DGame vide
 * @see detruire, le jeu FilAriane2DGame est � d�sallouer en fin d�utilisation
 * @param[in,out] fl : flux de sortie
 * @param[in,out] t : le jeu FilAriane2DGame

*/
void initialiser(FilAriane2DGame& f, ifstream& fl){
	unsigned int capa, pas;   // capacit� et pas des conteneursTDE

	// Initialisation du labyrinthe
	initialiser(f.lab, fl);
	// Calcul de la capacit�
	capa = 100;
	// Calcul du pas
	pas = 200;
	// Initialisation de la pile de f
	initialiser(f.plan,  capa,  pas);
	// Initialisation de la liste de f
	initialiser(f.chemin, capa,  pas);

}

/**
 * brief Desallocation d'un jeu FilAriane2DGame
 * @see initialiser, le jeu FilAriane2DGame  a deja �t� allou� en m�moire dynamique
 * @param[in,out] f : le jeu FilAriane2DGame
*/
void detruire(FilAriane2DGame& f){
	// Destruction du labyrinthe
	detruire(f.lab);
	// Destruction de la pile de f
	detruire(f.plan);
	// Destruction de la liste de f
	detruire(f.chemin);
}

/**
 * brief Recherche du minotaure un jeu FilAriane2DGame
 * d�roulement du jeu
 * @see initialiser, le jeu FilAriane2DGame  a deja �t� allou� en m�moire dynamique
 * @param[in,out] f : le jeu FilAriane2DGame
 * @param[in] e : L' IndexPosition2D de l'entr�e du labyrinthe
*/
bool recherche(FilAriane2DGame& f,const IndexPosition2D& e){

	IndexPosition2D index1, index2;

	//Empilement de la position de l'entr�e du labyrinthe dans la pile
	empiler(f.plan, e);
	index1 = e;

	// Tant que l'on ne trouve pas le minotaure et qu'il reste des chemins a parcourir
	while( f.lab.tab2D.tab[index1.x][index1.y] != MINOTAURE && !estVide(f.plan)){
		// On recup�re les coordonn�es de l'entr�e du prochain chemin a explorer
		index1 = sommet(f.plan);
		// On le supprime des la pile des chemins a explorer.
		depiler(f.plan);
		// Th�s�e se d�place sur cette case. La case est marqu� comme "visit��" si le minotaure ne s'y trouve pas
		if(f.lab.tab2D.tab[index1.x][index1.y] != (char)MINOTAURE){
			f.lab.tab2D.tab[index1.x][index1.y] = VISITEE;
		}

		
		// On r�cup�re les coordonn�es de la derniere case visit� dans la liste
		// du chemin parcouru
		if( longueur(f.chemin)>0 ){
		index2 = lire(f.chemin, longueur(f.chemin)-1);
		// Tant que la derniere case du chemin n'est pas a cot� de la case ou est Th�s�e
		// on supprime la derniere case du chemin
		while( longueur(f.chemin) > 0 && !estConnexe(index1, index2)  ){
			supprimer(f.chemin, longueur(f.chemin)-1);
			index2 = lire(f.chemin, longueur(f.chemin)-1);
			}
		}		
		// On ecrit les coordonn�es de la case ou est Th�s�e a la fin de la liste
		// du chemin

		 inserer(f.chemin, longueur(f.chemin), index1);

		// Si la case ou est Th�s�e n'est pas celle du minotaure
		// On empile les coordonn�es des prochaine cases ( est, nord, ouest et sud
		// a parcourir ,si elles n'ont pas �t� visit�e et si ce ne sont pas des murs,
		// dans la pile
		if( f.lab.tab2D.tab[index1.x][index1.y] != MINOTAURE ){

			// Est
			if(f.lab.tab2D.tab[index1.x][index1.y+1] != MUR && f.lab.tab2D.tab[index1.x][index1.y+1] != VISITEE && (f.lab.tab2D.tab[index1.x][index1.y+1] == PASSAGE || f.lab.tab2D.tab[index1.x][index1.y+1] == MINOTAURE) ){
				
				index2.x = index1.x;
				index2.y = index1.y+1;
				empiler(f.plan, index2);
			}
			
			//Nord
			if(f.lab.tab2D.tab[index1.x-1][index1.y] != MUR && f.lab.tab2D.tab[index1.x-1][index1.y] != VISITEE && (f.lab.tab2D.tab[index1.x-1][index1.y] == PASSAGE || f.lab.tab2D.tab[index1.x-1][index1.y] == MINOTAURE)){
							index2.y = index1.y;
							index2.x = index1.x-1;
							empiler(f.plan, index2);
						}
			
			//Ouest
			if(f.lab.tab2D.tab[index1.x][index1.y-1] != MUR && f.lab.tab2D.tab[index1.x][index1.y-1] != VISITEE && (f.lab.tab2D.tab[index1.x][index1.y-1] == PASSAGE || f.lab.tab2D.tab[index1.x][index1.y-1] == MINOTAURE)){
							index2.x = index1.x;
							index2.y = index1.y-1;
							empiler(f.plan, index2);
						}

			//Sud
			if(f.lab.tab2D.tab[index1.x+1][index1.y] != MUR && f.lab.tab2D.tab[index1.x+1][index1.y] != VISITEE && (f.lab.tab2D.tab[index1.x+1][index1.y] == PASSAGE || f.lab.tab2D.tab[index1.x+1][index1.y] == MINOTAURE)){
							index2.y = index1.y;
							index2.x = index1.x+1;
							empiler(f.plan, index2);
						}			
		}

	}
	
	// Toutes las cases "visit�es" deviennent des cases "passage" ( suppression des 'V')
	
	for(unsigned int i=0 ; i < f.lab.tab2D.dimX; i++){
		for(unsigned j =0 ; j < f.lab.tab2D.dimY ; j++ ){
			if(f.lab.tab2D.tab[i][j] == VISITEE)
				f.lab.tab2D.tab[i][j] = PASSAGE;
		}
	}
	

	// Si le Minotaure se trouve sur la dernier case parcourue, Th�s�e est
	// victorieux, sinon il affiche sa deception. Dans tous les cas, le fil
	// d'Ariane est d�roul�

	if(f.lab.tab2D.tab[index1.x][index1.y] != MINOTAURE ){
		cout << "Deception" << endl;
		for(unsigned compt = 0; compt < longueur(f.chemin) ; compt ++){
			index1 = lire(f.chemin, compt);
			f.lab.tab2D.tab[index1.x][index1.y] = CHEMIN;
		}

		afficher(f.lab);
		return 0;
	}

	else{
		cout << " Victory !" << endl;
		for(unsigned compt = 0; compt < longueur(f.chemin) ; compt ++){
			index1 = lire(f.chemin, compt);
			f.lab.tab2D.tab[index1.x][index1.y] = CHEMIN;
		}
		f.lab.tab2D.tab[index1.x][index1.y] = THESEE;
		//afficher(f.lab);
		return 1;
	}
	
}
/**
 * brief
 * @see recherche
 * @param[in,out] fl : flux d'entr�e
*/
void enregistrer(ofstream& fl, const FilAriane2DGame& f){

	unsigned int X = f.lab.tab2D.dimX, Y = f.lab.tab2D.dimY, compt=0, j = 1;
	IndexPosition2D index;
	// On affcihe les dimenssions du labyrinthe
	fl  << X << "   " << Y << endl;
	// On affiche le labyrinthe caract�re par caract�re
	for(unsigned int i=0 ; i < X ; i++){
		for(unsigned j =0 ; j < Y ; j++ ){
			fl << (char)f.lab.tab2D.tab[i][j];
		}
		fl << endl;
	}

	fl << endl;
	// On affiche la longueur du fil d'Ariane
	fl << " Longueur du chemin :" << longueur(f.chemin) << endl;
	fl << endl;
	// On affiche les coordonn�es des cases du fil dAriane
	for(unsigned int i = longueur(f.chemin) ; i >= 1  ; i--){
		index = lire(f.chemin, i-1);
		fl << setw(2) <<"(" << setw(5) << index.y << "," << setw(5)  << index.x << ")";
		compt++;
		// Toutes les quatres coordonn�es on change de ligne
		if( compt == 5){
			fl << endl;
			compt = 0;	
		}
		
	}
	fl << endl;

}
