#include <stdlib.h>
#include <stdio.h>

#define max 5

typedef int tab[max];

int sommet;

void empiler( tab pile, int nombre){

  
  if(sommet<max){
    pile[sommet]=nombre;
    sommet=sommet +1;
  }else{
    printf("erreur la pile est pleine impossible de rajouter %d\n",nombre);
  }
}

void depiler (tab pile){
  pile[sommet-1]=-1;
  sommet=sommet-1;
}

int estVidePile(tab pile){
  if(pile[sommet]==0)
    return 1;
  else
    return 0;
}


void affichePile(tab pile){
  int i;
  for (i=0;i<max;i++)
    printf("%d",pile[i]);
  printf("\n");
}

void main(){

  sommet = 0;
  tab pile= {-1,-1,-1,-1,-1};
  empiler(pile,4);
  affichePile(pile);
  empiler(pile,3);
  empiler(pile,5);
  affichePile(pile);
  depiler(pile);
  affichePile(pile);
  empiler(pile,9);
  empiler(pile,7);
  empiler(pile,2);
  empiler(pile,5);
  affichePile(pile);
  depiler(pile);
  depiler(pile);
  empiler(pile,2);
  affichePile(pile);
}
    


