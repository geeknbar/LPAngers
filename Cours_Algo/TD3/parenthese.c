#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Element
{
	char valeur;
	struct Element * suivant;
};
typedef struct Element * Pile;

void empiler(Pile *mapile, char val)
{
	Pile tmp;
	tmp = malloc(sizeof(struct Element));
	tmp->valeur = val;
	tmp->suivant = *mapile;
	*mapile=tmp;
}

Pile depiler(Pile *mapile)
{
	Pile tmp;
	if (*mapile == NULL)
		return NULL;
	else
		{
			tmp = *mapile;
			*mapile=(*mapile)->suivant;
			tmp->suivant = NULL;
			return tmp;
		}
}

void afficher(Pile p)
{
	while(p!=NULL)
		{
			printf("%c ",p->valeur);
			p=p->suivant;
		}
	printf("\n");
}


void detruire(Pile *p)
{
	while(*p != NULL)
		free(depiler(&(*p)));
}


int comparer(char * exp) 
{
  int i=0;
  int boolean=0;
  Pile p=NULL;
  
  while((&exp[i]!=NULL)&&(boolean!=0)){
       
    if ((exp[i]=='{')||(exp[i]=='(')||(exp[i]=='[')){
      empiler(&p,exp[i]);
      i++;    
    }else if ((exp[i]=='}')&&(p->valeur=='{')){
      depiler(&p);
      i++;
    }else if ((exp[i]==')')&&(p->valeur=='(')){
      depiler(&p);
      i++;
    }else if ((exp[i]==']')&&(p->valeur=='[')){
      depiler(&p);
      i++;
    }else{
      boolean = 1;
      return 1;
    }
    return 0;
}	


int main(int argc, char * argv[])
{ int r;

 printf("%s\n",argv[1]);
	r =comparer(argv[1]);
	printf("%d \n",r);
	return 0;
}
