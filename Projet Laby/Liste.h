#ifndef _LISTE_
#define _LISTE_

/**
 * @file Liste.h
  Projet Labyrinthe
 * @author BURNER Whitney et DELERIN Maxime
 * @version 1 30/12/2013
 * @brief Composant de liste en m�moire dynamique et extensible
 * Structures de donn�es et algorithmes - DUT1 Paris 5
 */

#include "ConteneurTDE.h"

struct Liste {
	ConteneurTDE c;		// tableau m�morisant les �l�ments de la liste
    unsigned int nb;	// nombre d'�l�ments stock�s dans la liste
};

/**
 * @brief Initialiser une liste vide
 * la liste est allou�e en m�moire dynamique
 * @see detruire, la liste est � d�sallouer en fin d�utilisation
 * @param[out] l : la liste � initialiser
 * @param[in] capa : capacit� de la liste
 * @param[in] pas : pas d�extension de la liste
 * @pre capa>0 et pas>0
 */
void initialiser(Liste& l, unsigned int capa, unsigned int pas);

/**
 * @brief D�sallouer une liste
 * @see initialiser, la liste a d�j� �t� allou�e en m�moire dynamique
 * @param[out] l : la liste
 */
void detruire(Liste& l);

/**
 * @brief Longueur de liste
 * @param[in] l : la liste
 * @return la longueur de la liste
 */
unsigned int longueur(const Liste& l);

/**
 * @brief Lire un �l�ment de liste
 * @param[in] l : la liste
 * @param[in] pos : position de l'�l�ment � lire
 * @return l'item lu en position pos
 * @pre 0<=pos<longueur(l)
 */
IndexPosition2D lire(const Liste& l, unsigned int pos);

/**
 * @brief Ecrire un IndexPosition2D dans la liste
 * @param[in,out] l : la liste
 * @param[in] pos : position de l'�l�ment � �crire
 * @param[in] it : l'IndexPosition2D
 * @pre 0<=pos<longueur(l)
*/
void ecrire(Liste& l, unsigned int pos, const IndexPosition2D& it);

/**
 * @brief Ins�rer un �l�ment dans une liste
 * @param[in,out] l : la liste
 * @param[in] pos : la position � laquelle l'�l�ment est ins�r�
 * @param[in] it : l'�l�ment ins�r�
 * @pre 0<=pos<=longueur(l)
 * l�insertion est faite avant la position pos
 */
void inserer(Liste& l, unsigned int pos, const IndexPosition2D& it);

/**
 * @brief Supprimer un �l�ment dans une liste
 * @param[in,out] l : la liste
 * @param[in] pos : la position de l'�l�ment � supprimer
 * @pre longueur(l)>0 et 0<=pos<longueur(l)
 */
void supprimer(Liste& l, unsigned int pos);

#endif
