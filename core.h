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
    char texte[50];
    struct Pile_Gouts* next;
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
void construire_gateau(Gateau* gateau, Element_str* l_gouts);
void livrer(Gateau* gateau, File_Degustation* f_degustation);
void degustation(File_Degustation* f_degustation, int nb_parts);

#endif //PROJET_CORE_H
