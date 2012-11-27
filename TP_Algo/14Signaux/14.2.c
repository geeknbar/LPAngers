#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void handler(int sig)
{
     char  c;

     signal(sig, SIG_IGN);
     printf("Etes vous sur [o/n]");
     c = getchar();
     if (c == 'o' || c == 'O')
          exit(0);
     else
          signal(SIGINT, handler);
     getchar();
}


int  main(void)
{
     signal(SIGINT, handler);
     while (1)
          pause();
     return 0;
}