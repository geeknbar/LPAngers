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

int teteFile,nbElement;

//fonction qui permet d'ajouter un élément dans la file
void ajoutFile( tab file, int nombre){
  
  //adj est la variable qui permet de savoir où l'on doit ajouter la valeur dans la file
  int adj=0;
  if(nbElement<max){
    if((teteFile+nbElement)<max){
      adj=teteFile+nbElement;
    }else{
      adj=teteFile+nbElement-max;
    }
    file[adj]=nombre;
    nbElement=nbElement+1;
  }else{
    printf("erreur la File est pleine impossible de rajouter %d\n",nombre);
  }
}


//fonction qui permet de supprimer un élément dans la file
void supFile (tab file){
  if(teteFile==max){
    teteFile=1;
  }else{
    file[teteFile]=0;
    teteFile=teteFile+1;
    
  }
  nbElement=nbElement-1;
}

//fonction qui renvoie 1 lorsque la file est vide et 0 lorsqu'il y a un élément dans la file
int estVideFile(tab file){
  if(nbElement==0){
    return 1;
  }else{
    return 0;
  }
}

//fonction qui permet d'afficher la file
void afficheFile(tab file){
  int i;
  for (i=0;i<max;i++)
    printf("%d",file[i]);
  printf("\n");
}

//fonction qui initialise la pile avec 0 comme valeur par défaut + initialisation des variables nbElement et teteFile;
void InitFile(tab file){
  int i;
  for (i=0;i<max;i++){
    file[i]=0;
  }
  nbElement =0;
  teteFile =0;
}

void main(){

  int vide;
  //création de la file + initialisation de la pile avec 0 comme valeur par défaut
  tab file;
  InitFile(file);
  
  //ajout des valeurs dans la pile
  
  afficheFile(file);
  vide=estVideFile(file);
  printf("La file est vide : %d (1 pour oui 0 pour non)\n",vide);
  
  
  ajoutFile(file,1);
  ajoutFile(file,2);
  ajoutFile(file,3);
  ajoutFile(file,4);
  ajoutFile(file,5);
  
  afficheFile(file);
  vide =estVideFile(file);
  printf("La file est vide : %d (1 pour oui 0 pour non)\n",vide);
  
  
  supFile(file);
  supFile(file);
  supFile(file);
  afficheFile(file);
  ajoutFile(file,6);
  afficheFile(file);
  ajoutFile(file,7);
  ajoutFile(file,8);
  ajoutFile(file,9);
  afficheFile(file);
    /*
  supFile(file);
  supFile(file);
  supFile(file);
  afficheFile(file);


  supFile(file);
  afficheFile(file);
  
  
  afficheFile(file);
  ajoutFile(file,7);
  ajoutFile(file,8);
  ajoutFile(file,9);
  afficheFile(file);
  */
  
  
  
}
    


