#define MAX 128

// pile de tableau
 
typedef struct pile pile;
struct pile{
    int sommet;
    int table[MAX];
};

void initPile(pile *P);


void empiler(pile *p, int x);

int depiler(pile *p);
int estVide(pile *p);
int estPleine(pile *p);

