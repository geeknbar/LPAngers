/* lire un fichier octet par octet et imprimer 
   les valeurs numériques des octets composant les codes utf-8 rencontrés
   à raison d'un code utf8 par ligne
   ---------------------------------------------------------------------------
   Sans prendre de précautions contre un fichier mal codé.
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	FILE *fp;
	int val, val1, val2, val3, val4;

	if (argc!=2) {
    	printf("Il me faut un nom de fichier");
    	exit(1);
	}

	if ((fp= fopen(argv[1], "r")) == NULL) {
     	printf("Je ne peux pas ouvrir %s", argv[1]);
     	exit(1);
	}

	while ((val=fgetc(fp)) !=EOF) {
    	if( val < 128 ){ /* ASCII */
    		printf("%d\n", val);
    	}else{
    		val1 = val;
    		if( val1 >= 240 ){ /* 4 octets : 240 = 128+64+32+16 */
    			val2 = fgetc(fp);
    			val3 = fgetc(fp);
    			val4 = fgetc(fp);
    			printf("%d %d %d %d\n", val1, val2, val3, val4);
    		}else{
    			if( val1 >= 224 ){ /* 3 octets : 224 = 128+64+32 */
    				val2 = fgetc(fp);
    				val3 = fgetc(fp);
     				printf("%d %d %d\n", val1, val2, val3);
     			}else{ /* 2 octets : >192 = 128+64 */
    				val2 = fgetc(fp);   			
   			   		printf("%d %d\n", val1, val2);
   				}
   			}
    	}
	} /* while */
	fclose(fp);
	return 0;
}/* main */

 
