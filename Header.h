#include <stdio.h>
#include <stdlib.h>

typedef struct Element Element;
struct Element {
    void* donnee;
    Element *suivant;
};

typedef struct Liste Liste;
struct Liste {
    Element* premier;
};
