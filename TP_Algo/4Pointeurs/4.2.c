#include <stdio.h>


int a=2, b=0;
int *ptr;



void f(int i, int *j){
 
  *j=2*i;
}


void main(){
  ptr=&b;
  f(a,ptr);
  printf("ptr=%p *ptr=%d i=%d\n",ptr,*ptr,a);
  printf("ptr=%p *ptr=%d i=%d\n",ptr,*ptr,b);
}
