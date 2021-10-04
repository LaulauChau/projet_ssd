//
// Created by Laurent Chau on 04/10/2021.
//

#include "core.h"

Element_str* initialiser_gouts(char liste_gouts[MIN][MAX]) {
    Element_str* head = malloc(sizeof(*head));
    for (int i = 0; i < strlen(liste_gouts[0]) + 1; i++) {
        head->texte[i] = liste_gouts[0][i];
    }
    head->next = NULL;
    Element_str* previous = head;

    for (int i = 1; i < strlen((const char *) liste_gouts) - 1; i++) {
        Element_str* link = malloc(sizeof(*link));
        for (int j = 0; j < strlen(liste_gouts[i]) + 1; j++) {
            link->texte[j] = liste_gouts[i][j];
        }
        link->next = NULL;
        previous->next = link;
        previous = link;
    }
    return head;
}

void passer_commande(char commande[50], File_Commandes* f_commandes) {
    f_commandes->data = malloc(sizeof(*f_commandes->data));

    for (int i = 0; i < strlen(commande); i++) {
        for (int j = 0; j < 2; j++) {
            if (j == 0) {
                f_commandes->data->texte[j] = commande[i];
            } else {
                f_commandes->data->texte[j] = '\0';
            }
        }
        f_commandes->data->next = NULL;
    }
}
