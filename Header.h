#include <stdio.h>
#include <stdlib.h>

typedef struct Element Element;
struct Element {
    void* donnee;
    Element *suivant;
};

typedef struct Liste Liste;
struct Liste {
    Element *premier;
    int nbElements;
};

Liste* initialisation();
void insertion(Liste *liste, void* donnee);
void suppression(Liste *liste);
void afficher(Liste *liste);

// -------------------------------------------------------

void ajoutElementIndex(Liste *liste, void* donnee, int index);
void suppressionIndex(Liste *liste, int index);
void suppressionListe(Liste *liste);
int tailleListe(Liste *liste);
