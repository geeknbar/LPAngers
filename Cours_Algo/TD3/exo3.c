#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct liste {
  int val;
  struct liste *succ;
  struct liste *pred;
};


typedef struct liste *Listed;


/*
void afficheListe(ptr_liste_double L){
 while (L!=NULL){
   
   if(L->pred != NULL){
     if(L->succ != NULL)
       printf("%d (%d,%d)",L->val,L->pred->val,L->succ->val);
     else
       printf("%d (%d,NULL)",L->val,L->pred->val);
   }else{
     if(L->succ != NULL)
       printf("%d (NULL,%d)",L->val,L->succ->val);
     else
       printf("%d (NULL,NULL)",L->val);
   }
   L=L->succ;
 }
 printf("\n");
}
*/
/*
void inserer (Listed *maliste, int val){
  Listed tmp,l;
  tmp=malloc(sizeof(struct liste_double_chaine));
  tmp->val = val;
  l=*maliste;
  
  if((*maliste== NULL)||(val<=(*maliste)->val)){//NUll ou premier a inserer
    tmp->succ=(*maliste);
    tmp->pred=NULL;
    if(*maliste !=NULL)
	(*maliste)->pred=tmp;
    *maliste=tmp;
    */

void ajout (Listed *L, int val){
  Listed p;
  p= malloc(sizeof(struct liste));
  p->val = val;
  p->succ = *L;
  p->pred = NULL;
  *L=p;
}


void main(){
 
  Listed L;
  L=NULL;
  ajout(&L,3);
  ajout(&L,7);
  //afficheListe(L);
}
