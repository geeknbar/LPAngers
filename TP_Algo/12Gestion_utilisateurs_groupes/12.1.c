#include <stdio.h>

//includede getpwent
#include <sys/types.h>
#include <pwd.h>

//include de getgrgid
//#include <sys/types.h>
#include <grp.h>



int main()
{

struct passwd *p;
struct group *g;

p=getpwent();
g=getgrgid(p->pw_gid);

while ((p=getpwent())!=NULL) {

  printf("Utilisateur: %s Groupe: %s \n",p->pw_name, g->gr_name);

}

endpwent();
  
}
