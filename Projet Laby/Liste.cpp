/**
 * @file Liste.cpp
  Projet Labyrinthe
 * @author BURNER Whitney et DELERIN Maxime
 * @version 1 30/12/2013
 * @brief Composant de liste en mémoire dynamique et extensible
 * Structures de données et algorithmes - DUT1 Paris 5
 */
#include "stdafx.h"

#include <cassert> 
#include "Liste.h"

/**
 * @brief Initialiser une liste vide
 * la liste est allouée en mémoire dynamique
 * @see detruire, la liste est à désallouer en fin d’utilisation
 * @param[out] l : la liste à initialiser
 * @param[in] capa : capacité de la liste
 * @param[in] pas : pas d’extension de la liste
 * @pre capa>0 et pas>0
 */
void initialiser(Liste& l, unsigned int capa, unsigned int pas) {
	assert ((capa>0) && (pas>0));
	initialiser(l.c, capa, pas);
	l.nb=0;
}
 
/**
 * @brief Désallouer une liste
 * @see initialiser, la liste a déjà été allouée en mémoire dynamique
 * @param[out] l : la liste
 */
void detruire(Liste& l) {
	detruire(l.c);
}

/**
 * @brief Longueur de liste
 * @param[in] l : la liste
 * @return la longueur de la liste
 */
unsigned int longueur(const Liste& l) {
	return l.nb;
}

/**
 * @brief Lire un élément de liste
 * @param[in] l : la liste
 * @param[in] pos : position de l'élément à lire
 * @return l'item lu en position pos
 * @pre 0<=pos<longueur(l)
 */
IndexPosition2D lire(const Liste& l, unsigned int pos) {
	assert(pos<l.nb);
	return lire(l.c, pos);
}

/**
 * @brief Ecrire un IndexPosition2D dans la liste
 * @param[in,out] l : la liste
 * @param[in] pos : position de l'élément à écrire
 * @param[in] it : l'IndexPosition2D
 * @pre 0<=pos<longueur(l)
*/
void ecrire(Liste& l, unsigned int pos, const IndexPosition2D& it) {
	assert(pos<=l.nb);
	ecrire(l.c, pos, it);
}	

/**
 * @brief Insérer un élément dans une liste
 * @param[in,out] l : la liste
 * @param[in] pos : la position à laquelle l'élément est inséré
 * @param[in] it : l'élément inséré
 * @pre 0<=pos<=longueur(l)
 * l’insertion est faite avant la position pos
 */
void inserer(Liste& l, unsigned int pos, const IndexPosition2D& it) {
	assert(pos<=l.nb);
	for (unsigned int i=l.nb; i>pos; i--) {
		ecrire(l.c, i, lire(l.c, i-1));
	}
	ecrire(l.c, pos, it);
	l.nb++;
}

/**
 * @brief Supprimer un élément dans une liste
 * @param[in,out] l : la liste
 * @param[in] pos : la position de l'élément à supprimer
 * @pre longueur(l)>0 et 0<=pos<longueur(l)
 */
void supprimer(Liste& l, unsigned int pos) {
	assert((l.nb!=0) && (pos<l.nb));
	l.nb--;
	for (unsigned int i=pos; i<l.nb; ++i)
	   ecrire(l.c, i, lire(l.c,i+1));
}

