#include "core.h"

int main() {
    Element_str* Chocolat = initialiser_gouts("chocolat");

    printf("%s", Chocolat->texte);

    free(Chocolat);

    return 0;
}
