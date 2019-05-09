#include <stdio.h>
#define SATIR 3
#define SUTUN 3

void matris_gir(int mat[][SUTUN]);
void matris_yazdir(int mat[][SUTUN]);
void matris_toplama(int mat1[][SUTUN],int mat2[][SUTUN],int top[][SUTUN]);
void matris_carpma(int mat1[][SUTUN],int mat2[][SUTUN],int carp[][SUTUN]);
void matris_transpoz(int mat[][SUTUN],int trans[][SUTUN]);

int main(void){
	int mat1[SATIR][SUTUN],mat2[SATIR][SUTUN],top[SATIR][SUTUN],carp[SATIR][SUTUN],trans[SATIR][SUTUN];
	
	printf("%dx%d birinci matrisin elemanlarini gir:\n",SATIR,SUTUN);
	matris_gir(mat1);
	
	printf("%dx%d ikinci matrisin elemanlarini gir:\n",SATIR,SUTUN);
	matris_gir(mat2);
	
	printf("\nMatrislerin toplami:\n");
	matris_toplama(mat1,mat2,top);
	matris_yazdir(top);
	
	printf("\nMatrislerin carpimi:\n");
	matris_carpma(mat1,mat2,carp);
	matris_yazdir(carp);
	
	printf("\n1.Matrisin transpozu:\n");
	matris_transpoz(mat1,trans);
	matris_yazdir(trans);
	
	printf("\n2.Matrisin transpozu:\n");
	matris_transpoz(mat2,trans);
	matris_yazdir(trans);
	
	return 0;
}

void matris_gir(int mat[][SUTUN]){
	int i,j;
	for(i=0; i<SATIR; i++){
		
		for(j=0; j<SUTUN; j++){
			printf("[%d][%d]=",i,j);
			scanf("%d",(*(mat+i)+j)); 
		}
	}
}

void matris_yazdir(int mat[][SUTUN]){
	int i,j;
	for(i=0; i<SATIR; i++){
		for(j=0; j<SUTUN; j++){
			printf("%d ",*(*(mat+i)+j));
		}
		printf("\n");
	}
}

void matris_toplama(int mat1[][SUTUN],int mat2[][SUTUN],int top[][SUTUN]){
	int i,j;
	
	for(i=0; i<SATIR; i++){
		for(j=0; j<SUTUN; j++){
			*(*(top+i)+j) = *(*(mat1+i)+j) + *(*(mat2+i)+j);  //top[i][j] = mat1[i][j] + mat2[i][j]
		}
	}
		
	
}

void matris_carpma(int mat1[][SUTUN],int mat2[][SUTUN],int carp[][SUTUN]){
	int i,j,k;
	int sum;
	for(i=0; i<SATIR; i++){
		for(j=0; j<SUTUN; j++){
			sum=0;
			for(k=0; k<SUTUN; k++){
				sum += (*(*(mat1 + i) + k)) * (*(*(mat2 + k) + j));
			}
			
			*(*(carp + i) + j) = sum;
		}
	}
	
}

void matris_transpoz(int mat[][SUTUN],int trans[][SUTUN]){
	int i,j;

	for(i=0; i<SATIR; i++){
        for(j=0; j<SUTUN; j++){
            trans[j][i] = mat[i][j];
        }
    }
    

}

