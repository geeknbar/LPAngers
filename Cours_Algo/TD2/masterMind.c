#include <stdio.h>
#include <math.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>


#define MAX 3

typedef int TAB[MAX];

TAB A={9,2,5},B={2,3,5},C;
int gagne;

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

int compare_tab (TAB A,TAB B){
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
  
  affiche_tab(C);
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
  compare_tab(A,B);
}  