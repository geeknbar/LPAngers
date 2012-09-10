/*ecrit un programme qui donne le nombre de jours dans un mois
Saisir le numero du mois
Si le numero est 1 3 5 7 8 10 12 afficher 31
Si le numero est 4 6 9 11 afficher 30
Si le numero est 2 afficher 28 ou 29
*/

#include <stdio.h>// Bibliothequa

//Variables
int mois;

/*¨Programme*/
void main(){
printf("Saisissez le numero du mois :\n");
scanf("%d",&mois);
switch(mois){
	case 1:case 3:case 5:case 7:case 8:case 10:case 12:
	printf("Le nombre de jours est de :31 \n");
	break;
	case 4:case 6:case 9:case 11:
	printf("Le nombre de jours est de :30 \n");
	break;
	case 2:
	printf("Le nombre de jours est de  28 ou 29 \n");
	break;
	default: printf("Mois inexistant \n");
	}

}