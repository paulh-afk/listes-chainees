#include "Header.h"

int main() {
    Liste *liste = initialisation();

    insertion(liste, (int*)19);

    afficher(liste);
    printf("\n");

    suppressionListe(liste);

    afficher(liste);
    printf("\n");

    insertion(liste, (int*)19);
    insertion(liste, (int*)1);
    insertion(liste, (int*)120);

    afficher(liste);
    printf("\n");

    suppressionElementIndex(liste, 1);

    afficher(liste);
    printf("\n");

    ajoutElementIndex(liste, 13, 1);

    afficher(liste);

    return 0;
}
