#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "pile.h"

void initPile(pile *P){

    P->sommet = -1;
}
 


 void  empiler(pile *p, int valeur) {
    if (estPleine(p)) {
        printf("Erreur : La pile est pleine.\n");
       
    }
    p->sommet++;
    p->table[p->sommet] = valeur;
   
}

// Dépile un élément de la pile
int depiler(pile *p) {
    if (estVide(p)) {
        printf("Erreur : La pile est vide.\n");
        return -1;  // Valeur spéciale pour indiquer une erreur
    }
    return p->table[p->sommet--];  // Retourne la valeur et décrémente le sommet
}

int estVide(pile *p) {
    return p->sommet == -1;
}

// Vérifie si la pile est pleine
int estPleine(pile *p) {
    return p->sommet == MAX - 1;
}
