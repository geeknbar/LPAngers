#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 50

char buffer[N];


int main(){
  
  int n,i;
  char **tab;
  
  printf("Combien de chaine à trier?\n");
  scanf("%d",&n);//si fgets ecrire scanf("%d",&n);
  
  tab=malloc(n*sizeof(char*));
  if (tab==NULL){ perror("malloc");exit(1);}
  for (i=0;i<n;i++){
    printf("taper votre chaîne de caractères\n");
    scanf("%39s",buffer);//39 correspond a 40 -1 cf la taille de N;
    //fgets(buffer,N-1,stdin); //a verifier si cela fonctionne
    tab[i]=malloc(strlen(buffer+1)*sizeof(char));
      if (tab==NULL){ perror("malloc");exit(1);}
    strcpy(tab[i],buffer);
  }
  
  for(i=0;i<n;i++){
    printf("%s\n",tab[i]);
  }
  

  for(i=0;i<n;i++){
    free (tab[i]);
  }
  
  free(tab); 
  
  
  
  return 0;
}

