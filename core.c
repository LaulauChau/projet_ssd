//
// Created by Laurent Chau on 04/10/2021.
//

#include "core.h"

Element_str* initialiser_gouts() {
    /* On cree une liste chainee accueillant la collection de gouts
     *
     * Arguments :
     *
     * Retours :
     *     Premier maillon de la liste chainee
     */
    char liste_gouts[MIN][MAX] = {"Chocolat", "Vanille", "Fraise", "Abricot", "Pomme", "Banane", "Myrtille"};
    // On commence par initialiser le premier maillon de la LSC
    Element_str* head = malloc(sizeof(*head));
    strcpy(head->texte, liste_gouts[0]);
    head->next = NULL;
    // On stock le maillon actuel comme etant le precedent
    Element_str* previous = head;

    for (int i = 1; i < strlen((const char *) liste_gouts) - 1; i++) {
        // On cree les autres maillons
        Element_str* link = malloc(sizeof(*link));
        strcpy(link->texte, liste_gouts[i]);
        link->next = NULL;
        // On pointe la variable next du maillon precedent vers le maillon actuel
        previous->next = link;
        previous = link;
    }
    return head;
}

void passer_commande(char commande[50], File_Commandes* f_commandes) {
    /* Le client passe une commande qui sera ajoutee a la file de commande
     *
     * Arguments :
     *      commande : chaine de caractere, le client specifie les gouts qu'il voudra dans son gateau
     *      f_commandes : file des commandes
     *
     * Retours :
     */

    // 10 commandes maximum dans la file
    if (f_commandes->nb_commandes >= 10) {
        return;
    }

    // On cree la commande du client
    Element_str* nouv_commande = malloc(sizeof(*nouv_commande));
    strcpy(nouv_commande->texte, commande);
    nouv_commande->next = NULL;

    if (f_commandes->nb_commandes != 0) {   // S'il y a au moins 1 commande dans la file, on enfile a la suite
        Element_str* commande_actuel = f_commandes->commande;

        while (commande_actuel->next != NULL) {
            commande_actuel = commande_actuel->next;
        }

        commande_actuel->next = nouv_commande;
    } else {    // Sinon notre commande devient le premier element
        f_commandes->commande = nouv_commande;
    }

    // On incremente le nombre total de commande
    f_commandes->nb_commandes++;
}

Element_str* traiter_commande(File_Commandes* f_commandes) {
    /* Recupere une commande de la file pour la traiter
     *
     * Arguments :
     *      f_commandes : file des commandes
     *
     * Retour :
     *      Structure contenant notre commande
     */

    // Verifie s'il y a au moins une commande
    if (f_commandes->nb_commandes == 0) {
        return NULL;
    }

    Element_str* head = malloc(sizeof(*head));
    head->texte[0] = f_commandes->commande->texte[0];
    head->texte[1] = '\0';
    head->next = NULL;
    Element_str* previous = head;

    for (int i = 1; i < strlen(f_commandes->commande->texte); i++) {
        Element_str* link = malloc(sizeof(*link));
        link->texte[0] = f_commandes->commande->texte[i];
        link->texte[1] = '\0';
        link->next = NULL;
        previous->next = link;
        previous = link;
    }

    // On defile la liste de commande
    Element_str* to_delete = f_commandes->commande;
    f_commandes->commande = f_commandes->commande->next;
    free(to_delete);

    f_commandes->nb_commandes--;

    return head;
}

void construire_gateau(Gateau* gateau, Element_str* l_gouts) {
    /* On construit le gateau a partir d'une commande
     *
     * Arguments :
     *      gateau : gateau avec un nom de commande et une pile de gout
     *      l_gouts : commande traiter
     *
     * Retour :
     */

    // On recupere la liste de gout de reference
    Element_str* liste_gouts = initialiser_gouts();

    // Verifie si la command existe
    if (gateau == NULL || l_gouts == NULL) {
        return;
    }

    int i = 0;
    while (l_gouts != NULL) {
        gateau->commande->texte[i] = l_gouts->texte[0];
        // Si la lettre de la commande correspond au gout
        while (l_gouts->texte[0] != liste_gouts->texte[0]) {
            liste_gouts = liste_gouts->next;
        }
        // On empile le gout
        Pile_Gouts* nouv_gout = malloc(sizeof(*nouv_gout));
        strcpy(nouv_gout->texte, liste_gouts->texte);
        nouv_gout->next = gateau->p_gouts;
        gateau->p_gouts = nouv_gout;
        i++;
        l_gouts = l_gouts->next;
        // Reinitialise la liste de gout de reference
        liste_gouts = initialiser_gouts();
    }

    gateau->commande->texte[i] = '\0';
}

void livrer(Gateau* gateau, File_Degustation* f_degustation) {
    /* Enfile un gateau dans la file de degustation
     *
     * Arguments :
     *      gateau : gateau cree
     *      f_degustation : file de degustation
     *
     * Retour :
     */

    if (gateau == NULL || f_degustation == NULL) {
        return;
    }

    Element_gtx* nouveau = malloc(sizeof(*nouveau));
    nouveau->gateau = gateau;
    nouveau->next = NULL;
    // On verifie s'il y a au moins un element dans la file
    if (f_degustation->data != NULL) {
        Element_gtx* actuel = f_degustation->data;

        while (actuel->next != NULL) {
            actuel = actuel->next;
        }

        actuel->next = nouveau;
    } else { // Sinon notre gateau est le premier element
        f_degustation->data = nouveau;
    }
}

void degustation(File_Degustation* f_degustation, int nb_parts) {
    /* Le client va deguster les gateaux dans la file de degustation
     *
     * Arguments :
     *      f_degustation : file de degustation
     *      nb_parts : nombre de part que le client va manger part gateau
     *
     * Retour :
     */

    if (f_degustation == NULL) {
        return;
    }
    // On stock le nombre de part
    int parts = nb_parts;

    while (f_degustation->data != NULL) {
        // On defile la pile de gout en fonction du nombre de part
        while (nb_parts-- && f_degustation->data->gateau->p_gouts != NULL) {
            Pile_Gouts* a_deguster = f_degustation->data->gateau->p_gouts;
            f_degustation->data->gateau->p_gouts = f_degustation->data->gateau->p_gouts->next;
            free(a_deguster);
        }

        // Si le client a fini le gateau on passe on suivant
        if (f_degustation->data->gateau->p_gouts == NULL) {
            f_degustation->data = f_degustation->data->next;
            nb_parts = parts;
        } else if (nb_parts == 0 && f_degustation->data->gateau->p_gouts != NULL) { // Si le client n'a pas fini le gateau, il devra le finir avant de passe au suivant
            nb_parts = parts;
        }
    }
}