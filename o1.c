#include <stdio.h>

int main (void){
	int a = 10;
	int *p;
	p = &a; // p recebe o endere�o de a
	*p = 2; // posi��o apontada por p (a) recebe o valor 2.
	
	int *c = &p;
	*c = 10;
	printf("%d\n , %d\n %d",a,p,c);
	return;
}

//imprime o valor 2
