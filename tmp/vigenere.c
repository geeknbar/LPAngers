#include <stdio.h>
#include <stdlib.h>

void chiffrement(char *, char *, unsigned int *, unsigned int) ;
double coincidence(char *, unsigned int) ;

void chiffrement(char *entree, char *sortie, unsigned int *clef, unsigned int n)
{
  FILE *f_in, *f_out ;
  int c, chiffre ;
  unsigned int i = 0 ;
  if ((f_in = fopen(entree, "r")) == NULL)
    {
      fprintf(stderr,"Erreur ds l’ouverture du fichier %s\n", entree) ;
      return ;
    }
  if ((f_out = fopen(sortie, "w")) == NULL)
    {
      fprintf(stderr,"Erreur ds l’ouverture du fichier %s\n", sortie) ;
      return ;
    }
  while ((c = fgetc(f_in)) != EOF)
    {
      chiffre = (((c-97) + clef[i%n]) % 26) + 97 ;
      fprintf(f_out,"%c",chiffre) ;
      i++ ;
    }
  fclose(f_in) ;
  fclose(f_out) ;
  return ;
}

double coincidence(char *entree, unsigned int longueur)
{
  FILE *f_in ;
  unsigned int **tab_frequence ;
  double res, total=0 ;
  int i, j, c ;
  unsigned int *nb_lettres ;

  if ((f_in = fopen(entree, "r")) == NULL)
    {
      fprintf(stderr,"Erreur ds l’ouverture du fichier %s\n", entree) ;
      return(0) ;
    }

  nb_lettres = (unsigned int*)calloc(longueur, sizeof(unsigned int)) ;
  tab_frequence = (unsigned int**)malloc(longueur * sizeof(unsigned int*)) ;
  for (i=0 ; i< longueur ; i++)
    tab_frequence[i] = (unsigned int*)calloc(26, sizeof(unsigned int)) ;
  i = 0 ;
  while ((c = fgetc(f_in)) != EOF)
    {
      tab_frequence[i%longueur][c-97]++ ;
      nb_lettres[i%longueur]++ ;
      i++ ;
    }

 for (i=0 ; i<longueur ; i++)
    {
      res = 0 ;
      for (j=0 ; j<26 ; j++)
	res += tab_frequence[i%longueur][j] * (tab_frequence[i%longueur][j]-1) ;
      res = res / (nb_lettres[i] * (nb_lettres[i]-1)) ;
      total += res ;
    }

  for (i=0 ; i<longueur ; i++)
    free(tab_frequence[i]) ;
  free(tab_frequence) ;
  fclose(f_in) ;
  return(total/longueur) ;
}

int main(int argc, char *argv[0])
{
  unsigned int n ;
  unsigned int *clef ;
  int i, c ;
  if (argc != 3)
    {
      fprintf(stderr, "\nErreur : nombre d’arguments invalide\n") ;
      fprintf(stderr, "Syntaxe : %s fichier_entree fichier_sortie\n", argv[0]) ;
      return(EXIT_FAILURE) ;
    }
  printf("\n Entrez la longueur de la clef entre 1 et 10 :\t") ;
  scanf("%u", &n) ;
  c = getchar() ;
  clef = (unsigned int*)malloc(n * sizeof(unsigned int)) ;
  printf("Entrez la clef sous forme d’un mot de %u lettres minuscules : ",n) ;
  for (i=0 ; i<n ; i++)
    {
      c = getchar() ;

     clef[i] = c - 97 ;
    }
  printf("\n clef ;\n") ;
  for(i=0 ;i<n ;i++)
    printf("%d (%c)", clef[i], clef[i]+97) ;
  chiffrement(argv[1], argv[2], clef, n) ;
  for (i=1 ; i<= 10 ; i++)
    {
      printf("\n longueur testee = %d\n", i) ;
      printf("\n indice de coincidence moyen = %f\n", coincidence(argv[2], i)) ;
    }
  return(EXIT_SUCCESS) ;
}