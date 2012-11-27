#include <signal.h>
#include <unistd.h>
#include <stdio.h>

int main(void){
void Traite_Sig(int Numero);
int Nb_Sig ;

for(Nb_Sig = 1; Nb_Sig < NSIG ; Nb_Sig ++){

    }
    while(1){
    sleep(5);  /* Attendre des signaux   */
    }
}

/************* Fonction de traitement **************/
void Traite_Sig (int Numero){
    printf("Coucou, recu signal %d !\n", Numero);

}