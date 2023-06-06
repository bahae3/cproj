#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rendezvous.h"
#include "file_io.h"

// Constantes
#define FICHIER_RENDEZVOUS "rendezvous.bin"

// Prototypes de fonctions locales
void prendre_rendezvous();
void afficher_rendezvous();

// Implémentation des fonctions pour la gestion des rendez-vous
void gerer_rendezvous() {
    int choix;
    do {
        printf("Gestion des rendez-vous\n");
        printf("1. Prendre un rendez-vous\n");
        printf("2. Afficher la liste des rendez-vous\n");
        printf("0. Retour au menu principal\n");
        printf("Entrez votre choix : ");
        scanf("%d", &choix);
        getchar();

        switch (choix) {
            case 1:
                prendre_rendezvous();
                break;
            case 2:
                afficher_rendezvous();
                break;
            case 0:
                break;
            default:
                printf("Choix invalide. Veuillez réessayer.\n");
                break;
        }
    } while (choix != 0);
}

void prendre_rendezvous() {
    Rendezvous nouveau_rendezvous;

    printf("Entrez l'ID du patient: ");
    scanf("%d", &nouveau_rendezvous.id_patient);

    printf("Entrez la date du rendez-vous (AAAA-MM-JJ): ");
    scanf("%s", &nouveau_rendezvous.date);

    printf("Entrez l'heure du rendez-vous (HH:MM): ");
    scanf("%s", &nouveau_rendezvous.heure);

    FILE *file = fopen("rdv.txt", "w");
    fprintf(file, "id: %d\nDate: %f\nHeure: %s\n********************\n", nouveau_rendezvous.id_patient, nouveau_rendezvous.date, nouveau_rendezvous.heure);
    if(file != NULL){
        printf("Les donnees sont bien saisies.\n");
    }
    fclose(file);

}

void afficher_rendezvous() {
    FILE *file = fopen("rdv.txt", "r");
    char chars[300] = "";
    if (file == NULL) {
        printf("Le fichier est vide. Il n'y a pas de rdv.");
    }
    else{
        while(fgets(chars, 300, file) != NULL){
            printf("Les infos des rdv:\n%s", chars);
        }
    }
    fclose(file);
}
