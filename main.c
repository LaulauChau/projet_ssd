#include "core.h"

int main() {
    File_Commandes* f_commandes = malloc(sizeof(*f_commandes));
    f_commandes->commande = malloc(sizeof(*f_commandes->commande));
    f_commandes->nb_commandes = 0;
    passer_commande("CMVP", f_commandes);

    printf("%s - %d\n", f_commandes->commande->texte, f_commandes->nb_commandes);
    Element_str* commande = traiter_commande(f_commandes);
    while (commande != NULL) {
        printf("%s\n", commande->texte);
        commande = commande->next;
    }

    printf("%s - %d\n", f_commandes->commande->texte, f_commandes->nb_commandes);
    return 0;
}
