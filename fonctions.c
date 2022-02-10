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
    liste->nbElements = 1;

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
    liste->nbElements += 1;
}

void suppression(Liste *liste) {
    if(liste == NULL) {
        exit(EXIT_FAILURE);
    }

    if(liste->premier != NULL) {
        Element *aSupprimer = liste->premier;
        liste->premier = aSupprimer->suivant;
        liste->nbElements -= 1;
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

// -------------------------------------------------------

void ajoutElementIndex(Liste *liste, void* donnee, int index) {
    Element *nouvelleElement = malloc(sizeof(*nouvelleElement));

    if(liste == NULL || nouvelleElement == NULL || index > (tailleListe(liste) - 1) || index < 0) {
        exit(EXIT_FAILURE);
    }

    nouvelleElement->donnee = donnee;

    if(index == 0) {
        // insertion()
        nouvelleElement->suivant = liste->premier;
        liste->premier = nouvelleElement;
    } else {
        Element *elementPrecedent = liste->premier;

        for(int i = 0; i < index - 1; i++) {
            elementPrecedent = elementPrecedent->suivant;
        }

        nouvelleElement->suivant = elementPrecedent->suivant;
        elementPrecedent->suivant = nouvelleElement;
    }

    liste->nbElements += 1;
}

void suppressionElementIndex(Liste *liste, int index) {
    if(liste == NULL || index > (tailleListe(liste) - 1) || index < 0) {
       exit(EXIT_FAILURE);
    }

    Element *elementPrecedent = liste->premier;

    if(index == 0) {
        // suppression()
        liste->premier = elementPrecedent->suivant;

        free(elementPrecedent);
    } else {
        for(int i = 0; i < index - 1; i++) {
            elementPrecedent = elementPrecedent->suivant;
        }

        Element *aSupprimer = elementPrecedent->suivant;
        elementPrecedent->suivant = elementPrecedent->suivant->suivant;

        free(aSupprimer);
    }

    liste->nbElements -= 1;
}

void suppressionListe(Liste *liste) {
    if(liste == NULL) {
        exit(EXIT_FAILURE);
    }

    Element *elementCourant = liste->premier;

    while(elementCourant != NULL) {
        Element *aSupprimer = elementCourant;

        elementCourant = elementCourant->suivant;
        free(aSupprimer);
    }

    liste->premier = NULL;
    liste->nbElements = 0;
}

int tailleListe(Liste *liste) {
    if(liste == NULL) {
        exit(EXIT_FAILURE);
    }

    return liste->nbElements;
}
