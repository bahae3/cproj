#ifndef TRAITEMENT_H
#define TRAITEMENT_H

typedef struct {
    int id_patient;
    char description[100];
    float lecout;
} Traitement;

void gerer_traitements();
void ajouter_traitement();
void afficher_traitements();

#endif
