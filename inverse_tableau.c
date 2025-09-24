#include<stdio.h>
#include<stdlib.h>
int main(){

    int T[10000]; 
    int i,N;

    //Définition de la taille du tableau
    do{
        printf("Entrer la taille de votre tableau:");
        scanf("%d",&N);
    }
   while(N>10000);

   //Remplissage du tableau
   for(i=0; i<N; i++){
    printf("entrer la valeur n° %d du tableau:",i);
    scanf("%d",&T[i]);
   }
   printf("\n");

   //affichage du tableau
   for(i=0; i<N; i++){
    printf("%d",T[i]);
   }
   printf("\n");

   //Inversement et affichage du tableau
   printf("Affichage du nouveau tableau:\n");
   for(i=N-1; i>=0; i--){
    printf("%d",T[i]);
   }
   return 0;
}