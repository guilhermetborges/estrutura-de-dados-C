#include <stdio.h>  
#include <stdlib.h>
#include <string.h>  

void main() {
	char hello[] = "Hello World";
	printf("from main: %d\n", &hello);
	char *hello2 = malloc(sizeof(hello));
	strcpy(hello2, hello);
	printf("hello2: %x\n", hello2);
	
	char *hello3 = hello2 +6;
	printf("from hello2: %s\n", hello2);
	printf("from hello3: %x\n %s\n", hello3,hello3);
	
	return;
	}
