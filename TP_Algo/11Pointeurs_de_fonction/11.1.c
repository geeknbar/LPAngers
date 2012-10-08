#include <stdio.h>
#include <math.h>

struct function {
  char *n;
  double (*f)(double);  
  
};

int main(int argc, char *argv[]){

  int res =0;
  double num =0;
  int i;
  
  struct function tab[]={{"cos",cos},{"sin",sin},{"tan",tan},{"e",exp},{"ln",log},{"v",sqrt}};
  if (argc > 3){
    printf("paramètre demandé 1 nombre 1 fonction (cos,sin,tan,e,ln,v) \n");

  }else{
    if (*argv[1]=='e'){
    sscanf (argv[2],"%f",&num);
    
    printf("le résultat est de %f\n",num);
    
  }
  }
 
}