#ifndef FACTURATION_H
#define FACTURATION_H

typedef struct {
    int id_patient;
    float montant;
    char date[11]; // AAAA-MM-JJ et le caractère de fin de chaîne '\0'
} Facture;

void gerer_facturation();
void creer_facture();
void afficher_factures();

#endif
