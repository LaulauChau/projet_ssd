//
// Created by Laurent Chau on 04/10/2021.
//

#include "core.h"

Element_str* initialiser_gouts() {
    char liste_gouts[MIN][MAX] = {"Chocolat", "Vanille", "Fraise", "Abricot", "Pomme", "Banane", "Myrtille"};
    Element_str* head = malloc(sizeof(*head));
    strcpy(head->texte, liste_gouts[0]);
    head->next = NULL;
    Element_str* previous = head;

    for (int i = 1; i < strlen((const char *) liste_gouts) - 1; i++) {
        Element_str* link = malloc(sizeof(*link));
        strcpy(link->texte, liste_gouts[i]);
        link->next = NULL;
        previous->next = link;
        previous = link;
    }
    return head;
}

void passer_commande(char commande[50], File_Commandes* f_commandes) {
    if (f_commandes->nb_commandes >= 10) {
        return;
    }

    Element_str* nouv_commande = malloc(sizeof(*nouv_commande));
    strcpy(nouv_commande->texte, commande);
    nouv_commande->next = NULL;

    if (f_commandes->nb_commandes != 0) {
        Element_str* premiere_commande = f_commandes->commande;
        Element_str* commande_actuel = f_commandes->commande;

        while (commande_actuel->next != NULL) {
            commande_actuel = commande_actuel->next;
        }

        commande_actuel->next = nouv_commande;
        f_commandes->commande = premiere_commande;
    } else {
        f_commandes->commande = nouv_commande;
    }

    f_commandes->nb_commandes++;
}

Element_str* traiter_commande(File_Commandes* f_commandes) {
    if (f_commandes->nb_commandes == 0) {
        return NULL;
    }

    Element_str* l_gouts = initialiser_gouts();

    while ((l_gouts != NULL) && (l_gouts->texte[0] != f_commandes->commande->texte[0])) {
        l_gouts = l_gouts->next;
    }

    Element_str* head = malloc(sizeof(*head));
    strcpy(head->texte, l_gouts->texte);
    head->next = NULL;
    Element_str* previous = head;
    l_gouts = initialiser_gouts();

    int i = 1;

    while (i < strlen(f_commandes->commande->texte)) {
        if (f_commandes->commande->texte[i] == l_gouts->texte[0]) {
            Element_str* link = malloc(sizeof(*link));
            strcpy(link->texte, l_gouts->texte);
            link->next = NULL;
            previous->next = link;
            previous = link;
            l_gouts = initialiser_gouts();
            i++;
        } else {
            l_gouts = l_gouts->next;
        }
    }

    Element_str* to_delete = f_commandes->commande;
    f_commandes->commande = f_commandes->commande->next;
    free(to_delete);
    f_commandes->nb_commandes--;

    return head;
}