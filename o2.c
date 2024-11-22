#include <stdio.h>  

/*main(){
	char palavra[100];
	printf("%x\n", &palavra[0]);
	printf("%x\n", &palavra[100]);
	printf("%d\n", &palavra[100] - & palavra[0]);
}   */

void f2(char hello[]){
	printf("from f2: %d\n", &hello);
	printf("%s\n", hello);
}

void f1(char hello[]){
	printf("from f1: %d\n", &hello);
	f2(hello);
}

void main() {
	char hello[] = "Hello World";
	printf("from main: %d\n", &hello);
	f1(hello);
	
	return;
}
