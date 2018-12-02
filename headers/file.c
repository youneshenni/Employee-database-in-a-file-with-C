//Lecture
#include <stdio.h>
#include "struct.h"
#include "file.h"
#include <stdlib.h>
#include "list.h"

int read(struct start *f) {
	int count;
	struct element *e;
	FILE *file;
	struct element *latest;
	if ((file = fopen("data.csv", "r")) != NULL) {
		if ((e = (struct element*)malloc(sizeof(struct element))) != NULL) {
			e->suivant = NULL;
			while ((count = fscanf(file, "%s", e->agent.nom)) != EOF) {
				fscanf(file, "%s", e->agent.prenom);
				fscanf(file, "%d", &(e->agent.age));
				fscanf(file, "%s", e->agent.adresse);
				fscanf(file, "%d", &(e->agent.salaire));
				//Link it to latest element of the List
				if (f->suivant != NULL) {
					latest = last(f);
					latest->suivant = e;
				} else {
					f->suivant = e;
				}
				
				//Create new element
				if ((e = (struct element*)malloc(sizeof(struct element))) == NULL) {
					printf("Erreur d'allocation");
					fclose(file);
					return 1;
				}
			}
			fclose(file);
			return 0;
		} else {
			printf("Erreur d'allocation");
			return 1;
		}
	} else {
		printf("\nErreur lors de l'ouverture du fichier data.csv ou fichier introuvable, Il n'y a pas d'employés");
		return 2;
	}
}


int ajout(struct start *f) {
	struct element* e;
	if ((e = creer(f)) == NULL) {
		printf("Erreur d'allocation");
		return 1;
	}
	else {
		last(f)->suivant = e;
	}
	FILE* file;
	if ((file = fopen("data.csv", "a")) == NULL) {
		printf("Erreur d'ouverture du fichier data.csv");
		return 2;
	} else {
		fprintf(file, "\n%s %s %d %s %d", e->agent.nom, e->agent.prenom, e->agent.age, e->agent.adresse, e->agent.salaire);
		return 0;
	}
}