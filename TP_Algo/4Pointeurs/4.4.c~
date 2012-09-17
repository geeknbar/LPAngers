#include <stdio.h>
#include <math.h>

int a,b,s,p;
int *i;
int *j;



int f(int s,int p,int *i, int*j){
  
  int res = 0;
  int d = s*s-4*p;
  if (d<0)
    res =1;
  else {
    *i=(s+sqrt(d))/2;
    *j=(s-sqrt(d))/2;
  }  
  return res;
}



void main(){
  printf("Entrer 2 nombres somme +produit\n");
  scanf("%d %d",&s,&p);
  i=&a;
  j=&b;
  int res;
  res=f(s,p,i,j);
  printf("res=%d a=%d b=%d\n",res,a,b);
}