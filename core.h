//
// Created by Laurent Chau on 04/10/2021.
//

#ifndef PROJET_CORE_H
#define PROJET_CORE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN 100
#define MAX 100

typedef struct Element_str {
    char texte[50];
    struct Element_str* next;
} Element_str;

typedef struct Pile_Gouts {
    // TODO
    struct Element_str* l_gouts; // Liste de gouts a disposition
} Pile_Gouts;

typedef struct Gateau {
    struct Element_str* commande;
    struct Pile_Gouts* p_gouts;
} Gateau;

typedef struct Element_gtx {
    struct Gateau* gateau;
    struct Element_gtx* next;
} Element_gtx;

typedef struct File_Commandes {
    // TODO
    struct Element_str* commande;
    int nb_commandes;
} File_Commandes;

typedef struct File_Degustation {
    // TODO
    struct Element_gtx* data;
} File_Degustation;

Element_str* initialiser_gouts();
void passer_commande(char commande[50], File_Commandes* f_commandes);
Element_str* traiter_commande(File_Commandes* f_commandes);

#endif //PROJET_CORE_H
