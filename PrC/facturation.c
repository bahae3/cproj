#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "facturation.h"
#include "file_io.h"

// Constantes
#define FICHIER_FACTURES "factures.bin"

// Prototypes de fonctions locales
void creer_facture();
void afficher_factures();

// Implémentation des fonctions pour la gestion de la facturation
void gerer_facturation() {
    int choix;
    do {
        printf("Gestion de la facturation\n");
        printf("1. Créer une facture\n");
        printf("2. Afficher la liste des factures\n");
        printf("0. Retour au menu principal\n");
        printf("Entrez votre choix : ");
        scanf("%d", &choix);
        getchar();

        switch (choix) {
            case 1:
                creer_facture();
                break;
            case 2:
                afficher_factures();
                break;
            case 0:
                break;
            default:
                printf("Choix invalide. Veuillez réessayer.\n");
                break;
        }
    } while (choix != 0);
}

void creer_facture() {
    Facture nouvelle_facture;

    printf("Entrez l'ID du patient: ");
    scanf("%d", &nouvelle_facture.id_patient);

    printf("Entrez le montant de la facture: ");
    scanf("%f", &nouvelle_facture.montant);

    printf("Entrez la date de la facture (AAAA-MM-JJ): ");
    scanf("%s", &nouvelle_facture.date);

    FILE *file = fopen("facture.txt", "w");
    fprintf(file, "id: %d\nMontant: %f\nDate: %s\n********************\n", nouvelle_facture.id_patient, nouvelle_facture.montant, nouvelle_facture.date);
    if(file != NULL){
        printf("Les donnees sont bien saisies.\n");
    }
    fclose(file);

}

void afficher_factures() {
    FILE *file = fopen("facture.txt", "r");
    char chars[300] = "";
    if (file == NULL) {
        printf("Le fichier est vide. Il n'y a pas de facturation.");
    }
    else{
        while(fgets(chars, 300, file) != NULL){
            printf("Les infos des facture:\n%s", chars);
        }
    }
    fclose(file);
}
