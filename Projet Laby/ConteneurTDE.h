#ifndef _CONTENEUR_TDE_
#define _CONTENEUR_TDE_

/**
 * @file ConteneurTDE.h
 * Projet Labyrinthe
 * @author BURNER Whitney et DELERIN Maxime
 * @version 1 30/12/2013
 * @brief Composant d'un conteneur d'items de capacit� extensible
 * Structures de donn�es et algorithmes - DUT1 Paris 5
 */

#include "IndexPosition2D.h"

/** @brief Conteneur d'items allou�s en m�moire dynamique
 *  de capacit� extensible suivant un pas d'extension
 */ 
struct ConteneurTDE {
    unsigned int capacite; 	   // capacit� du conteneur (>0)
	unsigned int pasExtension; // pas d'extension du conteneur (>0)
	IndexPosition2D* tab;				   // conteneur allou� en m�moire dynamique
};

/**
 * @brief Initialise un conteneur d'items
 * Allocation en m�moire dynamique du conteneur d'IndexPosition2D
 * de capacit� (capa) extensible par pas d'extension (p)
 * @see detruire, pour sa d�sallocation en fin d'utilisation 
 * @param[out] c : le conteneur d'items
 * @param [in] capa : capacit� du conteneur
 * @param [in] p : pas d'extension de capacit�
 * @pre capa>0 et p>0
 */
void initialiser(ConteneurTDE& c, unsigned int capa, unsigned int p);

/**
 * @brief D�salloue un conteneur d'items en m�moire dynamique
 * @see initialiser, le conteneur d'items a d�j� �t� allou� 
 * @param[in,out] c : le conteneur d'items
 */
void detruire(ConteneurTDE& c); 

/**
 * @brief Lecture d'un item d'un conteneur d'IndexPosition2D
 * @param[in] c : le conteneur d'items
 * @param[in] i : la position de l'item dans le conteneur
 * @return l'item � la position i
 * @pre i < c.capacite   
 */
IndexPosition2D lire(const ConteneurTDE& c, unsigned int i);

/**
 * @brief Ecrire un IndexPosition2D dans un conteneur d'items
 * @param[in,out] c : le conteneur d'items
 * @param[in] i : la position o� ajouter/modifier l'item
 * @param[in] it : l'IndexPosition2D � �crire
 */
void ecrire(ConteneurTDE& c, unsigned int i, const IndexPosition2D& it);

#endif /*_CONTENEUR_TDE_*/
