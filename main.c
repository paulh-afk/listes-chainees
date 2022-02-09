#include "Header.h"

Liste *initialisation() {
    Liste *liste = malloc(sizeof(*liste));
    Element *element = malloc(sizeof(*element));

    if(liste == NULL || element == NULL) {
        exit(EXIT_FAILURE);
    }

    element->donnee = 0;
    element->suivant = NULL;
    liste->premier = element;

    return liste;
}

void insertion(Liste *liste, void* donnee) {
    Element *element = malloc(sizeof(*element));

    if(liste == NULL || element == NULL) {
        exit(EXIT_FAILURE);
    }

    element->donnee = donnee;
    element->suivant = liste->premier;
    liste->premier = element;
}

void suppression(Liste *liste) {
    if(liste == NULL) {
        exit(EXIT_FAILURE);
    }

    if(liste->premier != NULL) {
        Element *aSupprimer = liste->premier;
        liste->premier = liste->premier->suivant;
        free(aSupprimer);
    }
}

int main() {
    Liste *liste;
    liste = initialisation();

    insertion(liste, "chaine");
    insertion(liste, 13);
    suppression(liste);

    printf("%s", liste->premier->donnee);

    return 0;
}
