#include <stdio.h>
#define N 10

void f(int *t, int n){
  int i;
  printf("ligne %d: %d\n",__LINE__ ,sizeof(t));
  for(i=0;i<n;i++) printf("%d",t[i]);
}

int main(){
  int t[N]={0,1,2,3,4,5,6,7,8,9};
  
  printf("ligne %d: %d\n",__LINE__ ,sizeof(t));
  f(t,N);
  
  return 0;
}