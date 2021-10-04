//
// Created by Laurent Chau on 04/10/2021.
//

#include "core.h"

Element_str* initialiser_gouts(char gouts[]) {
    Element_str* temp = malloc(sizeof(*temp));

    for (int i = 0; i < strlen(gouts) + 1; i++) {
        temp->texte[i] = gouts[i];
    }
    temp->next = NULL;

    return temp;
}
