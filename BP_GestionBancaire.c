#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct info_compte{
   char client_nom[30];
   char client_prenom[30];
   char client_cin[10];
   float montant;
}info_compte;

int menu()
{
   int option;
   printf("\n1. Creer un nouveau compte \n");
   printf("2. Creer plusieurs comptes \n");
   printf("3. Afficher mon compte/solde \n");
   printf("4. Depot argent \n");
   printf("5. Retrait argent \n");
   printf("6. Afficher les comptes \n");
   printf("7. Quitter application \n\n");
   printf("Entrez une option (1/2/3/4/5/6/7) pour continuer : "); 
   scanf("%d", &option);
   printf("\n");
   return option;
}

info_compte creer_compte(){
    info_compte client;
    printf("Entrez votre Nom : ");
    scanf("%s", client.client_nom);
    printf("Entrez votre Prenom : ");
    scanf("%s", client.client_prenom);
    printf("Entrez votre CIN : ");
    scanf("%s", client.client_cin);
    printf("Deposez un fond de base : ");
    scanf("%f", &client.montant);
    return client;
}

void affcompte(info_compte client)
{
    printf("-----------------------------\n");
    printf("CIN : %s\n", client.client_cin);
    printf("nomCLient : %s\n", client.client_nom);
    printf("prenomClient : %s\n", client.client_prenom);
    printf("montant : %.2f\n", client.montant);
    printf("-----------------------------\n");
}

typedef struct classeur
{
    info_compte comptes[10];
    int size;
}classeur;

classeur creer_position_client()
{
    classeur pos_client;
    pos_client.size = 0;
    return pos_client;
}

int aff_par_cin(classeur test, char* cin)
{
    int i = 0;
    for(i = 0; i < test.size; i++)
    {
        if(strcmp(test.comptes[i].client_cin, cin) == 0)
        {
            return i;
        }
    }
    return -1;
}

void ajouter_compte(classeur* pos_client, info_compte client)
{
    pos_client->comptes[pos_client->size] = client;
    pos_client->size++;
}


int main(){
   info_compte client;
   int fin = 0;

   while(!fin){
      system("CLS");
      printf("\n******** La banque Youcode est a votre disposition ********\n");

      switch(menu()){
         case 1:
               client = creer_compte();
               ajouter_compte(&client, client);
               break;
         case 2:
               system("CLS");
               int nc;
               int i=1;
               printf("\nQuel est le nombre de comptes a creer : ");
               scanf("%d",&nc);
                  while (i<=nc) {
                     printf("\n*** Compte N%d ***\n",i);
                     client = creer_compte();
                     ajouter_compte(&client, client);
                     i++;
                  }
               break;
         case 3:
               system("CLS");
               break;
         case 4:
               system("CLS");
               break;
         case 5:
               system("CLS");
               break;
         case 6:
               fin = 1;
               break;
         default:
               printf("\nerreur de saisie essayer a nouveau\n");
               break;
      }
      
   }
   
   printf("\napplication fermer !!\n");
}
   
   
   /*while(1)
   {
      printf("\n******** La banque Youcode est a votre disposition ********\n");
      menu();
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
}*/