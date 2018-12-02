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
void afficher_employe(struct employe *this);
struct element* creer(struct start *f);