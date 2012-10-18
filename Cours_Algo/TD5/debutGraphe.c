#include <stdlib.h>
#include <stdio.h>

#define N 6
// liste d'adjacence
struct cellule
{
 	int noeud;
 	struct cellule * suivant;
};

typedef struct cellule * GRAPHEL[N];

// matrice d'adjacence
typedef int GRAPHEM[N][N];


void creerGrapheL(GRAPHEL g)
{
int i;
for(i=0;i<N;i++)
	g[i] = NULL;
}

void creerGrapheM(GRAPHEM g)
{
int i,j;
for(i=0;i<N;i++)
	for(j=0;j<N;j++)
		g[i][j] = 0;
}


void afficheGrapheM(GRAPHEM g){
int i,j;
for(i=0;i<N;i++){
	for(j=0;j<N;j++)
		printf("%d ",g[i][j]);
	printf("\n");
	}
printf("\n");
}

void afficheGrapheL(GRAPHEL g){
int i;
struct cellule * tmp;
for(i=0;i<N;i++){
	tmp = g[i];
	while (tmp != NULL){
			printf("%d->%d\n",i+1,tmp->noeud+1);
			tmp = tmp->suivant;
		}
	}
}

// Programme Principal
int main()
{
GRAPHEL gl;
GRAPHEM gm;

printf("CREATION\n");
creerGrapheM(gm);
creerGrapheL(gl);

printf("GM\n");
afficheGrapheM(gm);
printf("GL\n");
afficheGrapheL(gl);

printf("AJOUT\n");
ajoutArcL(gl,1,2);
ajoutArcM(gm,1,2);

printf("GM\n");
afficheGrapheM(gm);
printf("GL\n");
afficheGrapheL(gl);

printf("TESTS\n");
printf("M arc entre 1 et 2 : %d \n",testarcM(gm,1,2));
printf("L arc entre 1 et 2 : %d \n",testarcL(gl,1,2));

printf("SUCCESSEURS\n");
succM(gm,1);
succL(gl,1);
succL2(gl,1);
printf("PREDECESSEURS\n");
predM(gm,2);
predL(gl,2);

printf("SUPPRESSION\n");
supprimeArcL(gl,1,2);
supprimeArcM(gm,1,2);

printf("GM\n");
afficheGrapheM(gm);
printf("GL\n");
afficheGrapheL(gl);

printf("TESTS\n");
printf("M arc entre 1 et 2 : %d \n",testarcM(gm,1,2));
printf("L arc entre 1 et 2 : %d \n",testarcL(gl,1,2));

return 0;
}
