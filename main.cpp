#include <stdio.h>
#include <string>	//pour manipuler les chaines de caractères
#include <string.h>

#define TAILLE 2

typedef struct Ddn {// Pour stocker notre date de naissance

	int n_jour = 0;
	int n_mois = 0;
	int n_annee = 0;
}ddn;

typedef struct adresse {// Pour stocker notre adresse

	char* str_rue = nullptr;
	char* str_cp = nullptr;
	char* str_ville = nullptr;

}adrs;

typedef enum class civ { M, Mme } civ;

typedef struct CID {//pour stocker toute la carte d'identitée

	int n_id;
	civ E_civ;
	char* str_nom;
	char* str_prenom;
	ddn* t_ddn;
	adrs* t_adr;

}cid;

void saisirCid(cid* tab_cid);//cette fonction permet de saisir les données entrées par l'utilisateur
void afficheCid(cid* tab_cid);//cette fonction permet d'afficher les données saisies par l'utilisateur

int main() {
	cid* tab_cid = nullptr;
	tab_cid = (cid*)malloc(TAILLE * sizeof(cid));//on crée un tableau où on stock toutes les données saisie par l'utilisateur

	saisirCid(tab_cid);
	afficheCid(tab_cid);

	free(tab_cid);//on efface les données entrées

	tab_cid = nullptr;

	return 0;
}


void saisirCid(cid* tab_cid) {


	int n_id2 = 0;
	civ E_civ2 = civ::M;
	char* str_nom2 = nullptr;
	char* str_prenom2 = nullptr;
	ddn* t_ddn2 = { 0 };
	adrs* t_adr2 = nullptr;




	for (int n_i = 0; n_i < TAILLE; n_i++) {//pour chaque personne, on saisie leur donnéee.

		printf_s("Entrez votre id (nb) : \n");
		scanf_s("%d", &n_id2);
		printf_s("Entrez votre civilite : \n");
		scanf_s("%d", &E_civ2);
		printf_s("Entrez votre nom : \n");
		scanf_s("%s", &str_nom2);
		fflush(stdin);
		printf_s("Entrez votre prenom : \n");
		scanf_s("%s", &str_prenom2);
		fflush(stdin);
		printf_s("Entrez votre date de naissance : \n");
		scanf_s("%d", &t_ddn2);
		
		printf_s("Entrez votre adresse (rue, cp, ville) : \n\n\n");
		scanf_s("%s", &t_adr2);


		fflush(stdin);

		

	}
}


void afficheCid(cid * tab_cid) {


	printf_s("\nAffichage de la carte id : \n");

	for (int n_i = 0; n_i < TAILLE; n_i++) {//on affiche les données de chaque utilisateurs.

		if (tab_cid != nullptr) {
			printf_s("id : %d\n", tab_cid[n_i].n_id);
			printf_s("civ : %d\n", tab_cid[n_i].E_civ);
			printf_s("Nom : %s\n", tab_cid[n_i].str_nom);
			printf_s("Prenom : %s\n", tab_cid[n_i].str_prenom);
			printf_s("Date de Naissance : %d\n", tab_cid[n_i].t_ddn);
			printf_s("Adresse : %s\n", tab_cid[n_i].t_adr);

		}

	}
}
