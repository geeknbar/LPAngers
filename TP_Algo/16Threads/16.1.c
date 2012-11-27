#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

#define MAX 26

int globale = 0;

void *f1(void *arg){
  
  int i;
  int c=97;
  
  for(i=0;i<MAX;i++){
    printf("%c\n",c+i);
    printf("globale : %d\n",globale);
    fflush(stdout);
    sleep(1);
    
  }
  pthread_exit(0);
}

void *f2(void *arg){
  
  int i;
  int c=65;
  
  for(i=0;i<MAX;i++){
    printf("%c\n",c+i);
    fflush(stdout);
    sleep(2);
  }
  
  pthread_exit(0);
}

void *f3(void *arg){
  
  int i;
  
  for(i=1;i<9;i++){
    printf("%d\n",i);
    globale++;
    fflush(stdout);
    sleep(3);
  }
  
  pthread_exit(0);
}

int main(){
  
  pthread_t t1,t2,t3;
  
  if(pthread_create(&t1,NULL,f1,NULL)<0) perror("f1 fails\n");
  if(pthread_create(&t2,NULL,f2,NULL)<0) perror("f1 fails\n");
  if(pthread_create(&t3,NULL,f3,NULL)<0) perror("f1 fails\n");
  
  pthread_join(t1,NULL);
  pthread_join(t2,NULL);
  pthread_join(t3,NULL);
  
  return 0;
}