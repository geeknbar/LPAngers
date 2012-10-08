#include <stdio.h>
#include "8.3.h"

#define N 10

int main()
{
	FILE *out ;
	struct person ami[N] ;
	int i ;

	for (i=0 ; i<N ; i++) 
	{
		printf("nom, prenom et age: ") ;
		scanf("%19s %19s %d",ami[i].firstname,ami[i].lastname,&ami[i].age) ;
	}

	out = fopen("myfile","w") ;
	if (out==NULL) { perror("myfile") ; return 1 ; }
	fwrite(ami,sizeof(struct person),N,out) ;
	fclose(out) ;

	return 0 ;
}
