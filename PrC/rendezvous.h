#ifndef RENDEZVOUS_H
#define RENDEZVOUS_H

typedef struct {
    int id_patient;
    char date[11]; // AAAA-MM-JJ et le caract�re de fin de cha�ne '\0'
    char heure[6]; // HH:MM et le caract�re de fin de cha�ne '\0'
} Rendezvous;

void gerer_rendezvous();
void prendre_rendezvous();
void afficher_rendezvous();

#endif
