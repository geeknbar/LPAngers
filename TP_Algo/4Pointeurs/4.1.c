#include <stdio.h>

int i=12;
int *ptr;

void main(){
ptr = &i;
*ptr=21;

printf("ptr=%p *ptr=%d i=%d\n",ptr,*ptr,i);
scanf("%d",ptr);
printf("ptr=%p *ptr=%d i=%d\n",ptr,*ptr,i);
}
