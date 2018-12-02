#include <stdlib.h>
#include <stdio.h>
#include "list.h"
#include "struct.h"
//Liste chaînée

//Début


//Initialisation
struct start* init() {
	struct start *f;
	if ((f = malloc(sizeof(struct start))) != NULL) {
		f->suivant = NULL;
		return f;
	}
	else {
		printf("Erreur d'allocation");
		return NULL;
	}
}

//Obtention du dernier element de la liste


struct element* last(struct start *f) {
	struct element *e;
	e = f->suivant;
	if (e == NULL) {
	}
	while (e->suivant != NULL) {
		e = e->suivant;
	}
	return e;
}

void parcours(struct start *f) {
	struct element *e;
	e = f->suivant;
	do {
		printf("Nom: %s, Prénom: %s, Age:%d, Adresse: %s, Salaire: %d\n", e->agent.nom, e->agent.prenom, e->agent.age, e->agent.adresse, e->agent.salaire);
	} while ((e = e->suivant) != NULL);
}
