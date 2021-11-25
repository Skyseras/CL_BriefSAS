#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct info_compte2{
   char client_nom_prenom[30];
   int client_cin;
   float montant;
}info_compte;

info_compte liste[500];

int index_compte_general=0;

void ajouter(int s){
    int i;
    for (i = 0; i < s; i++){
        printf("\nCreation du compte #%d", index_compte_general + 1);

        printf("\nEntrez le CIN : ");
        scanf("%d", &liste[index_compte_general].client_cin);
        fflush(stdin);
        printf("Entrez le nom et prenom : ");
        gets(liste[index_compte_general].client_nom_prenom);
        liste[index_compte_general].montant = 0;
        index_compte_general++;
    } 
}

void afficher(int s, int min){
    int i;
    printf("\n\n***CIN***\t***Nom / Prenom***\t***Montant***\n");
    for (i = 0; i < s; i++){
        if (liste[i].montant >= min)
        printf("%d\t        %s\t        %f\n", liste[i].client_cin, liste[i].client_nom_prenom,
            liste[i].montant);
    } 
}

int chercher(int x, int cin){
    int i;

    for (i = 0; i < x; i++){
        if (liste[i].client_cin == cin){
            return i;
        } 
    }
    return  - 1;
}

void deposer(int x, int cin, int m){
    int i = chercher(x, cin);
    if (i ==  - 1){
        printf("Pas de compte pour ce CIN.");
    } 
    else{
        liste[i].montant += m;
    }
}

void retirer(int x, int cin, int m){
    int i = chercher(x, cin);
    if (i ==  - 1){
        printf("Pas de compte pour ce CIN.\n");
    } 
    else if (liste[i].montant < m){
        printf("FOND INSUFFISANT.\n");
    }
    else{
        liste[i].montant -= m;
    }
}

void trierCroissant()
{
    int i;
    int j;
    
    info_compte tmp;
    for(i = 0; i < index_compte_general; i++)
    {
        for(j = 0; j < index_compte_general; j++)
        {
            if(liste[j+1].client_cin && liste[j].montant > liste[j+1].montant)
            {
                tmp = liste[j];
                liste[j] = liste[j + 1];
                liste[j + 1] = tmp;
            }
        }
    }
}

void trierDecroissant()
{
    int i;
    int j;
    info_compte tmp;
    for(i = 0; i < index_compte_general; i++)
    {
        for(j = 0; j < index_compte_general; j++)
        {
            if(liste[j+1].client_cin && liste[j].montant < liste[j+1].montant)
            {
                tmp = liste[j];
                liste[j] = liste[j + 1];
                liste[j + 1] = tmp;
            }
        }
    }
}

void fd(){
    trierDecroissant();
    if (liste[0].client_nom_prenom)
        liste[0].montant *= 1.013;
    if (liste[1].client_nom_prenom)
        liste[1].montant *= 1.013;
    if (liste[2].client_nom_prenom)
        liste[2].montant *= 1.013;
    printf("Fidelisation activer avec succee!");
}

int main()
{
    info_compte data[20];
    int n, option, compte_cin, xmontant, index;

    printf("******** Banque Youcode 'BIENVENUE' ********\n\n");
    printf("Notre banque ne dispose d'aucun client, combien voulez vous ajouter? : ");
    scanf("%d", &n);
    ajouter(n);
    do
    {

        printf("\n1. Ajoutez un nouveau compte \n");
        printf("2. Ajoutez plusieurs comptes \n");
        printf("3. Afficher tout les comptes \n");
        printf("4. Afficher mon compte/solde \n");
        printf("5. Depot argent \n");
        printf("6. Retrait argent \n");
        printf("7. Trier croissant a un montant \n");
        printf("8. Trier decroissant a un montant \n");
        printf("9. Activer la fidelisation. \n");
        printf("0. Quitter application \n\n");
        printf("\nEntrez une option (0-9) : ");
        scanf("%d", &option);
        switch (option){
            case 1:
                n=1;
                ajouter(n);
                break;
            case 2:
                printf("Combien voulez vous ajouter? : ");
                scanf("%d", &n);
                ajouter(n);
                break;
            case 3:
                afficher(index_compte_general, 0);
                break;
            case 4:
                printf("Entrez CIN : ");
                scanf("%d", &compte_cin);
                index = chercher(index_compte_general, compte_cin);
                if (index ==  - 1)
                {
                    printf("Pas de compte avec ce CIN.");
                }
                else
                {
                    printf("CIN : %d\nNom et Prenom: %s\nMontant: %f\n",
                        data[index].client_cin, data[index].client_nom_prenom,
                        data[index].montant);
                }
                break;
            case 5:
                printf("Entrez CIN : ");
                scanf("%d", &compte_cin);
                printf("Entrez le montant a deposer : ");
                scanf("%d", &xmontant);
                deposer(index_compte_general, compte_cin, xmontant);
                break;
            case 6:
                printf("Entrez CIN : ");
                scanf("%d", &compte_cin);
                printf("Entrez le montant a retirer : ");
                scanf("%d", &xmontant);
                retirer(index_compte_general, compte_cin, xmontant);
                break;
            case 7:
                int m;
                scanf("%d", &m);
                printf("Donner le montant : ");
                trierCroissant();
                afficher(index_compte_general, m);
                break;
            case 8:
                int m2;
                printf("Donner le montant : ");
                scanf("%d", &m2);
                trierDecroissant();
                afficher(index_compte_general, m2);
                break;
            case 9:
                fd();
                break;
        }
        printf("\nEntrer pour continuer...");
        getch();
    }
    while (option != 0);

    return 0;
}