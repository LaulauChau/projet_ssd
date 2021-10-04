//
// Created by Laurent Chau on 04/10/2021.
//

#ifndef PROJET_CORE_H
#define PROJET_CORE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Element_str {
    char texte[50];
    struct Element_str* next;
} Element_str;

typedef struct Pile_Gouts {
    // TODO
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
    struct Element_gtx* current;
    struct File_Commandes* next;
} File_Commandes;

typedef struct File_Degustation {
    // TODO
    struct Element_gtx* current;
    struct File_Degustation* next;
} File_Degustation;

Element_str* l_gouts; // Liste de gouts a disposition
File_Commandes* f_commandes; // File de commandes
File_Degustation* f_degustation; // File de degustation

Element_str* initialiser_gouts();

#endif //PROJET_CORE_H
