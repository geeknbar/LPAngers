#include <stdio.h>// Bibliothequa

//Variables
int annee,annee_courante,age;
/*�Programme*/
void main(){
printf("Ann�e courante :\n");
scanf("%d",&annee_courante);
printf("votre ann�e de naissance :\n");
scanf("%d",&annee);
age=annee_courante-annee;
printf("votre age est de %d \n", age);
}
