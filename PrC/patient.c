#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "patient.h"
#include "file_io.h"

// Constantes
#define FICHIER_PATIENTS "patients.bin"

// Prototypes de fonctions locales
void ajouter_patient();
void afficher_patients();

// Implémentation des fonctions pour la gestion des patients
void gerer_patients(){
    int choix;
    do {
        printf("Gestion des patients\n");
        printf("1. Ajouter un patient\n");
        printf("2. Afficher la liste des patients\n");
        printf("0. Retour au menu principal\n");
        printf("Entrez votre choix : ");
        scanf("%d", &choix);
        //getchar();

        switch (choix){
            case 1:
                ajouter_patient();
                break;
            case 2:
                afficher_patients();
                break;
            case 0:
                break;
            default:
                printf("Choix invalide. Veuillez réessayer.\n");
                break;
        }
    }while (choix != 0);
}

void ajouter_patient() {
    Patient nouveau_patient;

    printf("Entrez l'ID du patient: ");
    scanf("%d", &nouveau_patient.id);

    printf("Entrez le nom du patient: ");
    scanf("%s", &nouveau_patient.nom);

    printf("Entrez le prénom du patient: ");
    scanf("%s", &nouveau_patient.prenom);

    printf("Entrez la date de naissance du patient (AAAA-MM-JJ): ");
    scanf("%s", &nouveau_patient.date_naissance);

    ecrire_donnees("patients.txt", nouveau_patient);
}

void afficher_patients() {
    lire_donnees("patients.txt");
}
