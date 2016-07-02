/**
 * @file Pile.cpp
  Projet Labyrinthe
 * @author BURNER Whitney et DELERIN Maxime
 * @version 1 30/12/2013
 * @brief main
 * Structures de données et algorithmes - DUT1 Paris 5
 */

#include "stdafx.h"
#include <iostream>
#include <fstream>

using namespace std;

#include "FilAriane2DGame.h"

int main(){
	char nom[100];
	FilAriane2DGame fil;
	const IndexPosition2D e;
	ifstream f ;
	ofstream fe;

	cout << " Entrez le nom du labyrinthe" << endl;
	cin >> nom;
	f.open(nom, ios_base::in);
	if( !f ){

		cerr << " Impossible de lire le labyrinthe \n " ;
		return 0;
	}
	else{
		// Initialisation du jeu FilAriane2DGame a partir du fichier
		initialiser(fil, f);
		// Recherche du minotaure
		recherche(fil,fil.lab.entree);
		// Fermeture du flot de lecture
		f.close();
		cout << endl << "saisissez le nom du ficher qui contiendra la solution : ";
		cin >> nom;
		// Création d'un fichier
		fe.open(nom,ios::out);
		if(!fe){
		cerr << " Impossible d'ouvrir le fichier \n " ;


		}
		else{
			// On enregistre le resultat du jeu
			enregistrer(fe, fil);
			// Fermeture du flot d'Ecriture
			f.close();
			

		}
		detruire(fil);
		return 0;
	}
}

