/**
 * @file ConteneurTDE.cpp
* Projet Labyrinthe
 * @author BURNER Whitney et DELERIN Maxime
 * @version 1 30/12/2013
 * @brief Composant de conteneur d'items de capacité extensible
 * Structures de données et algorithmes - DUT1 Paris 5
 */
#include "stdafx.h"

#include <iostream>
#include <cassert>

using namespace std;

#include "ConteneurTDE.h"

/**
 * @brief Initialise un conteneur d'items
 * Allocation en mémoire dynamique du conteneur d'items
 * de capacité (capa) extensible par pas d'extension (p)
 * @see detruire, pour sa désallocation en fin d'utilisation 
 * @param[out] c : le conteneur d'IndexPosition2D
 * @param [in] capa : capacité du conteneur
 * @param [in] p : pas d'extension de capacité
 * @pre capa>0 et p>0
 */
void initialiser(ConteneurTDE& c, unsigned int capa, unsigned int p) {
	assert((capa>0) && (p>0));
	c.capacite = capa;
	c.pasExtension = p;
	// arrêt du programme en cas d'erreur d'allocation
	c.tab = new IndexPosition2D[capa];
	/* Affichage pour une trace de l'allocation en TP
	 * Affichage à supprimer après le test du conteneur */	
	//cout << "Allocation initiale de " << capa*sizeof(Item)
	// << " octets (" << capa << " IndexPosition2D(s))" << endl;
}

/**
 * @brief Désalloue un conteneur d'IndexPosition2D en mémoire dynamique
 * @see initialiser, le conteneur d'IndexPosition2D a déjà été alloué
 * @param[in,out] c : le conteneur d'IndexPosition2D
 */
void detruire(ConteneurTDE& c) {
	delete [] c.tab;
	c.tab = NULL;
}

/**
 * @brief Lecture d'un IndexPosition2D d'un conteneur d'items
 * @param[in] c : le conteneur d'IndexPosition2D
 * @param[in] i : la position de l'IndexPosition2D dans le conteneur
 * @return l'IndexPosition2D à la position i
 * @pre i < c.capacite   
 */
IndexPosition2D lire(const ConteneurTDE& c, unsigned int i) {
	assert(i < c.capacite);
	return c.tab[i];
}

/**
 * @brief Ecrire un item dans un conteneur d'items
 * @param[in,out] c : le conteneur d'items
 * @param[in] i : la position où ajouter/modifier l'item
 * @param[in] it : l'item à écrire 
 */
void ecrire(ConteneurTDE& c, unsigned int i, const IndexPosition2D& it) {
	if (i>=c.capacite) {
		/* Stratégie de réallocation proportionnelle au pas d'extension :
		 * initialisez la nouvelle taille du conteneur (newTaille) 
		 * à i * c.pasExtension */
		unsigned int newTaille = (i+1) * c.pasExtension;
		/* Allouez en mémoire dynamique un nouveau tableau (newT) 
		 * à cette nouvelle taille*/
		IndexPosition2D* newT = new IndexPosition2D[newTaille];
		/* Recopiez les items déjà stockés dans le conteneur */
    	for (unsigned int i = 0; i < c.capacite; ++i)
      		newT[i] = c.tab[i];
      	/* Désallouez l'ancien tableau support du conteneur */
    	delete [] c.tab;
    	/* Actualiser la mise à jour du conteneur en mémoire dynamique
    	 * Faites pointer le tableau support du conteneur 
    	 * sur le nouveau tableau en mémoire dynamique */
    	c.tab = newT;
    	/* Actualisez la taille du conteneur */
    	c.capacite = newTaille;
    		/* Affichage pour une trace de l'allocation en TP
	 	* En TP, pour tracer l'extension de l'allocation en mémoire,
	 	* affichez les informations qui suivent.
	 	* Cet affichage sera supprimé après le test du conteneur */	
		//cout << "Extension - Allocaton/Réallocation de " << newTaille*sizeof(Item) 
		// << " octets (" << newTaille << " items)." << endl;
	}
	/* Ecriture de l'IndexPosition2D (it) à la position i dans le conteneur */
	c.tab[i] = it;
}
