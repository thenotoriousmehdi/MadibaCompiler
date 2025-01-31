#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Définitions des classes
#define T_UNKNOWN 0         // Inconnu
#define C_CONST 1       // Constante
#define C_VAR 2         // Variable
#define C_TYPE 3        // Type utilisateur (enum, object, ARRAY.)
#define C_LOCAL 4       // Variable locale
#define C_ARGUMENT 5    // Argument d'une fonction
#define C_CHAMP 6    // Argument d'une fonction
#define C_ARRAY 7      // Tableau
int insertSymbol(const char *name, int classe, int type, int complement);
// Définitions des types
#define T_INT 1         // Type entier
#define T_FLOAT 2       // Type flottant
#define T_BOOL 3        // Type booléen
#define T_CHAR 4        // Type caractère
#define T_STRING 5      // Type chaîne de caractères
#define T_OBJECT 7      // Objet (structure utilisateur)
#define T_ENUM 8        // Enumération
#define T_FUNCTION 9    // Fonction

// Taille maximale de la table
#define MAX_DICO 1000

// Description d'un identifiant
typedef struct {
    char *identif;   // Nom de l'identifiant
    int classe;      // Classe ( locale, argument)
    int type;        // Type (int, float, bool ... 
    // char *valeur;    // Valeur associée 
    int complement;  // Complément (taille pour les tableaux, nb de paramètres pour les fonctions, etc.)
} desc_identif;

// Structure de la table des symboles
typedef struct {
    desc_identif tab[MAX_DICO]; // Tableau des identifiants
    int base;                   
    int sommet;                 // Indice du sommet de la pile
} table_symbol;

// Déclaration de la table des symboles globale
extern table_symbol symbolTable;

// Initialisation de la table des symboles
void initTable();

// Insertion d'un identifiant dans la table
int insertSymbol(const char *name, int classe, int type, int complement);

// Recherche d'un identifiant dans la table
desc_identif* lookupSymbol(const char *name);

// Affichage de la table des symboles
void displayTable();

#endif // SYMBOL_TABLE_H
