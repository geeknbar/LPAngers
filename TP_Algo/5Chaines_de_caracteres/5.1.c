#include <stdio.h>
#include <string.h>
char s1[10],s2[10],x[10];

void main(){
 
  printf("Saisir 2 chaines de caracteres\n");
  scanf("%s",s1);
  scanf("%s",s2);
  
  if (strcmp(s1,s2)>0){
    strcpy(x,s1);
    strcpy(s1,s2);
    strcpy(s2,x);
  }
  
  printf("Chaine s1 %s\n",s1);
  printf("Chaine s2 %s\n",s2);
}


// permet de ranger dans l'odre alphabetique les chaines rentrées en parametre.