/*Erire l'algorithme qui de,qnde a l'etudiant la note obtenue dans chacune des matières suivantes : informatique
,mathematique,chi,ie.Affihez la moyenne de cet etudiant sachant que les matieres ont respectivement
des coefficients de 3,3,2 */

#include <stdio.h>// Bibliothequa

//Variables
int cchimie,cinfo,cmaths;
float ninfo,nmaths,nchimie,moy;

/*¨Programme*/
void main(){
cinfo=3;
cmaths=3;
cchimie=2;
printf("Note d'info :\n");
scanf("%f",&ninfo);
printf("Note de maths :\n");
scanf("%f",&nmaths);
printf("Note de chimie :\n");
scanf("%f",&nchimie);
/*
printf("Note d'info,de maths,de chimie :\n");
scanf("%f,%f,%f",&ninfo,&nmaths,&nchimie);
*/

printf("Votre moyenne est de %f \n",(ninfo*cinfo+nmaths*cmaths+nchimie*cchimie)/(cinfo+cmaths+cchimie) );
}