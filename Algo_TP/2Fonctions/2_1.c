#include <stdio.h>

float F(int);
double rec(int);
int k;
float res=0;
double res_rec=0;


float F(int k){
  float f;
  
  for (f=1;k>0;k--)
    f*=k;
  
  return f;
  
}




double rec (int n){

  return n>0 ? n*rec(n-1) : 1;
  
}

int main(){
  
  k=10;
  res=F(k);
  printf("factoriel %d = %f\n",k,res);  
  res_rec=rec(k);
  printf("%f\n",res_rec);
}