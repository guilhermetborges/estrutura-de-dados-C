#include <stdio.h>
int lermat(int x, int y);
int escrevamat(int x, int y);


main(){
	int linhas,colunas;
	printf("numero de linhas: ");
	scanf("%d",&linhas);
	
	printf("numero de colunas: ");
	scanf("%d",&colunas);
	
	lermat(linhas, colunas);
	escrevamat(linhas,colunas);
}



int lermat(x,y){
	int i,k,mat[x][y];
	for(i=0;i<x;i++){
		for(k=0;k<y;k++){
			scanf("%d",&mat[i][k]);
		}
	}
}
int escrevamat(int x, int y){
	
	int i,k,mat[x][y];
	for(i=0;i<x;i++){
		for(k=0;k<y;k++){
			printf(" %d |",mat[i][k]);
		}
		printf("\n");
	}
}

