#include <stdio.h>
#include <stdlib.h>

struct info_compte
{
   char client_nom[30];
   char client_prenom[30];
   char client_cin[10];
   float fond_base;     
};
struct info_compte account[100];

FILE *fptr;
// fptr = fopen("C:\\Users\\Youcode\\CL_BriefSAS\\BP_GB.txt","w");
/*if(fptr == NULL){
      printf("Error!");   
      exit(1);             
   }
   
   printf("Enter num: ");
   scanf("%d",&num);
   fprintf(fptr,"%d",num);
   fclose(fptr);
   
   */


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
      default:
         printf("Please enter one of the options");
         printf("(1/2/3/4/5/6) to continue \n ");
         break;
      }
   }
   return 0;
}

void menu()
{
    printf("\n1. Creer un nouveau compte \n");
    printf("2. Creer plusieurs comptes \n");
    printf("3. Retrait argent \n");
    printf("4. Depot argent \n");
    printf("5. Afficher mon solde \n");
    printf("6. Rechercher les comptes par CIN \n");
    printf("7. Quitter application \n\n");
}

void compte(){
   char client_nom[30];
   char client_prenom[30];
   char client_cin[10];
   float fond_base;  
   int choix;
   printf("\nEntrez votre nom : ");
   scanf("%s", &client_nom);
   printf("\nEntrez votre prenom : ");
   scanf("%s", &client_prenom);
   printf("\nEntrez votre CIN : ");
   scanf("%s", &client_cin);
   printf("\nDeposez un fond de base : ");
   scanf("%f", &fond_base);
   printf("\n*** Votre compte a ete creer avec succes ***\n");
   printf("\n1. Voir le compte");
   printf("\n2. Continuer\n");
   scanf("%d", &choix);
   switch (choix)
   {
   case 1:
      printf("\n*** Information du compte ***\n");
      printf("\nNom et Prenom : %s %s", client_nom, client_prenom);
      printf("\nCIN : %s", client_cin);
      printf("\nMontant : %f\n", fond_base);
      break;
   default:
      break;
   }
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