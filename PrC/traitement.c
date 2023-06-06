#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "traitement.h"
#include "file_io.h"

// Constantes
#define FICHIER_TRAITEMENTS "traitements.bin"

// Prototypes de fonctions locales
void ajouter_traitement();
void afficher_traitements();

// Implémentation des fonctions pour la gestion des traitements
void gerer_traitements() {
    int choix;
    do {
        printf("Gestion des traitements\n");
        printf("1. Ajouter un traitement\n");
        printf("2. Afficher la liste des traitements\n");
        printf("0. Retour au menu principal\n");
        printf("Entrez votre choix : ");
        scanf("%d", &choix);
        getchar();

        switch (choix) {
            case 1:
                ajouter_traitement();
                break;
            case 2:
                afficher_traitements();
                break;
            case 0:
                break;
            default:
                printf("Choix invalide. Veuillez réessayer.\n");
                break;
        }
    } while (choix != 0);
}

void ajouter_traitement() {
    Traitement nouveau_traitement;

    printf("Entrez l'ID du patient: ");
    scanf("%d", &nouveau_traitement.id_patient);

    printf("Entrez la description du traitement: ");
    scanf("%s", &nouveau_traitement.description);

    printf("Entrez le coût du traitement: ");
    scanf("%f", &nouveau_traitement.lecout);

    FILE *file = fopen("traitement.txt", "w");
    fprintf(file, "id: %d\nDescription: %s\nCout: %f\n********************\n", nouveau_traitement.id_patient, nouveau_traitement.description, nouveau_traitement.lecout);
    if(file != NULL){
        printf("Les donnees sont bien saisies.\n");
    }
    fclose(file);

}

void afficher_traitements() {
    FILE *file = fopen("traitement.txt", "r");
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
