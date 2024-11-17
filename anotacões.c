#include <stdio.h>   
/*

*/
void comparafloat(float b, float a);

main(){
	float a; 
	float b;
	printf("digite 2 numeros defcimais:\n");
	scanf("%f",&a);
	scanf("%f",&b);
	comparafloat(a , b);
	float res;
	res = a+b;
	printf("\n%.20f",res);

}

void comparafloat(float b, float a){
	float c;
	c = 0.3;
	if((a+b)==c ){
		printf("TRUE");
	}else{ 
		printf("FALSE");
	}
}

