#include <stdio.h>
#include <stdlib.h>
#include "headers/struct.h"
#include "headers/file.h"
#include "headers/list.h"


//Fonctions/Procédures

int scan(void) {
	int c;
	printf("Voulez vous:\n1 - Afficher tous les employés\n2 - Ajouter un nouvel employé\n3 - Quitter le programme\n");
	scanf("%d", &c);
	if (c != 1 && c!=2 && c!=3) {
		printf("Veuillez entrer 1, 2 ou 3\n");
		scanf("%d", &c);
	}
	return c;
}






int main() {
	struct start *f;
	if ((f = init()) == NULL) {
		printf("Erreur d'allocation\n");
		return 0;
	}
	read(f);

	int choix, a;
	while ((choix = scan()) != 3) {
		if (choix == 1) {
			//Parcours de la liste, affichage des employés
			parcours(f);
		}
		else if (choix == 2) {
			if ((a = ajout(f)) == 1) {
				return 0;
			}
			else if (a == 2) {
				return 0;
			}
			printf("Ajout effectué avec succès\n");
		}
		}
		printf("Au revoir!\n");
	}

