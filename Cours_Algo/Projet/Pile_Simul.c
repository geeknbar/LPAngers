/*
 * 
 * COFFINET Dorian LicPro 2012/2013 Projet CM Algo
 * 
 * J'ai choisi ici de mettre les valeurs par défaut du tableau à 0
 * 
 */

#include <stdio.h>

#define max 5

typedef int tab[max];

int sommet;

//fonction qui permet d'ajouter un élément dans la pile
void empiler( tab pile, int nombre){

  
  if(sommet<max){
    pile[sommet]=nombre;
    sommet=sommet +1;
  }else{
    printf("erreur la pile est pleine impossible de rajouter %d\n",nombre);
  }
}

//fonction qui permet de supprimer un élément dans la file
void depiler (tab pile){
  pile[sommet-1]=0;
  sommet=sommet-1;
}

//fonction qui renvoie 1 lorsque la file est vide et 0 lorsqu'il y a un élément dans la file
int estVidePile(tab pile){
  if(sommet==0)
    return 1;
  else
    return 0;
}

//fonction qui permet d'afficher la file
void affichePile(tab pile){
  int i;
  for (i=0;i<max;i++)
    printf("%d",pile[i]);
  printf("\n");
}

//fonction qui initialise la pile avec 0 comme valeur par défaut + initialisation da la variable sommet
void InitPile(tab pile){
  int i;
  for (i=0;i<max;i++){
    pile[i]=0;
  }
  sommet = 0;
}

void main(){

  int vide;
  //création de la pile + initialisation de la pile
  tab pile;
  InitPile(pile);
  
  //ajout des valeurs dans la pile
  
  vide=estVidePile(pile);
  printf("La pile est vide : %d (1 pour oui 0 pour non)\n",vide);
  
  empiler(pile,4);
  affichePile(pile);
  vide=estVidePile(pile);
  printf("La pile est vide : %d (1 pour oui 0 pour non)\n",vide);
  
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
    


