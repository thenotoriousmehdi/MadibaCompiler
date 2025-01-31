#ifndef GRAMMAR_H
#define GRAMMAR_H
#define MAX_PILE 100

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>


#define MAX 100
#define MAX_LINES 100       // Nombre maximal de lignes
#define MAX_TOKENS_PER_LINE 100 // Nombre maximal de tokens par ligne
#define MAX_TER 20
#define MAX_NT 20




int top = 0;
int nb_ter, nb_noter, chaine, nb_regle, count; // compteurs
char DEBUT[MAX][MAX], SUIVANT[MAX][MAX]; //ensembles DEBUT et SUIVANT
char TER[MAX], NOTER[MAX], GRAMMAIRE[MAX][MAX], PILE[MAX];
int table_analyse_ll1[MAX][MAX];


// Fonction pour vérifier la récursion à gauche dans la grammaire
void verifier_recursion_gauche() {
    printf("\nVérification de la récursion à gauche...\n");

    // Parcourir chaque règle de production
    for (int i = 0; i < nb_regle; i++) {
        char symbole_non_terminal = GRAMMAIRE[i][0];  // Le symbole non terminal de la règle
        char *cote_droit_production = GRAMMAIRE[i] + 3;  // Le côté droit de la règle (en ignorant "NonTerminal->")

        // Vérifier si le premier symbole du côté droit est le même que le non-terminal
        if (cote_droit_production[0] == symbole_non_terminal) {
            printf("Récursion à gauche détectée dans la règle : %s\n", GRAMMAIRE[i]);
            printf(">> La règle %c -> %s contient une récursion à gauche.\n", symbole_non_terminal, cote_droit_production);
            return;
        }
    }

    printf(">> Aucune récursion à gauche détectée.\n");
}


void removeSpaces(char *str) {
    int i, j = 0;
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ') { // Skip spaces
            str[j++] = str[i];
        }
    }
    str[j] = '\0'; // Null-terminate the string
}


void analyseur_ll1(char *STR) {
    if (STR == NULL) {
        printf("Erreur : La chaîne d'entrée est NULL.\n");
        return;
    }

    int i = 0, j, pos = -1, pos1 = -1, n, k;
    int foundAction = 0;

    // Allouer de la mémoire pour une copie de la chaîne avec le symbole de fin
    char *input = (char *)malloc(strlen(STR) + 2);
    if (input == NULL) {
        printf("Erreur : Échec de l'allocation mémoire.\n");
        return;
    }
    strcpy(input, STR);
    strcat(input, "#");

    // ---------------------------------------------------//
    // ---------------------------------------------------//


    // Initialiser la pile avec le symbole de départ et le symbole de fin
    PILE[++top] = '#';
    PILE[++top] = GRAMMAIRE[0][0];// l'axiome Z dans la pile 

    printf("\nSéquence d'analyse et actions\n\n");
    printf("PILE\t\t\tRESTE DE LA CHAINE\t\t\tACTION");
    printf("\n------------------------------------------------------------------------------------\n");

    while (top >= 0 && PILE[top] != '#') {
        // Afficher la pile actuelle
        for (j = 0; j <= top; j++) {
            printf("%c", PILE[j]);
        }
        printf("\t\t\t");

        // Afficher la chaîne restante
        for (j = i; input[j] != '\0'; j++) {
            printf("%c", input[j]);
        }

        foundAction = 0; // Réinitialiser l'indicateur d'action
         
        if (input[i] == PILE[top]) {
            // Correspondance trouvée, retirer le symbole de la pile et avancer dans la chaîne
            // avancer 
            printf("\t\t\t %c", PILE[top]);
            top--;
            i++;
            foundAction = 1;
        } else {
             
            // Trouver les positions dans NOTER 
            for (j = 0; j < nb_noter; j++) {
                if (PILE[top] == NOTER[j]) {
                    pos = j;
                    break;
                }
            }
           // Trouver la position de terminal 
            for (j = 0; j < nb_ter; j++) {
                if (input[i] == TER[j]) {
                    pos1 = j;
                    break;
                }
            }

            if (pos == -1 || pos1 == -1) {
                printf("\t\t\tERREUR SYNTAXIQUE : Symbole non trouvé\n");
                break;
            }

           // on cherche la regle  dans la table danalyse 
            n = table_analyse_ll1[pos][pos1];
            if (n >= 0) {
                if (GRAMMAIRE[n][3] == '!') {
                    // Production vide : retirer le sommet de la pile
                    top--;
                } else {
                    top = top-1;
                    // Ajouter les symboles de la production à la pile
                    for (k = strlen(GRAMMAIRE[n]) - 1; k > 2; k--) {
                        if (top + 1 < MAX) {
                            PILE[++top] = GRAMMAIRE[n][k];
                        } else {
                            printf("\t\t\tERREUR : Dépassement de la pile\n");
                            free(input);
                            return;
                        }
                    }
                }
                printf("\t\t\t %s", GRAMMAIRE[n]);
                foundAction = 1;
            }
        }

        if (!foundAction) {
            printf("\t\t\tERREUR SYNTAXIQUE : Aucune action trouvée\n");
            break;
        }
        // Vider la pile
        printf("\n");
    }



// ------------------------------ affichage ----------------


    // Affichage final
    for (j = 0; j <= top; j++) {
        printf("%c", PILE[j]);
    }
    printf("\t\t");

    for (j = i; input[j] != '\0'; j++) {
        printf("%c", input[j]);
    }

    printf("\n");

    if (PILE[top] == '#' && input[i] == '#') {
        printf("\nAnalyse terminée avec succès\n");
    } else {
        printf("\nErreur syntaxique\n");
    }

    free(input); // Libérer la mémoire allouée
    while (top >= 0) {
        PILE[top--] = '\0';
    }
}



// Fonction pour vérifier si un symbole est déjà présent dans un tableau
int containsss(char *arr, char ch) {
    int i;
    for (i = 0; arr[i] != '\0'; i++) {
        if (arr[i] == ch) {
            return 1;  // Symbole déjà présent
        }
    }
    return 0;  // Symbole non présent
}


void afficher_grammaire() {
    printf("Grammaire :\n");
    for (int i = 0; i < nb_regle; i++) {
        printf("%s\n",GRAMMAIRE[i]);
    }
}

// Fonction d'affichage des ensembles DEBUT
void affich_debut() {
    int i, j;
    char arr[MAX];
    for (i = 0; i < nb_noter; i++) {
        arr[0] = '\0';
        count = 0; // réinitialisation du compteur
        calculer_debut(arr, NOTER[i]);  // Trouver l'ensemble DEBUT pour chaque non-terminal
        for (j = 0; arr[j] != '\0'; j++) {
            DEBUT[i][j] = arr[j];  // Sauvegarder l'ensemble DEBUT
        }
        DEBUT[i][j] = '\0';  // Assurer que le tableau est bien terminé par '\0'
    }
    printf("\n*************** ENSEMBLE DES DEBUTS ***************\n\n");
    for (i = 0; i < nb_noter; i++) {
        printf("DEBUT( %c ): { ", NOTER[i]);
        for (j = 0; DEBUT[i][j + 1] != '\0'; j++) {
            printf(" %c,", DEBUT[i][j]);
        }
        printf(" %c }", DEBUT[i][j]);
        printf("\n");
    }
}

// Fonction d'affichage des ensembles SUIVANT pour chaque non-terminal
void affich_suivant() {
    int i, j;
    char arr[MAX];
    for (i = 0; i < nb_noter; i++) {
        arr[0] = '\0';
        count = 0;  // réinitialisation du compteur
        calculer_suivant(arr, NOTER[i]);  // Trouver l'ensemble SUIVANT pour chaque non-terminal
        for (j = 0; arr[j] != '\0'; j++) {
            SUIVANT[i][j] = arr[j];  // Sauvegarder l'ensemble SUIVANT
        }
        SUIVANT[i][j] = '\0';  // Assurer que le tableau est bien terminé par '\0'
    }
    printf("\n*************** ENSEMBLE DES SUIVANTS ***************\n\n");
    for (i = 0; i < nb_noter; i++) {
        printf("SUIVANT( %c ): { ", NOTER[i]);
        for (j = 0; SUIVANT[i][j + 1] != '\0'; j++) {
            printf(" %c,", SUIVANT[i][j]);
        }
        printf(" %c }", SUIVANT[i][j]);
        printf("\n");
    }
}

// Fonction de recherche de l'ensemble DEBUT pour un non-terminal
void calculer_debut(char *arr, char ch) {
    int i, j;
    // Si le caractère est un terminal, l'ajouter directement dans arr
    if (!isupper(ch)) {
        if (!containsss(arr, ch)) {
            arr[count++] = ch;
            arr[count] = '\0';
        }
    } else {
        // Si c'est un non-terminal, chercher dans les règles
        for (i = 0; i < nb_regle; i++) {
            if (ch == GRAMMAIRE[i][0]) {
                if (GRAMMAIRE[i][3] == '!') {
                    if (!containsss(arr, GRAMMAIRE[i][3])) {
                        arr[count++] = GRAMMAIRE[i][3];
                        arr[count] = '\0';
                    }
                } else {
                    calculer_debut(arr, GRAMMAIRE[i][3]);
                }
            }
        }
    }
}

// Fonction de recherche de l'ensemble SUIVANT pour un non-terminal
void calculer_suivant(char arr[], char ch) {
    int i, j, k, l, fl = 1, flag = 1;
    // Si le non-terminal est l'axiome, ajouter le symbole de fin de chaîne
    if (ch == GRAMMAIRE[0][0]) {
        if (!containsss(arr, '#')) {
            arr[count++] = '#';
            arr[count] = '\0';
        }
    }
    for (i = 0; i < nb_regle; i++) {
        for (j = 3; GRAMMAIRE[i][j] != '\0' && flag == 1; j++) {
            if (ch == GRAMMAIRE[i][j]) {
                flag = 0;
                // Si le prochain caractère est un non-terminal, traiter son DEBUT
                if (GRAMMAIRE[i][j + 1] != '\0' && isupper(GRAMMAIRE[i][j + 1])) {
                    for (k = 0; k < nb_noter; k++) {
                        if (GRAMMAIRE[k][0] == GRAMMAIRE[i][j + 1]) {
                            for (l = 0; DEBUT[k][l] != '\0'; l++) {
                                if (DEBUT[k][l] != '\0' && DEBUT[k][l] != '!' && !containsss(arr, DEBUT[k][l])) {
                                    arr[count++] = DEBUT[k][l];
                                    arr[count] = '\0';
                                }
                                if (DEBUT[k][l] == '!') {
                                    fl = 0;
                                }
                            }
                            break;
                        }
                    }
                }
                // Si le prochain caractère est un terminal, l'ajouter directement
                else if (GRAMMAIRE[i][j + 1] != '\0' && !isupper(GRAMMAIRE[i][j + 1])) {
                    if (!containsss(arr, GRAMMAIRE[i][j + 1])) {
                        arr[count++] = GRAMMAIRE[i][j + 1];
                        arr[count] = '\0';
                    }
                }
                // Si on arrive à la fin de la règle, appliquer la règle de suivi
                if ((GRAMMAIRE[i][j + 1] == '\0' || fl == 0) && GRAMMAIRE[i][0] != ch) {
                    fl = 1;
                    calculer_suivant(arr, GRAMMAIRE[i][0]);
                }
            }
        }
    }
}

// Fonction pour vérifier la factorisation dans la grammaire
void verifier_factorisation() {
    printf("\nVérification de la factorisation...\n");

    // Parcourir chaque règle de production
    for (int i = 0; i < nb_regle; i++) {
        for (int j = i + 1; j < nb_regle; j++) {
            // Si le côté gauche des deux règles est le même, on vérifie la factorisation
            if (GRAMMAIRE[i][0] == GRAMMAIRE[j][0] && GRAMMAIRE[i][3] == GRAMMAIRE[j][3]) {
                printf("La règle %s et %s doivent être factorisées.\n", GRAMMAIRE[i], GRAMMAIRE[j]);
            }
        }
    }
}


// Fonction pour vérifier l'intersection des ensembles DEBUT des productions
void verif_intersection_debuts() {
    printf("\nVérification de l'intersection des debuts... \n");

    for (int i = 0; i < nb_noter; i++) { // Parcourir tous les non-terminaux
        printf("\nNon-terminal : %c\n", NOTER[i]);

        char first_sets[MAX][MAX] = {{'\0'}}; // Ensemble DEBUT pour chaque production
        int count = 0; // Nombre de productions pour le non-terminal NOTER[i]

        // Parcourir toutes les règles de grammaire
        for (int j = 0; j < nb_regle; j++) {
            if (GRAMMAIRE[j][0] == NOTER[i]) { // Règle concernant NOTER[i]
                char temp_first[MAX] = {'\0'};

                // Calcul du DEBUT de la production (partie droite)
                int k = 3; // Ignorer le "X->" initial (la partie gauche)
                while (GRAMMAIRE[j][k] != '\0') {
                    if (GRAMMAIRE[j][k] != '!') {  // Si ce n'est pas epsilon
                        if (isupper(GRAMMAIRE[j][k])) {
                            strncat(temp_first, DEBUT[GRAMMAIRE[j][k]],1);
                        } else {
                            // Sinon, ajouter le symbole directement à l'ensemble DEBUT
                            strncat(temp_first, &GRAMMAIRE[j][k], 1);
                        }
                        break;  // On prend seulement le premier symbole (qui n'est pas epsilon)
                    }
                }

                // Sauvegarder le DEBUT calculé pour cette production
                strcpy(first_sets[count++], temp_first);
            }
        }

        // Vérifier les intersections des debuts des productions ayant le même non-terminal
        int conflict = 0;
        for (int p = 0; p < count; p++) {
            for (int q = p + 1; q < count; q++) {
                // Comparer les ensembles DEBUT des productions p et q
                for (int k = 0; first_sets[p][k] != '\0'; k++) {
                    // Si un symbole dans first_sets[p] est trouvé dans first_sets[q], il y a intersection
                    if (strchr(first_sets[q], first_sets[p][k]) != NULL) {
                        printf("Conflit détecté entre les productions %c -> %s et %c -> %s\n", 
                               NOTER[i], GRAMMAIRE[q]+3, NOTER[i], first_sets[p]);
                        conflict = 1;
                        break;
                    }
                }
                if (conflict) break;
            }
            if (conflict) break;
        }

        if (!conflict) {
            printf(">> Aucun conflit trouvé pour %c.\n", NOTER[i]);
        }
    }
}


int creer_table_analyse() {
    // Initialiser la table avec -1
    for(int i = 0; i < MAX; i++) {
        for(int j = 0; j < MAX; j++) {
            table_analyse_ll1[i][j] = -1;
        }
    }

    // Pour chaque règle
    for(int i = 0; i < nb_regle; i++) {
        char non_terminal = GRAMMAIRE[i][0];
        int index_nt = -1;
        
        // Trouver l'index du non-terminal DANS LA TABLE DES NOMS TERMINAL 
        for(int k = 0; k < nb_noter; k++) {
            if(NOTER[k] == non_terminal) {
                index_nt = k;
                break;
            }
        }
        
        if(index_nt == -1) continue;

        // // Si c'est une règle epsilon
        // if(strlen(GRAMMAIRE[i]) == 4 && GRAMMAIRE[i][3] == '!') {
        //     for(int k = 0; k < strlen(SUIVANT[index_nt]); k++) {
        //         char suivant = SUIVANT[index_nt][k];
        //         for(int l = 0; l < nb_ter; l++) {
        //             if(TER[l] == suivant) {
        //                 table_analyse_ll1[index_nt][l] = i;
        //                 break;
        //             }
        //         }
        //     }
        //     continue;
        // }

        // Pour les règles non-epsilon
        char first_symbol = GRAMMAIRE[i][3];
        
        // Si commence par un terminal , on va l'affecter dans la table 
        if(!isupper(first_symbol)) {
            // on cherche l'indice du non teminal et on l'affecte 
            for(int k = 0; k < nb_ter; k++) {
                if(TER[k] == first_symbol) {
                    table_analyse_ll1[index_nt][k] = i; // cette ligne 
                    break;
                }
            }
        } 
        // Si commence par un non-terminal , on va chercher l'indice de non terminal
        else {
            int first_nt_index = -1;
            for(int k = 0; k < nb_noter; k++) {
                if(NOTER[k] == first_symbol) {
                    first_nt_index = k;
                    break;
                }
            }
            // on cherche les debuts de non terminal trouver 
            for(int k = 0; k < strlen(DEBUT[first_nt_index]); k++) {
                char terminal = DEBUT[first_nt_index][k];
                for(int l = 0; l < nb_ter; l++) {
                    if(TER[l] == terminal) {
                        table_analyse_ll1[index_nt][l] = i;
                        break;
                    }
                }
            }
        }
    }
    return 1;
}


void affich_table_analyse(int success) {
    if(!success) {
        printf("\nLa grammaire n'est pas LL(1)\n");
        return;
    }
    
    printf("\n*************** TABLE D'ANALYSE LL(1) ***************\n\n");
    printf("    ");
    for(int i = 0; i < nb_ter; i++) {
        printf("%c  ", TER[i]);
    }
    printf("\n");
    
    for(int i = 0; i < nb_noter; i++) {
        printf("%c   ", NOTER[i]);
        for(int j = 0; j < nb_ter; j++) {
            if(table_analyse_ll1[i][j] == -1) {
                printf("-  ");
            } else {
                printf("%d  ", table_analyse_ll1[i][j]);
            }
        }
        printf("\n");
    }
}


void chack_Ll1_condition(){
    verifier_recursion_gauche();
    verifier_factorisation();
    affich_debut();  
    affich_suivant();
    verif_intersection_debuts();

}



#endif