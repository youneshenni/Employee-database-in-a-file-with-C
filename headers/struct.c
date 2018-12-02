#include <stdio.h>
#include <stdlib.h>
//Structures
//Structure Employé
struct start {
	struct element *suivant;
};

struct employe {
	char nom[30];
	char prenom[30];
	int age;
	char adresse[30];
	int salaire;	
};
struct element {
	struct employe agent;
	struct element *suivant;
};

struct element* creer(struct start *f) {
	struct element *e;
	if ((e = (struct element*)malloc(sizeof(struct element))) == NULL) {
		printf("Erreur d'allocation\n");
		return NULL;
	} else {
		printf("Ajout d'un nouvel employé:\nVeuillez entrer:\nNom: ");
		scanf("%s", e->agent.nom );
		printf("Prenom: ");
		scanf("%s", e->agent.prenom );
		printf("Age: ");
		scanf("%d", &(e->agent.age) );
		printf("Adresse: ");
		scanf("%s", e->agent.adresse );
		printf("Salaire: ");
		scanf("%d", &(e->agent.salaire) );
		e->suivant = NULL;
		return e;
	}
}

void afficher_employe(struct employe *this) {
	printf("\nEmployé:\n---------------\nNom: %s\nPrénom: %s\nAge: %d\nAdresse:%s\nSalaire: %d", this->nom, this->prenom, this->age, this->adresse, this->salaire);

}




