#include <stdio.h>

int main(){

int S=0, i=1, n=20;

/*for (i=1; i<=n;i++){
	S+=i;
	printf("i=%d S=%d\n", i,S);
}
*/

while (i<=n){
	S+=i;
	printf("i=%d S=%d\n", i,S);
	i++;
}

return 0;

}
