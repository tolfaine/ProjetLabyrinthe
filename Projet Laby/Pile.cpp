/**
 * @file Pile.cpp
  Projet Labyrinthe
 * @author BURNER Whitney et DELERIN Maxime
 * @version 1 30/12/2013
 * @brief Composant de pile à capacité extensible
 * Structures de données et algorithmes - DUT1 Paris 5
 */
#include "stdafx.h"

#include <iostream>
#include <cassert>

#include "Pile.h"

/**
 * @brief Initialiser une pile vide
 * la pile est allouée en mémoire dynamique
 * @see detruire, pour une désallocation en fin d’utilisation
 * @param[out] p : la pile à initialiser
 * @param[in] c : capacité initiale de la pile
 * @param[in] pas : pas d'extension de la pile
 * @pre c>0 et pas >0
 */

void initialiser(Pile& p, unsigned int c, unsigned int pas) {
	assert((c>0) && (pas >0));
	initialiser(p.tab, c, pas);
	p.sommet = -1; 
}

/**
 * @brief Désallouer une pile
 * @see initialiser, la pile a déjà été initialisée
 * @param[in,out] p : la pile à désallouer
 */
void detruire(Pile& p) {
	detruire(p.tab);
}

/**
 * @brief Test de pile vide
 * @param[in] p : la pile testée
 * @return true si p est vide, false sinon
 */
bool estVide(const Pile& p) {
	return (p.sommet == -1);
}

/**
 * @brief Lire l'IndexPosition2D au sommet de pile
 * @param[in] p : la pile
 * @return la valeur de l'IndexPosition2D au sommet de pile
 * @pre la pile n’est pas vide
 */
IndexPosition2D sommet(const Pile& p) {
	assert(!estVide(p));
	return (lire(p.tab, p.sommet));
}

/**
 * @brief Empiler un IndexPosition2D sur une pile
 * @param[in,out] p : la pile
 * @param[in] it : l'IndexPosition2D à empiler
 * La précondition (@pre la pile n’est pas pleine) n'est pas utile 
 * en raison de l'extension automatique en mémoire dynamique 
 */
void empiler(Pile& p, const IndexPosition2D& it) {
	p.sommet++;
	ecrire(p.tab, p.sommet, it);
}

/**
 * @brief Dépiler l’IndexPosition2D au sommet de pile
 * @param[in,out] p : la pile
 * @pre la pile n’est pas vide
 */
void depiler(Pile& p) {
	assert(!estVide(p));
	p.sommet--;
}
