//
// Created by Laurent Chau on 04/10/2021.
//

#include "core.h"

Element_str* initialiser_gouts() {
    char liste_gouts[MIN][MAX] = {"Chocolat", "Vanille", "Fraise", "Abricot", "Pomme", "Banane", "Myrtille"};
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
    Element_str* previous = NULL;
    if (f_commandes->commande->next != NULL) {
        previous = f_commandes->commande;
        f_commandes->commande = f_commandes->commande->next;
    }

    while (f_commandes->commande != NULL) {
        previous = f_commandes->commande;
        f_commandes->commande = f_commandes->commande->next;
    }

    f_commandes->commande = malloc(sizeof(*f_commandes->commande));

    if (previous != NULL) {
        previous->next = f_commandes->commande;
    }

    for (int i = 0; i < strlen(commande) + 1; i++) {
        f_commandes->commande->texte[i] = commande[i];
    }
    f_commandes->commande->next = NULL;
}

Element_str* traiter_commande(File_Commandes* f_commandes) {
    Element_str* l_gouts = initialiser_gouts();
    Element_str* head_l_gouts = l_gouts;
    Element_str* gateau = malloc(sizeof(*gateau));
    Element_str* previous = NULL;

    for (int i = 0; i < strlen(f_commandes->commande->texte) + 1; i++) {
        while (f_commandes->commande->texte[i] != l_gouts->texte[0] && l_gouts != NULL) {
            l_gouts = l_gouts->next;
        }

        for (int j = 0; j < strlen(l_gouts->texte) + 1; j++) {
            gateau->texte[j] = l_gouts->texte[j];
        }
        gateau->next = NULL;

        if (previous != NULL) {
            previous->next = gateau;
        }

        previous = gateau;
        l_gouts = head_l_gouts;
    }
    Element_str* temp = f_commandes->commande->next;
    free(f_commandes->commande);
    f_commandes->nb_commandes--;
    f_commandes->commande = temp;

    return gateau;
}