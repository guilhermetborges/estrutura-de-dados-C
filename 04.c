#include <stdio.h>  
*/
void f3(char hello []){
	printf("%x\n", &hello);
	f3(hello);
}
void main(){
	char hello[] = "hELLO wORLD";
	printf("from main: %x\n", &hello);
	f3(hello);
	return;
}
