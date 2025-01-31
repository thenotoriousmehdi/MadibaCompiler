%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbol_table.h" 
#include "pile.h"
#ifndef strdup
#define strdup _strdup
#endif

// Prototype de la fonction principale d'analyse lexicale
int yylex();
void yyerror(const char *s);
extern int yylex(void);  // Déclare la fonction yylex générée par Flex

extern int lineNumber;
extern int columnNumber;
extern table_symbol symbolTable;



typedef struct quadruplet quadruplet;
struct quadruplet
{   
    char oprt[30];
	char op1[30];
	char op2[30];   
	char result[30]; 
};

quadruplet tab_quad[1000]; 

pile  stack;

int qc = 1 ; 
int ti = 0 ; 


// pour print 
char* print_expressions[30];  
int num_print_expressions = 0;

char current_loop_var[256];  
char increment_val[256];
int condition_addr;



%}

%union {
    int intval;         // Pour INTEGER_LITERAL
    float floatval;     // Pour FLOAT_LITERAL
    char charval;       // Pour CHAR_LITERAL
    char* strval;       // Pour STRING_LITERAL et IDENTIFIER
    int type;           // Pour les types (INT, FLOAT, etc.)
   
    struct expressionTYPE {
    int type ;
    char val[256];
    } expressionTYPE;
}


%token IMPORT PROGRAM CONST VAR TYPES FUNCTIONS MAIN INT FLOAT CHAR BOOL STRING CST OBJECT ENUM FUNCTION FOR WHILE IF ELSE SCAN PRINT VOID TRUE FALSE
%token INTEGER_LITERAL FLOAT_LITERAL CHAR_LITERAL STRING_LITERAL IDENTIFIER ARRAY OBJECT_FIELD DOT
%token AND OR NOT
%token EQUAL NOT_EQUAL LESS_THAN GREATER_THAN LESS_EQUAL GREATER_EQUAL
%token PLUS MINUS MULTIPLY DIVIDE MODULO
%token COMMA OPEN_PAREN CLOSE_PAREN OPEN_BRACKET CLOSE_BRACKET OPEN_BRACE CLOSE_BRACE SEMICOLON QUOTE ASSIGN TWO_POINT RETURN

%type <intval> INTEGER_LITERAL
%type <floatval> FLOAT_LITERAL
%type <charval> CHAR_LITERAL
%type <strval> STRING_LITERAL IDENTIFIER
%type <type> type
%type <expressionTYPE> value
%type <expressionTYPE> expression

%left AND OR
%left EQUAL NOT_EQUAL LESS_THAN GREATER_THAN LESS_EQUAL GREATER_EQUAL
%left PLUS MINUS
%left MULTIPLY DIVIDE MODULO
%right NOT


%%

program:
    import_section PROGRAM IDENTIFIER const_section var_section types_section functions_section main_section 
    {
        printf("Analyse syntaxique correcte.\n");
        displayTable(); // Affiche la table des symboles après l'analyse
        YYACCEPT;
    }
    ;

import_section:
    IMPORT STRING_LITERAL SEMICOLON
    ;

const_section:
    /* vide */
    | CONST OPEN_BRACE const_declarations CLOSE_BRACE
    ;

const_declarations:
    /* vide */
    | const_declarations const_declaration 
    ;

const_declaration:
    type IDENTIFIER ASSIGN value SEMICOLON 
    {   
         
        if (insertSymbol($2, C_CONST, $1, 0) == -1) {
             char temp[100] ; 
            sprintf(temp,"Constante %s déjà déclarée.\n", $2);
            yyerrorS(temp);
        }
       
        if ($4.type != $1) {
            char temp[100] ; 
            sprintf(temp,"Type de la constante %s incorrect.\n", $2);

            yyerrorS(temp);
        }else{
              strcpy(tab_quad[qc].oprt,"=");
              strcpy(tab_quad[qc].op1,$4.val);
              strcpy(tab_quad[qc].op2,"");
              strcpy(tab_quad[qc].result,$2);
                qc++;
        }
        
    }
    ;


var_section:
    VAR OPEN_BRACE var_declarations CLOSE_BRACE
    ;

var_declarations:
    /* vide */
    | var_declarations var_declaration
    ;

var_declaration:
    type IDENTIFIER ASSIGN value SEMICOLON 
    {
        if (insertSymbol($2, C_VAR, $1, 0) == -1) {
            printf("Erreur : Variable %s déjà déclarée.\n", $2);
        }
         if ($4.type != $1) {
            printf("Erreur : Type de la Variable %s incorrect.\n", $2);
        }else{
             
              strcpy(tab_quad[qc].oprt,"=");
              strcpy(tab_quad[qc].op1,$4.val);
              strcpy(tab_quad[qc].op2,"");
              strcpy(tab_quad[qc].result,$2);
                qc++;
        }
    }
    | type IDENTIFIER SEMICOLON 
    {
        if (insertSymbol($2, C_VAR, $1, 0) == -1) {
            printf("Erreur : Variable %s déjà déclarée.\n", $2);
        }
    }
    ;



type:
    INT { $$ = T_INT; }
    | FLOAT { $$ = T_FLOAT; }
    | CHAR { $$ = T_CHAR; }
    | BOOL { $$ = T_BOOL; }
    | STRING { $$ = T_STRING; }
    ;

value:
    INTEGER_LITERAL { 
     $$.type = T_INT ; 
    char buffer[20]; 
    sprintf(buffer, "%d", $1); 
    strcpy($$.val,strdup(buffer)); 
     }   
  | FLOAT_LITERAL { 
    $$.type = T_FLOAT ; 
    char buffer[20]; 
    sprintf(buffer, "%f", $1); 
    strcpy($$.val,strdup(buffer));  
}
  | CHAR_LITERAL { 
   $$.type = T_CHAR ;    
    char buffer[20] ;
    sprintf(buffer, "%c", $1);
   strcpy($$.val,strdup(buffer)); 
}
  |STRING_LITERAL {  $$.type =  T_STRING ;   
                      char buffer[20] ;
                     sprintf(buffer, "%s", $1);
                     strcpy($$.val,strdup(buffer));  }
 
 
  | TRUE            {  $$.type = T_BOOL;  strcpy($$.val,strdup("true"));  }
  | FALSE           {  $$.type =  T_BOOL; strcpy($$.val,strdup("false"));  }
;



types_section:
    /* vide */
    | TYPES OPEN_BRACE types_declarations CLOSE_BRACE 
    {
        symbolTable.base = 0;
    }
    ;

types_declarations:
    /* vide */
    | types_declarations type_declaration
    ;

type_declaration:
    OBJECT IDENTIFIER OPEN_BRACE object_fields CLOSE_BRACE
    {
        if (insertSymbol($2, C_TYPE, T_STRING, symbolTable.base) == -1) {
            printf("Erreur : Type objet %s déjà déclaré.\n", $2);
        }
        symbolTable.base = 0 ;
    }
    | type IDENTIFIER OPEN_BRACKET INTEGER_LITERAL CLOSE_BRACKET SEMICOLON {
        printf("Tableau %s de type %d avec taille %d\n", $2, $1, $4); 
        if (insertSymbol($2, C_ARRAY, $1, $4) == -1) {
            printf("Erreur : Type enum %s déjà déclaré.\n", $2);
        }
    
    }
    ;

object_fields:
    /* vide */
    | object_fields type IDENTIFIER SEMICOLON
    {
        if(insertSymbol($3,C_CHAMP , $2, 0) == -1) {
            printf("Erreur : Type enum %d déjà déclaré.\n", $2);
        }
        symbolTable.base ++;
    }
    | object_fields type IDENTIFIER ASSIGN value SEMICOLON
    {
        if(insertSymbol($3,C_CHAMP , $2, 0) == -1) {
            printf("Erreur : Type enum %d déjà déclaré.\n", $2);
        }
        symbolTable.base ++;
    }
    ;

functions_section:
    /* vide */
    | FUNCTIONS OPEN_BRACE function_declarations CLOSE_BRACE
    ;

function_declarations:
    /* vide */
    | function_declarations function_declaration
    ;

function_declaration:
    type FUNCTION IDENTIFIER OPEN_PAREN parameters CLOSE_PAREN OPEN_BRACE fonction_body CLOSE_BRACE 
    {
        if (insertSymbol($3, C_VAR, T_FUNCTION, symbolTable.base) == -1) {
            printf("Erreur : Fonction %s déjà déclarée.\n", $3);
        }
        symbolTable.base = 0 ;
    
    }
    | VOID FUNCTION IDENTIFIER OPEN_PAREN parameters CLOSE_PAREN OPEN_BRACE fonction_body CLOSE_BRACE 
    {
        if (insertSymbol($3, C_VAR, T_FUNCTION,symbolTable.base) == -1) {
            printf("Erreur : Fonction %s déjà déclarée.\n", $3);
        }
        symbolTable.base = 0 ;
    }
;

parameters:
    /* vide */
    | parameter_list
    ;

parameter_list:
    type TWO_POINT IDENTIFIER
    {
        if (insertSymbol($3, C_ARGUMENT, $1, 0) == -1) {
            printf("Erreur : Argument %s déjà déclaré.\n", $3);
        }
        {
        symbolTable.base ++;
    
    }
    }
    | parameter_list COMMA type TWO_POINT IDENTIFIER
    {
        if (insertSymbol($5, C_ARGUMENT, $3, 0) == -1) {
            printf("Erreur : Argument %s déjà déclaré.\n", $5);
        }
        symbolTable.base ++;
    }
    ;
    
    
fonction_body:
    /* vide */
    | instructions_fonction_list
    ;

instructions_fonction_list:
    instruction_fonction
    | instructions_fonction_list instruction_fonction
    ;

instruction_fonction:
   
    type IDENTIFIER ASSIGN expression SEMICOLON 
     {
        if (insertSymbol($2, C_LOCAL, $1, 0) == -1) {
            printf("Erreur : Argument %d déjà déclaré.\n", $1);
        }
    }
    |type IDENTIFIER SEMICOLON 
     {
        if (insertSymbol($2, C_LOCAL, $1, 0) == -1) {
            printf("Erreur : Argument %d déjà déclaré.\n", $1);
        }
    }
    |affectation
    | print_stmt
    | scan_stmt
    | if_stmt
    | for_stmt
    | while_stmt
    | function_call SEMICOLON
    ;


function_call:
    IDENTIFIER OPEN_PAREN argument_list CLOSE_PAREN
    ;

argument_list:
    /* vide */
    | argument_list COMMA expression
    | expression
    ;

    
main_section:
    MAIN OPEN_BRACE main_body CLOSE_BRACE
    ;

main_body:
    /* vide */
    | instruction_list
    ;

instruction_list:
    instruction
    | instruction_list instruction
    ;

instruction:
    affectation
    | print_stmt
    | scan_stmt
    | if_stmt
    | for_stmt
    | while_stmt
    | function_call SEMICOLON
    ;

affectation:
    IDENTIFIER  ASSIGN expression SEMICOLON  {
        desc_identif* symbol = lookupSymbol($<strval>1);
        if (symbol == NULL) {
         char error_message[256];
         sprintf(error_message, "Variable %s non declaree.", $1);          
         yyerrorS(error_message);
        }else {
         if ($3.type != symbol->type) {
            printf("Erreur Sémantique : Type de la variable %s incorrect.\n", $1);
        }else{
              strcpy(tab_quad[qc].oprt,"=");
              strcpy(tab_quad[qc].op1,$3.val);
              strcpy(tab_quad[qc].op2,"");
              strcpy(tab_quad[qc].result,$1);
                qc++;
        }
    }
 } /////////
    | IDENTIFIER OPEN_BRACKET expression CLOSE_BRACKET ASSIGN expression SEMICOLON
    |IDENTIFIER DOT IDENTIFIER ASSIGN expression SEMICOLON
    ;

print_stmt:
    PRINT OPEN_PAREN print_expression_list CLOSE_PAREN SEMICOLON {
      
        for (int i = 0; i < num_print_expressions; i++) {
            strcpy(tab_quad[qc].oprt, "PRINT");
            strcpy(tab_quad[qc].op1, print_expressions[i]); 
            strcpy(tab_quad[qc].op2, "");
            strcpy(tab_quad[qc].result, "");
            qc++; 

            free(print_expressions[i]);
        }

       
        num_print_expressions = 0;
    }
    ;
print_expression_list:
    expression {
        print_expressions[num_print_expressions++] = strdup($1.val); 
    }
    | print_expression_list COMMA expression {
        print_expressions[num_print_expressions++] = strdup($3.val);  
    }
    ;

scan_stmt:
    SCAN OPEN_PAREN IDENTIFIER CLOSE_PAREN SEMICOLON {

        desc_identif* symbol = lookupSymbol($<strval>3);
        if (symbol != NULL) {
            strcpy(tab_quad[qc].oprt, "SCAN");
            strcpy(tab_quad[qc].op1, $3);  
            strcpy(tab_quad[qc].op2, "");
            strcpy(tab_quad[qc].result, "");
            qc++;  
        } else {
            yyerrorS("Invalid variable for SCAN");
        }
    }
    ;


if_stmt:
    IF OPEN_PAREN expression CLOSE_PAREN {
        if ($3.type == T_BOOL) {
            empiler(&stack, qc-1); 
        } else {
            yyerrorS("Condition must evaluate to a boolean value");
        }
    }
    OPEN_BRACE instruction_list CLOSE_BRACE else_part  {
        if (!estVide(&stack)) {  
            char addrEndIf[10];
            int addrFalseJump = depiler(&stack);

            sprintf(addrEndIf, "%d", qc);
            strcpy(tab_quad[addrFalseJump].op1, addrEndIf);
        } else {
            printf("Erreur : La pile est vide.\n");
        }
    } ;
    else_part:
    | ELSE {
        strcpy(tab_quad[qc].oprt, "BR");
        strcpy(tab_quad[qc].op1, "");
        strcpy(tab_quad[qc].op2, "");
        strcpy(tab_quad[qc].result, "");

        if (!estVide(&stack)) {
            char addrEndIf[10];
            int addrFalseJump = depiler(&stack);
            empiler(&stack, qc); 
            qc++;
            sprintf(addrEndIf, "%d", qc);
            strcpy(tab_quad[addrFalseJump].op1, addrEndIf);
        } else {
            printf("Erreur : La pile est vide.\n");
        }
    }
    OPEN_BRACE instruction_list CLOSE_BRACE
    ;

for_stmt:
    FOR OPEN_PAREN init_for corp_for OPEN_BRACE instruction_list CLOSE_BRACE {
              
        int expFor = depiler(&stack);  // on depile l'addrese de la condition 
        char temp [30]; 

        strcpy(tab_quad[qc].oprt, "BR");
        sprintf(temp, "%d", expFor);  // Jump to comparison
        strcpy(tab_quad[qc].op1, temp);
        strcpy(tab_quad[qc].op2, "");
        strcpy(tab_quad[qc].result, "");

        

        qc++;
         sprintf(temp,"%d",qc);

        strcpy(tab_quad[expFor].op1,temp); // mise a jour de l'adresse de la condition pour le branchement 
    }
    ;

init_for:
    IDENTIFIER ASSIGN expression COMMA {
        strcpy(current_loop_var, $1);  
       
        strcpy(tab_quad[qc].oprt, "=");
        strcpy(tab_quad[qc].op1, $3.val); 
        strcpy(tab_quad[qc].op2, "");
        strcpy(tab_quad[qc].result, $1);   
        qc++;
       
        condition_addr = qc;  
    }
    ;

corp_for:
    value COMMA value CLOSE_PAREN {
        
        strcpy(tab_quad[qc].oprt, "BG");
        strcpy(tab_quad[qc].op1, "temp");  // on va changer sa valeur dans la fin de for 
        strcpy(tab_quad[qc].op2,current_loop_var );      // 10
        strcpy(tab_quad[qc].result, $1.val);
        empiler(&stack,qc); // empiler pour pouvoir retourner 
        qc++;

        // incrementation 
        strcpy(tab_quad[qc].oprt, "+");
        strcpy(tab_quad[qc].op1, current_loop_var);
        strcpy(tab_quad[qc].op2, $3.val);
        char temp[20];
        sprintf(temp, "T%d", ti++);
        strcpy(tab_quad[qc].result, temp);
        qc++;
       
        strcpy(tab_quad[qc].oprt, "=");
        strcpy(tab_quad[qc].op1, temp);
        strcpy(tab_quad[qc].op2, "");
        strcpy(tab_quad[qc].result, current_loop_var);
        qc++;
       
   
       
       
        // Save increment value for later
        strcpy(increment_val, $3.val);
    }
    ;



while_stmt:
   debut_while  corp_while instruction_list CLOSE_BRACE {
    char adresse[10];
    char adresseCondWhile [10];

     int addrDebutWhile = depiler(&stack);  // apres verif cond nchofo win nro7o ida fin wela debut fin while 
    int addrCondWhile = depiler(&stack);  
    sprintf(adresseCondWhile,"%d",addrCondWhile);
    strcpy(tab_quad[qc].oprt,"BR");
    strcpy(tab_quad[qc].op1,adresseCondWhile); // branchement direct au debut de l'expression de la condition 
    strcpy(tab_quad[qc].op2,"");
    strcpy(tab_quad[qc].result,"");
    qc++;
    sprintf(adresse,"%d",qc);
    strcpy(tab_quad[addrDebutWhile].op1,adresse); // mise ajour  de laaddrese de expression 
    };

debut_while :  WHILE OPEN_PAREN {
    empiler(&stack,qc);  // empiler l'adresse de la condition  pour retourner a la condition  
  };
corp_while : 
       expression  CLOSE_PAREN OPEN_BRACE  { 
    if($1.type == T_BOOL){
        empiler(&stack,qc-1);  // empiler @ de quadriplet de l'expression  pour update 
    }else{
        printf("Semantic error : cannot evaluate non boolean expression as condition");
    }
} ;


expression:
    expression OR expression   {  // pas sur 
             if($1.type == T_BOOL &&  $3.type == T_BOOL  )
                    {  $$.type = T_BOOL ; 
                        strcpy(tab_quad[qc].oprt,"|");
                        strcpy(tab_quad[qc].op1,$1.val);
                        strcpy(tab_quad[qc].op2,$3.val);
                        char  res [10]; 
                        sprintf(res,"T%d",ti);
                        strcpy(tab_quad[qc].result,res);
                        strcpy($$.val,res);
                         ti++; 
                         qc++;  
                           } else {
                             yyerrorS("Type expression incompatible");
                                   }   
                     }
    | expression AND expression   { //revoir 
             if($1.type == T_BOOL &&  $3.type == T_BOOL  )
                    {  $$.type = T_BOOL ; 
                        strcpy(tab_quad[qc].oprt,"&");
                        strcpy(tab_quad[qc].op1,$1.val);
                        strcpy(tab_quad[qc].op2,$3.val);
                        char  res [10]; 
                        sprintf(res,"T%d",ti);
                        strcpy(tab_quad[qc].result,res);
                        strcpy($$.val,res);
                         ti++; 
                         qc++;  
                           } else {
                             yyerrorS("Type expression incompatible");
                                   }   
                     }
  | expression EQUAL expression { 
         
             if($1.type == $3.type  )
                    { $$.type = T_BOOL ;  ; 
                        strcpy(tab_quad[qc].oprt,"BNE");
                        strcpy(tab_quad[qc].op1,"");
                        strcpy(tab_quad[qc].op2,$1.val);
                        strcpy(tab_quad[qc].result,$3.val);
                         char  res [10]; 
                        sprintf(res,"T%d",ti);
                        strcpy($$.val,res);
                         ti++; 
                         qc++;  
                           } else {
                             yyerrorS("Type expression incompatible");
                           }   
                     }
    | expression NOT_EQUAL expression  { 
             if($1.type == $3.type  )
                    { $$.type = T_BOOL ; 
                        strcpy(tab_quad[qc].oprt,"BE");
                        strcpy(tab_quad[qc].op1,"");
                        strcpy(tab_quad[qc].op2,$1.val);
                        strcpy(tab_quad[qc].result,$3.val);
                        strcpy($$.val,"");
                         qc++;  
                           } else {
                             yyerrorS("Type expression incompatible");
                                   }   
                     }
    | expression LESS_THAN expression { 
             if($1.type == $3.type  )
                    { $$.type = T_BOOL ;  ; 
                        strcpy(tab_quad[qc].oprt,"BGE");
                        strcpy(tab_quad[qc].op1,"");
                        strcpy(tab_quad[qc].op2,$1.val);
                        strcpy(tab_quad[qc].result,$3.val);
                        strcpy($$.val,"");
                         qc++;  
                           } else {
                             yyerrorS("Type expression incompatible");
                                   }   
                     }
    | expression GREATER_THAN expression { 
             if($1.type == $3.type  )
                    {  $$.type = T_BOOL ; 
                        strcpy(tab_quad[qc].oprt,"BLE");
                        strcpy(tab_quad[qc].op1,"");
                        strcpy(tab_quad[qc].op2,$1.val);
                        strcpy(tab_quad[qc].result,$3.val);
                        strcpy($$.val,"");
                         qc++;  
                           } else {
                             yyerrorS("Type expression incompatible");
                                   }   
                     }
    | expression LESS_EQUAL expression { 
             if($1.type == $3.type  )
                    { $$.type = T_BOOL ; 
                        strcpy(tab_quad[qc].oprt,"BG");
                        strcpy(tab_quad[qc].op1,"");
                        strcpy(tab_quad[qc].op2,$1.val);
                        strcpy(tab_quad[qc].result,$3.val);
                        strcpy($$.val,"");
                         qc++;  
                           } else {
                             yyerrorS("Type expression incompatible");
                                   }   
                     }
    | expression GREATER_EQUAL expression { 
             if($1.type == $3.type  )
                    { $$.type = T_BOOL ;  ; 
                        strcpy(tab_quad[qc].oprt,"BL");
                        strcpy(tab_quad[qc].op1,"");
                        strcpy(tab_quad[qc].op2,$1.val);
                        strcpy(tab_quad[qc].result,$3.val);
                        strcpy($$.val,"");
                         qc++;  
                           } else {
                             yyerrorS("Type expression incompatible");
                                   }   
                     }
    | expression PLUS expression  { 
             if($1.type == $3.type &&  ( $1.type == T_INT  | $1.type == T_FLOAT ))
                    {  $$.type = $1.type ; 
                        strcpy(tab_quad[qc].oprt,"+");
                        strcpy(tab_quad[qc].op1,$1.val);
                        strcpy(tab_quad[qc].op2,$3.val);
                        char  res [10]; 
                        sprintf(res,"T%d",ti);
                        strcpy(tab_quad[qc].result,res);
                        strcpy($$.val,res);
                         ti++; 
                         qc++;  
                           } else {
                             yyerrorS("Type expression incompatible");
                                   }   
                     }
    | expression MINUS expression   { 
             if($1.type == $3.type &&  ( $1.type == T_INT  | $1.type == T_FLOAT ))
                    {  $$.type = $1.type ; 
                        strcpy(tab_quad[qc].oprt,"-");
                        strcpy(tab_quad[qc].op1,$1.val);
                        strcpy(tab_quad[qc].op2,$3.val);
                        char  res [10]; 
                        sprintf(res,"T%d",ti);
                        strcpy(tab_quad[qc].result,res);
                        strcpy($$.val,res);
                         ti++; 
                         qc++;  
                           } else {
                             yyerrorS("Type expression incompatible");
                                   }   
                     }
    | expression MULTIPLY expression  { 
             if($1.type == $3.type &&  ( $1.type == T_INT  | $1.type == T_FLOAT ))
                    {  $$.type = $1.type ; 
                        strcpy(tab_quad[qc].oprt,"*");
                        strcpy(tab_quad[qc].op1,$1.val);
                        strcpy(tab_quad[qc].op2,$3.val);
                        char  res [10]; 
                        sprintf(res,"T%d",ti);
                        strcpy(tab_quad[qc].result,res);
                        strcpy($$.val,res);
                         ti++; 
                         qc++;  
                           } else {
                             yyerrorS("Type expression incompatible");
                                   }   
                     }
    | expression DIVIDE expression  { 
             if($1.type == $3.type &&  ( $1.type == T_INT  | $1.type == T_FLOAT ))
                    {   if( strcmp($3.val,"0") != 0   ){
                        if( atoi($1.val) % atoi($3.val) == 0){
                           $$.type = T_INT ; 
                        } else {
                            $$.type = T_FLOAT; 
                        }
                        strcpy(tab_quad[qc].oprt,"/");
                        strcpy(tab_quad[qc].op1,$1.val);
                        strcpy(tab_quad[qc].op2,$3.val);
                        char  res [10]; 
                        sprintf(res,"T%d",ti);
                        strcpy(tab_quad[qc].result,res);
                        strcpy($$.val,res);
                         ti++; 
                         qc++;  
                           } else {
                    yyerrorS("Devision par 0 impossible !");  
                                   }  
                    }else{
                         yyerrorS("Type expression incompatible");
                    } 
                    }
    | expression MODULO expression   { 
             if($1.type == $3.type &&  ( $1.type == T_INT  | $1.type == T_FLOAT ))
                    {   if( strcmp($3.val,"0") != 0   ){
                           $$.type = T_INT ; 
                        strcpy(tab_quad[qc].oprt,"%");
                        strcpy(tab_quad[qc].op1,$1.val);
                        strcpy(tab_quad[qc].op2,$3.val);
                        char  res [10]; 
                        sprintf(res,"T%d",ti);
                        strcpy(tab_quad[qc].result,res);
                        strcpy($$.val,res);
                         ti++; 
                         qc++;  
                           } else {                        
                             yyerrorS("Devision par 0 impossible !");
                                   }  
                    }else{
                          yyerrorS("Type expression incompatible");
                    } 
                    }
    | NOT expression
    | function_call
    | OPEN_PAREN expression CLOSE_PAREN {
        $$.type = $2.type ; 
        strcpy($$.val,$2.val); 
    }
    | IDENTIFIER OPEN_BRACKET expression CLOSE_BRACKET //TABLEAU 
    | IDENTIFIER DOT IDENTIFIER  //OBJET 
    | IDENTIFIER   {
          desc_identif* symbol = lookupSymbol($<strval>1);
        if (symbol == NULL) {
         char error_message[256];
         sprintf(error_message, "Variable %s non declaree.", $1);          
         yyerrorS(error_message);
        }else {
            $$.type = symbol->type; 
            strcpy($$.val,$1) ; 
        }
    }
    | value
    ;
%%

void yyerror(const char *s) {
    fprintf(stderr, "Erreur syntaxique ligne %d, colonne %d : %s\n", lineNumber, columnNumber, s);
}
void yyerrorS(const char *s) {
    fprintf(stderr, "Erreur Semantique ligne %d, colonne %d : %s\n", lineNumber, columnNumber, s);
}

int main() {
    initTable(); 
    
    initPile(&stack); 
    printf("\nAnalyse syntaxique en cours...\n");
     yyparse();


      printf("Analyse syntaxique TERMINER...\n");
   for (int i = 1; i < qc; i++) {
    printf("[%d] - ( %s , %s , %s , %s )\n",  i, tab_quad[i].oprt, tab_quad[i].op1, tab_quad[i].op2, tab_quad[i].result);
   }
    return 0;

}
