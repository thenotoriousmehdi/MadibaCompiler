#include "symbol_table.h"

// Déclaration de la table des symboles globale
table_symbol symbolTable;

// Initialisation de la table des symboles
void initTable() {
    symbolTable.base = 0;
    symbolTable.sommet = 0;
}

// Insertion d'un identifiant dans la table
int insertSymbol(const char *name, int classe, int type, int complement) {
    if (symbolTable.sommet >= MAX_DICO) {
        printf("Erreur : Table des symboles pleine !\n");
        return -1;
    }
    // Affichage des arguments insérés

    // desc_identif *entry = &symbolTable.tab[symbolTable.sommet++];
    // entry->identif = strdup(name); // Copie du nom
    // entry->classe = classe;
    // entry->type = type;
    // entry->valeur = valeur ? strdup(valeur) : NULL; // Copie de la valeur si elle existe
    // entry->complement = complement;

    symbolTable.tab[symbolTable.sommet].identif = strdup(name); // Copie du nom
    symbolTable.tab[symbolTable.sommet].classe = classe;
    symbolTable.tab[symbolTable.sommet].type = type;
   // symbolTable.tab[symbolTable.sommet].valeur = valeur ? strdup(valeur) : NULL; // Copie de la valeur si elle existe
    symbolTable.tab[symbolTable.sommet].complement = complement;

    symbolTable.sommet++;

    return 0;
}

// Recherche d'un identifiant dans la table
desc_identif* lookupSymbol(const char *name) {
    for (int i = symbolTable.sommet - 1; i >= symbolTable.base; i--) {
        if (strcmp(symbolTable.tab[i].identif, name) == 0) {
            return &symbolTable.tab[i]; // Retourne un pointeur vers l'objet trouvé
        }
    }
    return NULL; // Retourne NULL si l'identifiant n'existe pas
}

// Affichage de la table des symboles
void displayTable() {
    printf("Index\tIdentifiant\tClasse\tType\tComplément\n");
    for (int i = 0; i < symbolTable.sommet; i++) {
        desc_identif *entry = &symbolTable.tab[i];
        printf("%-8d %-16s %-6d %-8d %-5d\n", i, symbolTable.tab[i].identif, symbolTable.tab[i].classe, symbolTable.tab[i].type, 
               symbolTable.tab[i].complement);
    }
}
