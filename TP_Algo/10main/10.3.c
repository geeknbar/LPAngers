#include <stdio.h>
int main(int argc, char *argv[]){

  int res =0;
  int i;
  int num,num1;
  
  for(i=0;i < argc;i++)printf("argv[%d]=%s\n",i,argv[i]);
  if (argc > 4){
    printf("paramètre demandé 1 nombre 1 opérateur 1 nombre \n");

  }else{
  if (*argv[2]=='+'){

    sscanf (argv[1],"%d",&num);
    sscanf (argv[3],"%d",&num1);

    res = num + num1;
    printf("le résultat est de %d\n",res);
    
  }
  if (*argv[2]=='-'){
    
    sscanf (argv[1],"%d",&num);
    sscanf (argv[3],"%d",&num1);

    res = num - num1;
    printf("le résultat est de %d\n",res);
    
    
  }
  if (*argv[2]=='x'){
    
    sscanf (argv[1],"%d",&num);
    sscanf (argv[3],"%d",&num1);

    res = num * num1;
    printf("le résultat est de %d\n",res);
    
  }
  }
}