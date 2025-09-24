#include<stdio.h>
#include<stdlib.h>
int main(){

    int T[10000];
    float median; 
    int i,j,N;

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

   //Tri du tableau
   for(i=0; i<N-1; i++){
     for(j=N-1; j<N-i-1; j++){
        if(T[j]>T[j+1]){
            int temp=T[j];
            T[j]=T[j+1];
            T[j+1]=temp;
        }
    }

   }
   
   

   //affichage du tableau une nouvelle fois
   for(i=0; i<N; i++){
    printf("%d",T[i]);
    }
    printf("\n");

   //median du tableau
   if(N%2!=0){
    median=T[N/2];
    printf("la médiane est:%2.f",median);
    }

    else{
        median=(T[N/2] + T[N/2 +1])/2;
        printf("la médiane est:%2.f",median);
    }
    return 0;

}