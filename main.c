#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../c.h"

int main() {
    Client clientData;
    donne(clientData);

    int choix;
    do {
        printf("\n---- Gestion de Location de Voitures ----\n");
        printf("1. Ajouter une voiture\n");
        printf("2. Afficher les voitures\n");
        printf("3. Rechercher une voiture\n");
        printf("4. Trier les voitures\n");
        printf("5. Supprimer une voiture\n");
        printf("6. Modifier une voiture\n");  // Added missing newline
        printf("7. Quitter\n");
        printf("Entrez votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                ajouterVoiture();
                break;
            case 2:
                afficherVoitures();
                break;
            case 3:
                rechercherVoiture();
                break;
            case 4:
                trierVoitures();
                break;
            case 5:
                supprimerVoiture();
                break;
            case 6:
                modifierVoiture();
                break;
            case 7:
                printf("Au revoir!\n");
                break;
            default:
                printf("Choix invalide. Veuillez réessayer.\n");
        }
    } while (choix != 7);

    return 0;
}
