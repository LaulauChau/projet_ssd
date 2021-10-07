#include "core.h"

int main() {
    //char liste_gouts[MIN][MAX] = {"Chocolat", "Vanille", "Fraise", "Abricot", "Pomme", "Banane", "Myrtille"};
    Element_str* root = initialiser_gouts();
    while (root != NULL) {
        printf("%s\n", root->texte);
        root = root->next;
    }
    free(root);
    return 0;
}
