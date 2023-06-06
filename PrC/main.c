#include <stdio.h>
#include <stdlib.h>
#include "patient.h"
#include "rendezvous.h"
#include "traitement.h"
#include "facturation.h"

void afficher_menu() {
    printf("\nMenu principal :\n");
    printf("1. Gerer les patients\n");
    printf("2. Gerer les rendez-vous\n");
    printf("3. Gerer les traitements\n");
    printf("4. Gerer la facturation\n");
    printf("5. Quitter\n");
}

int main() {
    int choix;

    do {
        afficher_menu();
        printf("Choisissez une option : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                gerer_patients();
                break;
            case 2:
                gerer_rendezvous();
                break;
            case 3:
                gerer_traitements();
                break;
            case 4:
                gerer_facturation();
                break;
            case 5:
                printf("Au revoir !\n");
                break;
            default:
                printf("Option invalide, veuillez réessayer.\n");
        }
    } while (choix != 5);

    return 0;
}
