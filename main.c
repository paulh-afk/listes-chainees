#include "Header.h"

Liste* initialisation() {
    Liste *liste = malloc(sizeof(*liste));
    Element *element = malloc(sizeof(*element));


    if(liste == NULL || element == NULL) {
        exit(EXIT_FAILURE);
    }

    element->donnee = 0;
    element->suivant = NULL;

    liste->premier = element;
    liste->taille = 1;

    return liste;
}

void insertion(Liste *liste, void* donnee) {
    Element *nouvelleElement = malloc(sizeof(*nouvelleElement));

    if(liste == NULL || nouvelleElement == NULL) {
        exit(EXIT_FAILURE);
    }

    nouvelleElement->donnee = donnee;
    nouvelleElement->suivant = liste->premier;

    liste->premier = nouvelleElement;
    liste->taille += 1;
}

void suppression(Liste *liste) {
    if(liste == NULL) {
        exit(EXIT_FAILURE);
    }

    if(liste->premier != NULL) {
        Element *aSupprimer = liste->premier;
        liste->premier = aSupprimer->suivant;
        liste->taille -= 1;
        free(aSupprimer);
    }
}

void afficher(Liste *liste) {
    if(liste == NULL) {
        exit(EXIT_FAILURE);
    }

    Element *elementActuel = liste->premier;

    while(elementActuel != NULL) {
        printf("%d -> ", elementActuel->donnee);
        elementActuel = elementActuel->suivant;
    }
    printf("NULL");
}

int main() {
    Liste *liste = initialisation();

    insertion(liste, 67);
    insertion(liste, 55);
    insertion(liste, 18);
    suppression(liste);

    afficher(liste);

    return 0;
}
