#include <stdlib.h>
#include <stdio.h>

#define max 5

typedef int tab[max];

int teteFile,nbElement;

void ajoutFile( tab file, int nombre){
  int adj=0;
  if(nbElement<max){
    if((teteFile+nbElement)<max){
      adj=teteFile+nbElement;
    }else{
      adj=teteFile+nbElement-max;
    }
    file[adj]=nombre;
    nbElement=nbElement+1;
  }else{
    printf("erreur la File est pleine impossible de rajouter %d\n",nombre);
  }
}



void supFile (tab file){
  if(teteFile==max){
    teteFile=1;
  }else{
    file[teteFile]=0;
    teteFile=teteFile+1;
    
  }
  nbElement=nbElement-1;
}

int estVideFile(tab file){
  if(nbElement==0){
    return 1;
  }else{
    return 0;
  }
}


void afficheFile(tab file){
  int i;
  for (i=0;i<max;i++)
    printf("%d",file[i]);
  printf("\n");
}

void main(){

  nbElement =0;
  teteFile =0;
  tab file= {0,0,0,0,0};
  afficheFile(file);
  ajoutFile(file,1);
  ajoutFile(file,2);
  ajoutFile(file,3);
  ajoutFile(file,4);
  ajoutFile(file,5);
  
  afficheFile(file);
  supFile(file);
  supFile(file);
  supFile(file);
  afficheFile(file);
  ajoutFile(file,6);
  afficheFile(file);
  ajoutFile(file,7);
  ajoutFile(file,8);
  ajoutFile(file,9);
  afficheFile(file);
    /*
  supFile(file);
  supFile(file);
  supFile(file);
  afficheFile(file);


  supFile(file);
  afficheFile(file);
  
  
  afficheFile(file);
  ajoutFile(file,7);
  ajoutFile(file,8);
  ajoutFile(file,9);
  afficheFile(file);
  */
  
  
  
}
    


