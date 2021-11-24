#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

int chercherCompteParCin(char cin[]);
struct info_compte
{
   char client_nom[30];
   char client_prenom[30];
   char client_cin[10];
   float fond_base;     
};
struct info_compte tcompte[100];

int CompteDispo=0;

void menu(){
   printf("\n1. Creer un nouveau compte \n");
   printf("2. Creer plusieurs comptes \n");
   printf("3. Afficher mon compte/solde \n");
   printf("4. Depot argent \n");
   printf("5. Retrait argent \n");
   printf("6. Rechercher les comptes par CIN \n");
   printf("7. Quitter application \n\n");
}

void compte(){
   printf("\nEntrez votre nom : ");
   scanf("%s", tcompte[CompteDispo].client_nom);
   printf("\nEntrez votre prenom : ");
   scanf("%s", tcompte[CompteDispo].client_prenom);
   printf("\nEntrez votre CIN : ");
   scanf("%s", tcompte[CompteDispo].client_cin);
   printf("\nDeposez un fond de base : ");
   scanf("%f", &tcompte[CompteDispo].fond_base);
   printf("\n*** Votre compte a ete creer avec succes ***\n");
   CompteDispo++;
}

void pcompte(){
   int nc;
   int i=1;
   printf("\nQuel est le nombre de comptes a creer : ");
   scanf("%d",&nc);
   while (i<=nc) {
      printf("\n*** Compte N%d ***\n",i);
      compte();
   i++;
   }
}

void mon_comptesolde(char cin[])
{
   int indice=chercherCompteParCin(cin);
   if(indice==-1){
      printf("le cin n'a a pas de compte");
      }
      else{
      printf("%s %s %s %f\n", tcompte[indice].client_cin, tcompte[indice].client_nom, tcompte[indice].client_prenom,tcompte[indice].fond_base);
      }
}

int chercherCompteParCin(char cin[]){
   for(int i=0; i<CompteDispo; i++){
      if(strcmp(tcompte[i].client_cin,cin)==0){
         return i;
      }
   }
   return -1;
}

int main()
{
   int option;
   while(1)
   {
      printf("\n******** La banque Youcode est a votre disposition ********\n");
      menu();
      printf("Entrez une option (1/2/3/4/5/6) pour continuer : "); 
      scanf("%d", &option);
      switch (option){
      case 1:
         compte();
         break;
      case 2:
         pcompte();
         break;
      case 3:
         char cin[20]; 
         printf("donner votre cin:");
         scanf("%s", cin);
         mon_comptesolde(cin);
         break;
      case 4:
         pcompte();
         break;
      case 5:
         pcompte();
         break;
      case 6:
         pcompte();
         break;
      default:
         printf("Please enter one of the options");
         printf("(1/2/3/4/5/6) to continue \n ");
         break;
      }
   }
   return 0;
}