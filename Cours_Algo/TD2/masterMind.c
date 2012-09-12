#include <stdio.h>
#include <math.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>


#define MAX 3

typedef int TAB[MAX];

TAB A={9,2,5},B={2,3,5},C={0,0,0};
int gagne;

/*Protopyte
void saisie tab (TAB *x);
void affiche_tab(TAB x);
int appartient(int x,TAB b);
int compare_tab (TAB x,TAB y,TAB *z);
*/
void saisie_tab(TAB *x){
  int tmp,i=0;
  
  while(i!=MAX){
    printf("Donner le numero %d:",i+1);
    scanf("%d",&tmp);  //scanf("%d", &((*x)[i]));
    if((tmp>0)&&(tmp<10)){
      (*x)[i]=tmp;
      i++;
    }
  }
}

void affiche_tab(TAB x){
  int i;
  for (i=0;i<MAX;i++)
    printf("%d",x[i]);
  printf("\n");
  
  
}

int appartient(int x,TAB b){
  /*
  int i;
  
  for (i=0;i<MAX;i++){
    if (b[i]==x)
      return 0;
    else
      return 1;
  }
  */
  
  int i=0;
  while(i<MAX){
    if (b[i]==x)
      return 0;
    i++;
  }
  return 1;
}

int compare_tab (TAB x,TAB y,TAB *z){
  /*
  int a=0;
  int j=0;
  int i=0;
  
  while (i<MAX && a){
    if (!appartient(A[i],B)){
      a=1;
      C[j]= 0;
      j++;
    }else{ 
      C[j]=-A[i];
      j++;
	if (A[i]==B[i]){
	  C[j]=A[i];
	  j++;
	}
    }
  }
  */
  int i,j=0;
  
  for (i=0;i<MAX;i++){
    if (x[i]==y[i]){
      (*z)[i]=x[i];
      j++;
    }else 
      if(appartient(x[i],y)==0){
	(*z)[i]=-x[i];
      }else{
	(*z)[i]=0;
      }
  }
  
  if (j==MAX){
    gagne=0;
  }
}

/*
 * attention ne fonctionne plus avec un nombre >10
 * le temps d'eecution n'est ps garanti, le pc peut prendre 1 sans arret!!
 * 
*/
void aleatoire(TAB *x){
  int i,temp;
  srandom(getpid());
  for (i=0;i<MAX;i++){
    (*x)[i]=0;
  }
  for (i=0;i<MAX;i++){
    temp=random()%9+1;
    while(appartient(temp,*x)==0)
      temp = random()%9+1;
    (*x)[i]=temp;
  }
}
/*
int main(){
  gagne=1;
  
  
  do
    saisie_tab();
    compare_tab();
    affiche_tab();
  while(gagne==1);
  
  printf("Bravo, vous avez gané");
}
*/

void main(){
  //TAB T;
  //saisie_tab(&T);
  //affiche_tab(T);
  appartient(4,B);
  compare_tab(A,B,&C);
  affiche_tab(C);
}  