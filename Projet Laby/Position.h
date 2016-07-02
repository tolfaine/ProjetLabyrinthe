#ifndef _POSITION_
#define _POSITION_

/**
 * @file Position.h
 * Projet sem04-tp-Cpp3
 * @author l'�quipe p�dagogique 
 * @version 1 19/12/05
 * @brief Composant de positions sur une grille
 * Structures de donn�es et algorithmes - DUT1 Paris 5
 */
 
/**
 * @brief Type position
 * invariant : la position doit �tre valide
*/
struct Position {
	unsigned int abscisse; // abscisse de la position
	unsigned int ordonnee; // ordonn�e de la position
};

/**
 * @brief Saisie d'une position valide
 * @return la position saisie
 */
 Position saisir();
 
/**
 * @brief Affichage d'une position
 * @param[in] p : la position � afficher
 */
void afficher(const Position& p);

#endif

