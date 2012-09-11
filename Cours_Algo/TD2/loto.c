#include <stdio.h>

typedef int GRILLE[49];
typedef int TIRAGE[7];

GRILLE G={0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,1,0,0,0,0,0,0};
TIRAGE T = {2,4,6,48,8,15,16};

int present (GRILLE g,int val){
  return g[val-1];
}

int numeros  (GRILLE g,TIRAGE t){
  int i,count;
  
  for(i=0;i<6;i++){
    count = count+present(g,t[i]);
  }
  return count;
}

void resultat (GRILLE g,TIRAGE t){
  int res = numeros(g,t);
  
  switch(res){
    case 3:
      if (present(g,t[6])==1)
	printf("3 num + comp\n");
      else
	printf("3 num\n");
      break;
    case 4:
      if (present(g,t[6])==1)
	printf("4 num + comp\n");
      else
	printf("4 num\n");
      break;
    case 5:
      if (present(g,t[6])==1)
	printf("5 num + comp\n");
      else
	printf("5 num\n");
      break;
    case 6:
      if (present(g,t[6])==1)
	printf("6 num + comp\n");
      else
	printf("6 num\n");
      break;  
    default :printf("perdu");
  }
  
  /*
   * int n=numero(g,t)
   * 
   * if (n>2){
   * 	printf("Vous avez %d numero",n);
   *	if(present(g,t[6]==1)
   * 		printf(" et le numero complementaire.");
   * 	prinft("\n")
   * else
   * 	printf("Perdu\n");
   * 
   * Le switch fait moins d'appel au systeme !
   * 
   * 
   */
}
void main(){
  printf("%d\n",present(G,4));
  printf("%d\n",present(G,3));
  printf("nb de numero : %d\n",numeros(G,T));
  resultat(G,T);
}
    