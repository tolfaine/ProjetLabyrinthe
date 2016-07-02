/**
 * @file IndexPosition.h
 * Projet Labyrinthe
 * @author BURNER Whitney et DELERIN Maxime 
 * @version 1 30/12/2013
 * @brief Composant des index de position d'une case.
 * Structures de donn�es et algorithmes - DUT1 Paris 5
 */

#ifndef INDEXPOSITION2D_H_
#define INDEXPOSITION2D_H_


/** Type IndexPosition2D
 *  Rep�res de l'abscisse et de l'ordonn�e de la case
 */
struct IndexPosition2D{
	unsigned int x;
	unsigned int y;
};

/** 
 * brief Initialisation d'un IndexPosition2D vide
 * @see detruire, l' IndexPosition2D est � d�sallouer en fin d�utilisation
 * @param[in] i : entier positif �gal a 0 pour l'abscisse
 * @param[in] j : entier positif �gal a 0 pour les ordonnees
 * @param[in,out] index : l'IndexPosition2D
 
*/

void initialisation(IndexPosition2D& index, unsigned int i=0, unsigned int j=0);

/** 
 * brief Determination de la connexit� de deux IndexPosition2D 
 * @param[in] i1 : Le premier IndexPosition2D
 * @param[in] i2 : Le deuxieme IndexPosition2D
*/
bool estConnexe(const IndexPosition2D& i1, const IndexPosition2D& i2);

/** 
 * brief Affichage d'un IndexPositon2D a l'ecran
 * @param[in] index : l'IndexPosition2D a afficher
*/
void afficher( IndexPosition2D& index );
#endif /* INDEXPOSITION2D_H_ */
