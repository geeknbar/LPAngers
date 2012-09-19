#include <stdio.h>
#include <stdlib.h>

struct Element{

  int Numero;
  //int rang; //facultatif
  struct Element * Suivant;
};

typedef struct Element * Liste;


void afficheliste(Liste l){
  while (l!=NULL){
    printf("%d",l->Numero);
    l=l->Suivant;
    printf("\n");
  }
  
}

int rechercher(Liste l, int val){
  Liste tmp=NULL;
  while (l != NULL){
    if (l->Numero != val)
      tmp=l;
    l=l->Suivant;
  }
  printf("%p\n",tmp);
  return tmp;
}


void supprimer(Liste *l, int val){
  Liste sup;
  if (*l != NULL){
    if((*l)->Numero ==val){
      sup=*l;
      *l=(*l)->Suivant;
      free(sup);
      supprimer(&(*l),val);
    }else{
      supprimer(&((*l)->Suivant),val);
    }
  }
}


int main(){

  Liste l,l1,l2;
  l = malloc(sizeof(struct Element));
  l1 = malloc(sizeof(struct Element));
  l2 = malloc(sizeof(struct Element));
  
  l->Numero = 24100;
  l->Suivant = l1;
 
  l1->Numero = 5432;
  l1->Suivant = l2;
  
  l2->Numero = 0321;
  l2->Suivant = NULL;
  
  
  afficheliste(l);
  rechercher(l,0321);
  supprimer(&l,5432);
  afficheliste(l);
  
  return 0;
}