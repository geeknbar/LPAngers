#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NMAX 10

struct maillon_ligne {
  int pix;
  struct maillon_ligne * suiv;
};

typedef struct maillon_ligne *ptr_ligne;

typedef ptr_ligne T_image[NMAX];


struct couple{
  int val,nb;
};

struct maillon_ligne_compressee{
  struct couple pix;
  struct maillon_ligne_compressee *suiv;
};

typedef struct maillon_ligne_compressee *ptr_ligne_compressee;

typedef ptr_ligne_compressee T_image_compressee[NMAX];

T_image im;
T_image_compressee imC;

/* Peut aussi s'écrire plus facilement mais les appels seront différents.
struct compresse {
  int pix;
  int nb;
  struct compresse * suiv;
};

typedef struct compresse *ptr_comp
*/


//inserer dans une ligne (faire un malloc etc pour une insertion en tete 
void ajout (ptr_ligne *L, int val){
  ptr_ligne p;
  p= malloc(sizeof(struct maillon_ligne));
  p->pix = val;
  p->suiv = *L;
  *L=p;
}

/*
 * inserer dans une ligne compresse une insertion en tete
 * on peu aussi void ajoutC (ptr_ligne_compressee *L,int val, int nb) il faut créer la sructure dans la fonction.
 * ptr_ligne_compressee p;
 * p= malloc(sizeof(struct maillon_ligne_compressee));
 * (p->pix).val = val;
 * (p->pix).nb = nb;
 * p->suiv = *L;
 * *L=p;
 * 
 */
void ajoutC (ptr_ligne_compressee *L,struct couple c){
  ptr_ligne_compressee p;
  p= malloc(sizeof(struct maillon_ligne_compressee));
  p->pix= c;
  p->suiv = *L;
  *L=p;
  
}

void afficheLigne(ptr_ligne L){
 while (L!=NULL){
   printf("%d",L->pix);
   L=L->suiv;
 }
 printf("\n");
}
  
void afficheLigneC(ptr_ligne_compressee L){
 while (L!=NULL){
   printf("(%d,%d) ",(L->pix).val,(L->pix).nb);
   L=L->suiv;
 }
 printf("\n");
}  


void compresse_ligne (ptr_ligne p,ptr_ligne_compressee *ligne){
  
  int val,nb;
  struct couple c;
  
  *ligne=NULL; //le dernier maillon est toujours égale a null faire attention!!
  
  while (p!=NULL){
    
    val=p->pix;
    nb=0;
    while ((p!=NULL) && (p->pix == val)){//on fait qu moins un tour dans la boucle
      nb=nb+1;
      p=p->suiv;
    }
    c.val=val;
    c.nb=nb;
    ajoutC(&(*ligne),c); 
  }
  
}

void compress_image (T_image im, int nbligne, T_image_compressee *imc){
  int i;
  for(i=0;i<nbligne;i++){
    compresse_ligne(im[i],&(*imc)[i]);
  }
}

void main(){
  //ATTENTION ne pasmettre 'ptr_ligne T = malloc(sizeof(struct maillon_ligne));' car on alloue un espace mémoire sans valeur!!!!
  ptr_ligne T = NULL;
  ajout(&T,3);
  ajout(&T,2);
  ajout(&T,2);
  ajout(&T,1);
  im[0]=T;
  ptr_ligne T2 = NULL;
  ajout(&T2,4);
  ajout(&T2,4);
  ajout(&T2,4);
  ajout(&T2,6);
  ajout(&T2,6);
  im[1]=T2;
  
  afficheLigne(im[0]);
  afficheLigne(im[1]);
  
  compresse_ligne(im[0],&imC[0]);
  compresse_ligne(im[1],&imC[1]);
  
  
  afficheLigneC(imC[0]);
  afficheLigneC(imC[1]);
  
}

