
/**
 * @file Tableau2D.h
 * Projet Labyrinthe
 * @author BURNER Whitney et DELERIN Maxime 
 * @version 1 30/12/2013
 * @brief Composant de tableau à deux dimensions.
 * Structures de données et algorithmes - DUT1 Paris 5
 */

#ifndef TABLEAU2D_H_
#define TABLEAU2D_H_

#include "Item2D.h"

/** Type Tableau2D
 * Stockage des éléments du labyrinthe dans un tableau de pointeurs sur pointeurs
 * Repères des dimensions du tableau à deux dimensions
*/
struct Tableau2D{
	Item2D** tab;
	unsigned int dimX;
	unsigned int dimY;
};

/** 
 * brief Initialisation d'un Tableau2D vide
 * Le Tableau2D est allouée en mémoire dynamique
 * @see detruire, le Tableau2D est à désallouer en fin d’utilisation
 * @param[in] dimX : dimension horizontale du tableau
 * @param[in] dimY : dimension verticale du tableau
 * @param[in,out] t : le Tableau2D
 */
void initialiser(Tableau2D& t, unsigned int dimX, unsigned dimY );

/** 
 * brief Desallocation d'un Tableau2D
 * @see initialiser, le Tableau2D a deja été alloué en mémoire dynamique
 * @param[in,out] t : le Tableau2D
 */
void detruire(Tableau2D& t);


/** 
 * brief Affichage d'un Tableau2D plein
 * @see initialiser, le Tableau2D a deja été alloué en mémoire dynamique
 * @param[in,out] t : le Tableau2D
 */
void afficher(Tableau2D& t);

#endif /* TABLEAU2D_H_ */
