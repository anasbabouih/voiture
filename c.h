#ifndef C_H_INCLUDED
#define C_H_INCLUDED
typedef struct {
    char id[50];
    char nom[50];
    char prenom[50];
} Client;

typedef struct {
    int id;
    char marque[50];
    char model[50];
    char carburant[20];
    int places;
    char transmission[20];
    float prix;
    char disponibilite[10];
} Voiture;


void donne(Client c);
void ajouterVoiture();
void afficherVoitures();
void modifierVoiture();
void supprimerVoiture();
void rechercherVoiture();
void trierVoitures();


#endif // C_H_INCLUDED
