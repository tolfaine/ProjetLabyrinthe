/**
 * @file ConteneurTDE.cpp
* Projet Labyrinthe
 * @author BURNER Whitney et DELERIN Maxime
 * @version 1 30/12/2013
 * @brief Composant de conteneur d'items de capacit� extensible
 * Structures de donn�es et algorithmes - DUT1 Paris 5
 */
#include "stdafx.h"

#include <iostream>
#include <cassert>

using namespace std;

#include "ConteneurTDE.h"

/**
 * @brief Initialise un conteneur d'items
 * Allocation en m�moire dynamique du conteneur d'items
 * de capacit� (capa) extensible par pas d'extension (p)
 * @see detruire, pour sa d�sallocation en fin d'utilisation 
 * @param[out] c : le conteneur d'IndexPosition2D
 * @param [in] capa : capacit� du conteneur
 * @param [in] p : pas d'extension de capacit�
 * @pre capa>0 et p>0
 */
void initialiser(ConteneurTDE& c, unsigned int capa, unsigned int p) {
	assert((capa>0) && (p>0));
	c.capacite = capa;
	c.pasExtension = p;
	// arr�t du programme en cas d'erreur d'allocation
	c.tab = new IndexPosition2D[capa];
	/* Affichage pour une trace de l'allocation en TP
	 * Affichage � supprimer apr�s le test du conteneur */	
	//cout << "Allocation initiale de " << capa*sizeof(Item)
	// << " octets (" << capa << " IndexPosition2D(s))" << endl;
}

/**
 * @brief D�salloue un conteneur d'IndexPosition2D en m�moire dynamique
 * @see initialiser, le conteneur d'IndexPosition2D a d�j� �t� allou�
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
 * @return l'IndexPosition2D � la position i
 * @pre i < c.capacite   
 */
IndexPosition2D lire(const ConteneurTDE& c, unsigned int i) {
	assert(i < c.capacite);
	return c.tab[i];
}

/**
 * @brief Ecrire un item dans un conteneur d'items
 * @param[in,out] c : le conteneur d'items
 * @param[in] i : la position o� ajouter/modifier l'item
 * @param[in] it : l'item � �crire 
 */
void ecrire(ConteneurTDE& c, unsigned int i, const IndexPosition2D& it) {
	if (i>=c.capacite) {
		/* Strat�gie de r�allocation proportionnelle au pas d'extension :
		 * initialisez la nouvelle taille du conteneur (newTaille) 
		 * � i * c.pasExtension */
		unsigned int newTaille = (i+1) * c.pasExtension;
		/* Allouez en m�moire dynamique un nouveau tableau (newT) 
		 * � cette nouvelle taille*/
		IndexPosition2D* newT = new IndexPosition2D[newTaille];
		/* Recopiez les items d�j� stock�s dans le conteneur */
    	for (unsigned int i = 0; i < c.capacite; ++i)
      		newT[i] = c.tab[i];
      	/* D�sallouez l'ancien tableau support du conteneur */
    	delete [] c.tab;
    	/* Actualiser la mise � jour du conteneur en m�moire dynamique
    	 * Faites pointer le tableau support du conteneur 
    	 * sur le nouveau tableau en m�moire dynamique */
    	c.tab = newT;
    	/* Actualisez la taille du conteneur */
    	c.capacite = newTaille;
    		/* Affichage pour une trace de l'allocation en TP
	 	* En TP, pour tracer l'extension de l'allocation en m�moire,
	 	* affichez les informations qui suivent.
	 	* Cet affichage sera supprim� apr�s le test du conteneur */	
		//cout << "Extension - Allocaton/R�allocation de " << newTaille*sizeof(Item) 
		// << " octets (" << newTaille << " items)." << endl;
	}
	/* Ecriture de l'IndexPosition2D (it) � la position i dans le conteneur */
	c.tab[i] = it;
}
