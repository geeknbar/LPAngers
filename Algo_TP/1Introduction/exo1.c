#include <stdio.h>

int i, j;
float x, y;
char c;


int main (){
printf("entrer un entier, un réel et un caractère:");
scanf ("%d,%f %c",&i,&x,&c);
printf ("%d %f %c\n",i,x,c);
printf ("%d %c %c\n",c,c+1,c-1);

i++; c--; printf("%d %d\n", i ,c);

x = i/11; y=i/11.;
printf("%f %f %.2f \n", x , y,y);
printf("%f %f\n", j/i, j/(float)i);

printf("%d %d %d \n", sizeof(int),sizeof(x), sizeof(c));

j*=2; printf("%d\n",j);
j-=10; printf("%d\n",j);

}


