#include <stdlib.h>
#include <stdio.h>

#define n 6



//liste d'adjacente
struct cellule
{
	 int noeud;
	 struct cellule * suivant;
};
typedef struct cellule * GRAPHEL[n];

//matrice d'adjacence
typedef int GRAPHEM[n][n];

void initM (GRAPHEM g){
  int i,j;
  for(i=0;i<n;i++)
    for(j=0;j<n;j++)
      g[i][j] = 0;
}

void initL(GRAPHEL g){
  int i;
  for(i=0;i<n;i++)
    g[i]=NULL;
}


void afficherM (GRAPHEM g){
  int i,j;
  for(i=0;i<n;i++){
    printf("\n"); 
    for(j=0;j<n;j++){
      printf("%d ",g[i][j]);
      
    }
  }
  printf("\n");
}

void afficherL(GRAPHEL g){
  int i;
  struct cellule *tmp;
  for(i=0;i<n;i++){
    tmp=g[i];
    while(tmp!=NULL){
      printf("%d->%d\n",i+1,tmp->noeud+1);
      tmp=tmp->suivant;
    } 
  }  
}


void ajoutM (GRAPHEM g, int a, int b){
  
  g[a-1][b-1]=1;
  
}

void ajoutL (GRAPHEL g, int i, int j){
  struct cellule *tmp;
  tmp= malloc(sizeof(struct cellule));
  tmp->noeud=j-1;
  tmp->suivant=g[i-1];
  g[i-1]=tmp; 
  
}

void supprimerM(GRAPHEM g, int a, int b){
  
    g[a-1][b-1]=0;
  
}

void supprimerL(GRAPHEL g, int i, int j)
{
	struct cellule * sup,* tmp = g[i-1];
	if (g[i-1] != NULL)
		{
		if ((g[i-1])->noeud == j-1)
			{
			sup = g[i-1];
			g[i-1] = g[i-1]->suivant;
			free(sup);
			}
		else
			{
			while ((tmp->suivant != NULL) && (tmp->suivant->noeud != j-1))
				tmp=tmp->suivant;
			if (tmp->suivant != NULL)
				{
				sup = tmp->suivant;
				tmp->suivant=tmp->suivant->suivant;
				free(sup);
				}
			}
		}
}

int existeM(GRAPHEM g, int i, int j){
  /*
  if(g[i-1][j-1]==1)
    return 1;
  else
    return 0;
  */
  return g[i-1][j-1];

}


int existeL(GRAPHEL g, int i, int j){
  
  struct cellule *tmp=g[i-1];
  while((tmp!=NULL)&&(tmp->noeud!=j-1))
    tmp=tmp->suivant;
  if(tmp==NULL)
    return 0;
  else
    return 1;
  
}

/* bon maisdonne qu'un successeurs
int successeursM(GRAPHEM g, int i){
  int j;
  int res=0;
  for(j=0;j<n;j++){
    if((g[i-1][j])==1){
      res=j+1;
    }
  }
  return res;
  
}
*/
int successeursM(GRAPHEM g, int i){
  int j;
  printf("%d -> ",i);
  for(j=0;j<n;j++){
    if(existeM(g,i,j)==1){
      printf("%d",j);
    }
  }
  printf("\n");
  
}

int successeursL(GRAPHEM g, int i){
  int j;
  printf("%d -> ",i);
  for(j=0;j<n;j++){
    if(existeL(g,i,j)==1){
      printf("%d",j);
    }
  }
  printf("\n");
  
}

int successeursL(GRAPHEL g, int i){
  struct cellule *tmp=g[i-1];
  printf("%d -> ",i);
  while(tmp!=NULL){
    printf("%d ",tmp->noeud+1);
    tmp=tmp->
  
  
}

int main()
{
  GRAPHEM gm;
  initM(gm);
  ajoutM(gm,2,3);
  ajoutM(gm,5,1);
  ajoutM(gm,6,4);
  afficherM(gm);
  supprimerM(gm,2,3);
  afficherM(gm);
  printf("existe %d \n",existeM(gm,2,3));
  printf("existe %d \n",existeM(gm,6,4));
  printf("successeurs %d \n",successeursM(gm,6));
  
  GRAPHEL gl;
  initL(gl);
  ajoutL(gl,2,3);
  ajoutL(gl,5,1);
  ajoutL(gl,6,4);
  afficherL(gl);
  supprimerL(gl,5,1);
  afficherL(gl);
  printf("existe %d \n",existeL(gl,5,1));
  printf("existe %d \n",existeL(gl,6,4));
  
  
  
  
}



