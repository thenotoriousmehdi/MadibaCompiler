%{
#include <stdio.h>
#include <string.h>
#include "tableau.h"

#define MAX_LINES 100       // Nombre maximal de lignes
#define MAX_TOKENS_PER_LINE 100 // Nombre maximal de tokens par ligne
#define MAX 100

char tokens_table[MAX_LINES][MAX_TOKENS_PER_LINE][50]; // Table 2D pour stocker les tokens
int current_line = 0;       // Ligne courante dans la table
int current_token = 0;      // Token courant dans la ligne


void callToFakeMain(){
    NOTER[0] = 'Z'; // Symbole de départ
    NOTER[1] = 'S'; // Symbole S
    NOTER[2] = 'D'; // Symbole D
    NOTER[3] = 'A'; // Symbole A
    NOTER[4] = 'V'; // Symbole V
    nb_noter = 5;   // Nombre de non-terminaux

    // Terminaux
    TER[0] = 't';   // Symbole terminal 'type'
    TER[1] = 'd';   // Symbole terminal 'identidiant'
    TER[2] = '=';   // Symbole terminal '='
    TER[3] = 'n';   // Symbole terminal 'valeur'
    TER[4] = ';';   // Symbole terminal ';'
    nb_ter = 5;     // Nombre de terminaux

    // Règles de grammaire
    strcpy(GRAMMAIRE[0], "Z->S");
    strcpy(GRAMMAIRE[1], "S->tD");
    strcpy(GRAMMAIRE[2], "D->dA");
    strcpy(GRAMMAIRE[3], "A->=V");
    strcpy(GRAMMAIRE[4], "V->n;");
    nb_regle = 5;    // Nombre de règles de grammaire

    chack_Ll1_condition();
    printf("\n=== TABLE D'ANALYSE LL(1) ===\n");
    int success = creer_table_analyse();
    affich_table_analyse(success);
  
}

void convertir_tokens_char(char *input, char *output) {
    // LES TOKENS RETOURNER PAR FLEX 
    const char* symbol_map[] = {
        "TOKEN_INT", "TOKEN_FLOAT", "TOKEN_STRING", "TOKEN_BOOL", "TOKEN_CHAR", 
        "IDENTIFIER", "ASSIGN", "VAL", "SEMICOLON"
    };

    // UN TABLEAU DE CORRESPONDANCE A NOTRE GRAMMAIRE 
    const char simplified_symbols[] = {'t', 't', 't', 't', 't', 'd', '=', 'n', ';'};
    int num_symbols = sizeof(symbol_map) / sizeof(symbol_map[0]);

    output[0] = '\0';
    char *token;
    char line[MAX];
    strncpy(line, input, sizeof(line) - 1);
    line[sizeof(line) - 1] = '\0';

    token = strtok(line, " \n");
    while (token != NULL) {
        int found = 0;
        for (int i = 0; i < num_symbols; i++) {
            if (strcmp(token, symbol_map[i]) == 0) {
                strncat(output, &simplified_symbols[i], 1);
                found = 1;
                break;
            }
        }
        if (!found) {
            fprintf(stderr, "Warning: Token not recognized: %s\n", token);
        }
        token = strtok(NULL, " \n");
        if (token != NULL) {
            strncat(output, " ", 1);
        }
    }
}

void add_token(const char* token) {
    strncpy(tokens_table[current_line][current_token], token, 50);
    tokens_table[current_line][current_token][49] = '\0';
    current_token++;
}

%}

%option noyywrap

%%

"int"           { add_token("TOKEN_INT"); }
"float"         { add_token("TOKEN_FLOAT"); }
"string"        { add_token("TOKEN_STRING"); }
"bool"          { add_token("TOKEN_BOOL"); }
"char"          { add_token("TOKEN_CHAR"); }
";"             { add_token("SEMICOLON"); }
"="             { add_token("ASSIGN"); }
[+-]?[0-9]+     { add_token("VAL"); }
[a-zA-Z_][a-zA-Z0-9_]*  { add_token("IDENTIFIER"); }
[\t ]+          { /* Ignorer les espaces et tabulations */ }
\n              { 
                 char converted_string[MAX];
                 char full_line[MAX] = "";

                 for (int i = 0; i < current_token; i++) {
                     strcat(full_line, tokens_table[current_line][i]);
                     if (i < current_token - 1) {
                         strcat(full_line, " ");
                     }
                 }
                 convertir_tokens_char(full_line, converted_string);
                 callToFakeMain();
                 printf("Ligne originale : %s\n", full_line);
                 removeSpaces(converted_string);
                printf("Chaîne simplifiée : %s\n", converted_string);
                 analyseur_ll1(converted_string);
                 current_line++;
                 current_token = 0;
               }
.               { printf("Unrecognized token: %s\n", yytext); }

%%

int main(void) {
    yylex();
    return 0;
}