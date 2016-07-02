/**
 * @file Labyrinthe2D.h
 * Projet Labyrinthe
 * @author BURNER Whitney et DELERIN Maxime 
 * @version 1 30/12/2013
 * @brief Composant d'un labyrinthe à deux dimensions.
 * Structures de données et algorithmes - DUT1 Paris 5
 */

#ifndef LABYRINTHE2D_H_
#define LABYRINTHE2D_H_

#include <fstream>

#include "Tableau2D.h"
#include "IndexPosition2D.h"


/** Type Labyrinthe2D
 * Stockage du tableau contenant les éléments du labyrinthe
 * Repères de la position du minotaure et de l'entree du labyrinthe
*/
struct Labyrinthe2D{
	Tableau2D tab2D;
	IndexPosition2D entree;
	IndexPosition2D minotaure;
};

/** 
 * brief Initialisation d'un Labyrinthe2D vide
 * Le Labyrinthe2D est allouée en mémoire dynamique
 * @see detruire, le Labyrinthe2D est à désallouer en fin d’utilisation
 * @param[in,out] f : flux de sortie
 * @param[in,out] t : le Labyrinthe2D
*/
void initialiser(Labyrinthe2D& l, std::ifstream& f);

/** 
 * brief Desallocation d'un Labyrinthe2D 
 * @see initialiser, le Labyrinthe2D a deja été alloué en mémoire dynamique
 * @param[in,out] t : le Labyrinthe2D
*/
void detruire(Labyrinthe2D& l);

/** 
 * brief Affichage d'un Labyrinthe2D 
 * @see initialiser, le Labyrinthe2D a deja été alloué en mémoire dynamique
 * @param[in,out] t : le Labyrinthe2D
*/
void afficher (Labyrinthe2D& l);

#endif /* LABYRINTHE2D_H_ */
