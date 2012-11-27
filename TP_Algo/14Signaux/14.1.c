#include <stdio.h>
#include <signal.h>

void handler(int s){
  printf("signal %d bien reçu \n",s);
}

int main(){
  int c = 0;
  c=(int)signal(SIGINT,handler);
  printf("est %d",c);
  for(;;);
  return 0;
}