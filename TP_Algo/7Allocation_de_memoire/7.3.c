#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define FICHIER "/usr/share/dict/words"
#define L 40


int ana(char *s1,char *s2)
{
	int i=0, j ;
	
	
	if (strlen(s1)!=strlen(s2)) return 0 ;

	for (i=0 ; s1[i] ; i++) // tant que s1[i] != '/0'
	{
		for (j=0 ; s2[j] ; j++)
			if (s1[i]==s2[j])
			{
				s2[j]=' ' ; // on barre
				break ;     // au suivant
			}	
		if (s2[j]=='\0') return 0 ; // on n'a pas trouvé
	}
	return 1 ;		
}



int main()
{
  FILE *in ;
  char s[L],s2[L] ;

  in = fopen(FICHIER,"r") ;
  if (in==NULL) { perror(FICHIER) ; return 1 ; }

  char buffer[L];

  int i,nombre_mot;
  char **tab;
  nombre_mot=99171;
  
  tab=malloc(nombre_mot*sizeof(char*));
  if (tab==NULL){ perror("malloc");exit(1);}
  for (i=0;i<nombre_mot;i++){
    while(fscanf(in,"%39s",buffer){
    tab[i]=malloc(strlen(buffer+1)*sizeof(char));
    }
      if (tab==NULL){ perror("malloc");exit(1);}
    strcpy(tab[i],buffer);
  }
  
  for(i=0;i<nombre_mot;i++){
    printf("%s\n",tab[i]);
  }
  
  /*
  while(fscanf(in,"%39s",s)==1){
 
    if (ana(s2,s)) printf("%s\n",s) ;
  }
  */
  fclose(in) ; 
  /*
  for(i=0;i<nombre_mot;i++){
    free (tab[i]);
  }
  
  free(tab); 
  */
	return 0 ;
}
