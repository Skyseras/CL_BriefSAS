#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct info_compte{
   char client_nom_prenom[30];
   int client_cin;
   float montant;
}info_compte;

typedef struct test{
    char client_nom_prenom[30];
    int client_cin;
    float montant;
}test;

int index_compte_general=0;

void ajouter(info_compte liste[80], int s){
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

void afficher(info_compte liste[80], int s){
    int i;
    printf("\n\n***CIN***\t***Nom / Prenom***\t***Montant***\n");
    for (i = 0; i < s; i++){
        printf("%d\t        %s\t        %f\n", liste[i].client_cin, liste[i].client_nom_prenom,
            liste[i].montant);
    } 
}

int chercher(info_compte liste[80], int x, int cin){
    int i;

    for (i = 0; i < x; i++){
        if (liste[i].client_cin == cin){
            return i;
        } 
    }
    return  - 1;
}

void deposer(info_compte liste[], int x, int cin, int m){
    int i = chercher(liste, x, cin);
    if (i ==  - 1){
        printf("Pas de compte pour ce CIN.");
    } 
    else{
        liste[i].montant += m;
    }
}

void retirer(info_compte liste[], int x, int cin, int m){
    int i = chercher(liste, x, cin);
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

void trierCroissant(info_compte liste[])
{
    int i;
    int j;
    for(i = 1; i < index_compte_general; i++)
    {
        for(j = i + 1; j < index_compte_general + 1; j++)
        {
            if(liste[i].montant > liste[j].montant)
            {
                liste[20] = liste[i];
                liste[i] = liste[j];
                liste[j] = liste[20];
            }
        }
    }
}

int main()
{
    info_compte data[20];
    int n, option, compte_cin, xmontant, index;

    printf("******** Banque Youcode 'BIENVENUE' ********\n\n");
    printf("Notre banque ne dispose d'aucun client, combien voulez vous ajouter? : ");
    scanf("%d", &n);
    ajouter(data, n);
    do
    {

        printf("\n1. Ajoutez un nouveau compte \n");
        printf("2. Ajoutez plusieurs comptes \n");
        printf("3. Afficher tout les comptes \n");
        printf("4. Afficher mon compte/solde \n");
        printf("5. Depot argent \n");
        printf("6. Retrait argent \n");
        printf("7. Afficher croissant \n");
        printf("0. Quitter application \n\n");
        printf("\nEntrez une option (0-7) : ");
        scanf("%d", &option);
        switch (option){
            case 1:
                n=1;
                ajouter(data, n);
                break;
            case 2:
                printf("Combien voulez vous ajouter? : ");
                scanf("%d", &n);
                ajouter(data, n);
                break;
            case 3:
                afficher(data, index_compte_general);
                break;
            case 4:
                printf("Entrez CIN : ");
                scanf("%d", &compte_cin);
                index = chercher(data, index_compte_general, compte_cin);
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
                deposer(data, index_compte_general, compte_cin, xmontant);
                break;
            case 6:
                printf("Entrez CIN : ");
                scanf("%d", &compte_cin);
                printf("Entrez le montant a retirer : ");
                scanf("%d", &xmontant);
                retirer(data, index_compte_general, compte_cin, xmontant);
                break;
            case 7:
                trierCroissant(data);
                break;
        }
        printf("\nEntrer pour continuer...");
        getch();
    }
    while (option != 0);

    return 0;
}