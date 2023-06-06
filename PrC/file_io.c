#include <stdio.h>
#include <stdlib.h>
#include "file_io.h"
#include "patient.h"

void ecrire_donnees(char filename[50], Patient p){
    FILE *file = fopen(filename, "a");
    fprintf(file, "id: %d\nNom: %s\nPrenom: %s\nDate de naissance: %s\n********************\n", p.id, p.nom, p.prenom, p.date_naissance);
    if(file != NULL){
        printf("Les donnees sont bien saisies.\n");
    }
    fclose(file);
}

void lire_donnees(char filename){
    FILE *file = fopen(filename, "r");
    char chars[300] = "";
    if (file == NULL) {
        printf("Le fichier est vide. Il n'y a pas de patient.");
    }
    else{
        while(fgets(chars, 300, file) != NULL){
            printf("Les infos des patients:\n%s", chars);
        }
    }
}
