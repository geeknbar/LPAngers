#include <stdio.h>

#define N 10
#define VRAI 1
#define FAUX 0

void tri(float *t)
{
	int permut ;
	float x, *ptr ;

	do {
	  permut = FAUX ;
	  for (ptr=t ; ptr-t<N-1 ; ptr++)
	    if (*ptr>*(ptr+1))
	    {
	      x = *ptr ;
	      *ptr = *(ptr+1) ;
	      *(ptr+1) = x ;
	      permut = VRAI ;
	    }
	} while (permut) ;
}

int main()
{
	float tab[N], *p ;

	for (p=tab ; p-tab<N ; p++) scanf("%f",p) ;
	tri(tab) ;
	for (p=tab ; p-tab<N ; p++) printf("%f ",*p) ;
	printf("\n") ;

	return 0 ;
}
