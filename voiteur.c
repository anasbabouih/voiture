
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"../c.h"




void donne(Client c) {
    printf("Donnez id du client: ");
    scanf("%s", c.id);
    printf("Donnez le nom du client: ");
    scanf("%s", c.nom);
    printf("Donnez le prenom du client: ");
    scanf("%s", c.prenom);

}

// Function to add a car
void ajouterVoiture() {
    FILE *file = fopen("voitures.csv", "a+");
    if (file == NULL) {
        printf("Erreur d'ouverture du fichier.\n");
        return;
    }

    Voiture v;
    printf("ID : "); scanf("%d", &v.id);
    printf("Marque : "); scanf("%s", v.marque);
    printf("Modele : "); scanf("%s", v.model);
    printf("Carburant : "); scanf("%s", v.carburant);
    printf("Places : "); scanf("%d", &v.places);
    printf("Transmission (auto/manuelle) : "); scanf("%s", v.transmission);
    printf("Prix par jour : "); scanf("%f", &v.prix);
    printf("Disponibilite (oui/non) : "); scanf("%s", v.disponibilite);

    fprintf(file, "%d,%s,%s,%s,%d,%s,%.2f,%s\n", v.id, v.marque, v.model, v.carburant, v.places, v.transmission, v.prix, v.disponibilite);
    printf("Voiture ajoutee avec succes!\n");

    fclose(file);
}

// Function to display all cars
void afficherVoitures() {
    FILE *file = fopen("voitures.csv", "r");
    if (file == NULL) {
        printf("Erreur d'ouverture du fichier.\n");
        return;
    }

    Voiture v;
    printf("\n---- Liste des Voitures ----\n");
    printf("| ID |   Marque   | Modele | Carburant | Places | Transmission | Prix  | Dispo |\n");
        printf("-------------------------------------------------------------\n");
    while (fscanf(file, "%d,%49[^,],%49[^,],%19[^,],%d,%19[^,],%f,%9s\n",
                  &v.id, v.marque, v.model, v.carburant,
                  &v.places, v.transmission, &v.prix,
                  v.disponibilite) != EOF) {

        printf(" %d \t | %s | %s \t| %s \t| %d \t| %s \t| %.2f \t| %s \t\n",
               v.id, v.marque, v.model, v.carburant,
               v.places, v.transmission, v.prix,
               v.disponibilite);
    }
    printf("-------------------------------------------------------------\n");

    fclose(file);
}
void modifierVoiture() {
    FILE *file = fopen("voitures.csv", "r");
    if (file == NULL) {
        printf("Erreur d'ouverture du fichier.\n");
        return;
    }

    Voiture voitures[100];
    int n = 0, idModif, found = 0;

    // Read all cars into an array
    while (fscanf(file, "%d,%49[^,],%49[^,],%19[^,],%d,%19[^,],%f,%9s\n",
                  &voitures[n].id, voitures[n].marque, voitures[n].model,
                  voitures[n].carburant, &voitures[n].places,
                  voitures[n].transmission, &voitures[n].prix,
                  voitures[n].disponibilite) != EOF) {
        n++;
    }
    fclose(file);

    // Ask for the car ID to modify
    printf("Entrez l'ID de la voiture a modifier: ");
    scanf("%d", &idModif);

    // Search for the car and modify it
    for (int i = 0; i < n; i++) {
        if (voitures[i].id == idModif) {
            found = 1;
            printf("Nouvelle marque : "); scanf("%s", voitures[i].marque);
            printf("Nouveau modele : "); scanf("%s", voitures[i].model);
            printf("Nouveau carburant : "); scanf("%s", voitures[i].carburant);
            printf("Nombre de places : "); scanf("%d", &voitures[i].places);
            printf("Transmission (auto/manuelle) : "); scanf("%s", voitures[i].transmission);
            printf("Prix par jour : "); scanf("%f", &voitures[i].prix);
            printf("Disponibilite (oui/non) : "); scanf("%s", voitures[i].disponibilite);
            break;
        }
    }

    if (!found) {
        printf("Voiture avec ID %d non trouvee.\n", idModif);
        return;
    }

    // Write back updated cars to the file
    file = fopen("voitures.csv", "w");
    if (file == NULL) {
        printf("Erreur d'ouverture du fichier pour ecriture.\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        fprintf(file, "%d,%s,%s,%s,%d,%s,%.2f,%s\n",
                voitures[i].id, voitures[i].marque, voitures[i].model,
                voitures[i].carburant, voitures[i].places,
                voitures[i].transmission, voitures[i].prix,
                voitures[i].disponibilite);
    }
    fclose(file);

    printf("Voiture avec ID %d modifiee avec succes.\n", idModif);
}
void supprimerVoiture() {
    FILE *file = fopen("voitures.csv", "r");
    if (file == NULL) {
        printf("Erreur d'ouverture du fichier.\n");
        return;
    }

    Voiture voitures[100];
    int n = 0, idSupp, found = 0;

    // Read all cars into an array
    while (fscanf(file, "%d,%49[^,],%49[^,],%19[^,],%d,%19[^,],%f,%9s\n",
                  &voitures[n].id, voitures[n].marque, voitures[n].model,
                  voitures[n].carburant, &voitures[n].places,
                  voitures[n].transmission, &voitures[n].prix,
                  voitures[n].disponibilite) != EOF) {
        n++;
    }
    fclose(file);

    // Ask for the car ID to delete
    printf("Entrez l'ID de la voiture à supprimer: ");
    scanf("%d", &idSupp);

    // Open the file for writing (overwrite mode)
    file = fopen("voitures.csv", "w");
    if (file == NULL) {
        printf("Erreur d'ouverture du fichier pour écriture.\n");
        return;
    }

    // Write back only cars that are NOT deleted
    for (int i = 0; i < n; i++) {
        if (voitures[i].id == idSupp) {
            found = 1; // Car found, skip writing it back
        } else {
            fprintf(file, "%d,%s,%s,%s,%d,%s,%.2f,%s\n",
                    voitures[i].id, voitures[i].marque, voitures[i].model,
                    voitures[i].carburant, voitures[i].places,
                    voitures[i].transmission, voitures[i].prix,
                    voitures[i].disponibilite);
        }
    }

    fclose(file);

    if (found) {
        printf("Voiture avec ID %d supprimée avec succès.\n", idSupp);
    } else {
        printf("Voiture avec ID %d non trouvée.\n", idSupp);
    }
}

void rechercherVoiture() {
    FILE *file = fopen("voitures.csv", "r");
    if (file == NULL) {
        printf("Erreur d'ouverture du fichier.\n");
        return;
    }

    Voiture v;
    int found = 0;
    int R;

    do {
        printf("\n---- Recherche de Voitures ----\n");
        printf("1. Marque\n");
        printf("2. Disponibilite\n");
        printf("3. Quitter\n");
        printf("Entrez votre choix : ");
        scanf("%d", &R);

        switch (R) {
            case 1: {
                char marque[50];
                printf("Entrez la marque : ");
                scanf("%s", marque);
                while (fscanf(file, "%d,%49[^,],%49[^,],%19[^,],%d,%19[^,],%f,%9s\n",
                              &v.id, v.marque, v.model, v.carburant,
                              &v.places, v.transmission, &v.prix,
                              v.disponibilite) != EOF) {
                    if (strcmp(v.marque, marque) == 0) {
                        found = 1;
                        printf("ID: %d | Marque: %s | Modele: %s | Carburant: %s | Places: %d | Transmission: %s | Prix: %.2f | Disponibilite: %s\n",
                               v.id, v.marque, v.model, v.carburant,
                               v.places, v.transmission, v.prix,
                               v.disponibilite);
                    }
                }
                if (!found) {
                    printf("Aucune voiture trouvee avec la marque '%s'.\n", marque);
                }
                break;
            }

            case 2: {
             char disponibilite[10];
             printf("Entrez la disponibilite (oui/non) : ");
             scanf("%s", disponibilite);
                            while (fscanf(file, "%d,%49[^,],%49[^,],%19[^,],%d,%19[^,],%f,%9s\n",
                              &v.id, v.marque, v.model, v.carburant,
                              &v.places, v.transmission, &v.prix,
                              v.disponibilite) != EOF) {
                    if (strcmp(v.disponibilite, disponibilite) == 0) {
                        found = 1;
                        printf("ID: %d | Marque: %s | Modele: %s | Carburant: %s | Places: %d | Transmission: %s | Prix: %.2f | Disponibilite: %s\n",
                               v.id, v.marque, v.model, v.carburant,
                               v.places, v.transmission, v.prix,
                               v.disponibilite);
                    }
                }
                if (!found) {
                    printf("Aucune voiture trouvee avec la disponibilite '%s'.\n", disponibilite);
                }
                break;
            }

            case 3:
                printf("Quitter la recherche.\n");
                break;
            default:
                printf("Choix invalide. Veuillez reessayer.\n");
        }
    } while (R != 3);

    fclose(file);
}

// Function to sort cars by marque and price per day
void trierVoitures() {
    FILE *file = fopen("voitures.csv", "r");
    if (file == NULL) {
        printf("Erreur d'ouverture du fichier.\n");
        return;
    }

    Voiture voitures[100];
    int n = 0;

    // Read cars into array
    while (fscanf(file, "%d,%49[^,],%49[^,],%19[^,],%d,%19[^,],%f,%9s\n",
                  &voitures[n].id, voitures[n].marque, voitures[n].model,
                  voitures[n].carburant, &voitures[n].places,
                  voitures[n].transmission, &voitures[n].prix,
                  voitures[n].disponibilite) != EOF) {
        n++;
    }
    fclose(file);

    // Bubble sort by marque, then by prix
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(voitures[j].marque, voitures[j + 1].marque) > 0 ||
                (strcmp(voitures[j].marque, voitures[j + 1].marque) == 0 && voitures[j].prix > voitures[j + 1].prix)) {
                Voiture temp = voitures[j];
                voitures[j] = voitures[j + 1];
                voitures[j + 1] = temp;
            }
        }
    }

    // Display sorted cars
    printf("\n---- Voitures Triees par Marque et Prix ----\n");
    for (int i = 0; i < n; i++) {
        printf("ID: %d | Marque: %s | Modele: %s | Carburant: %s | Places: %d | Transmission: %s | Prix: %.2f | Disponibilite: %s\n",
               voitures[i].id, voitures[i].marque, voitures[i].model,
               voitures[i].carburant, voitures[i].places,
               voitures[i].transmission, voitures[i].prix,
               voitures[i].disponibilite);
    }
}
