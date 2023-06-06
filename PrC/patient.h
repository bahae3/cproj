#ifndef PATIENT_H
#define PATIENT_H

typedef struct {
    int id;
    char nom[50];
    char prenom[50];
    char date_naissance[11]; // AAAA-MM-JJ
} Patient;

void gerer_patients();
void ajouter_patient();
void afficher_patients();

#endif
