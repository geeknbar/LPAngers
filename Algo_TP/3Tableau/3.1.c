#include <stdio.h>

#define N 10
#define VRAI 1
#define FAUX 0

void tri(float t[]){
  int i, permut;
  
  do{
    permut=FAUX;
    for(i=0;i<N-1;i++)
      if (t[i]>t[i+1]){
	int temp = t[i];
	t[i]=t[i+1];
	t[i+1]=temp;
	permut=VRAI;
      }
    }while (permut);
  
}

int main(void){
  int i;
  float tab[N];
  
  printf ("saisez les nombres à trier \n");
  for (i=0;i<N-1;i++){
    scanf("%f\t",&tab[i]);
  }
  
  tri(tab);
  
  printf ("votre tableau trier");
  for (i=0;i<N;i++){
    printf("%f",tab[i]);
  }
  
  return 0;
}
