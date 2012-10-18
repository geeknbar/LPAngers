#include <stdio.h>



//include de getgrgid
#include <sys/types.h>
#include <grp.h>



//faire une boucle pour savoir si il y a plus d'un utilisateur

int main(int nbarg, char *arg[])
{

struct group *g;

g=getgrent();

while ((g=getgrent())!=NULL) {

  
  if((g->gr_name)==arg[0]){
  printf("Groupe: %s Membres %s\n",g->gr_name, *g->gr_mem);
  }else{
    printf("rien \n");
  }

}

}

