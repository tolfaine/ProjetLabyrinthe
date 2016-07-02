/**
 * @file FilAriane2DGame.h
 * Projet Labyrinthe
 * @author BURNER Whitney et DELERIN Maxime 
 * @version 1 30/12/2013
 * @brief Composant du jeu de role FilAriane.
 * Structures de données et algorithmes - DUT1 Paris 5
 */

#ifndef FILARIANE2DGAME_H_
#define FILARIANE2DGAME_H_

#include "Labyrinthe2D.h"
#include "Liste.h"
#include "Pile.h"

/** Type FilAriane2DGame
 * Stockage du labyrinthe2D
 * Planification de la recherche du minotaure
 * Repères du chemin de l'entréé du labyrinthe à Thésée
*/
struct FilAriane2DGame {
	Labyrinthe2D lab; // le labyrinthe
	Pile plan; // planification de la recherche
	Liste chemin; // chemin de l’entrée à Thésée
};

/**
 * brief Initialisation d'un FilAriane2DGame vide
 * @see detruire, le jeu FilAriane2DGame est à désallouer en fin d’utilisation
 * @param[in,out] fl : flux de sortie
 * @param[in,out] t : le jeu FilAriane2DGame

*/
void initialiser(FilAriane2DGame& f, ifstream& fl);

/**
 * brief Desallocation d'un jeu FilAriane2DGame
 * @see initialiser, le jeu FilAriane2DGame  a deja été alloué en mémoire dynamique
 * @param[in,out] f : le jeu FilAriane2DGame
*/
void detruire(FilAriane2DGame& f);

/**
 * brief Recherche du minotaure un jeu FilAriane2DGame
 * déroulement du jeu
 * @see initialiser, le jeu FilAriane2DGame  a deja été alloué en mémoire dynamique
 * @param[in,out] f : le jeu FilAriane2DGame
 * @param[in] e : L' IndexPosition2D de l'entrée du labyrinthe
*/
bool recherche(FilAriane2DGame& f,const IndexPosition2D& e);

/**
 * brief
 * @see recherche
 * @param[in,out] fl : flux d'entrée
*/
void enregistrer(ofstream& fl, const FilAriane2DGame& f);

#endif /* FILARIANE2DGAME_H_ */
