// 1 Write a C program to read a 2D array (with most of the elements as 0s) and then represent the same array as Sparse Metrics.
#include<stdio.h>
int main(){
	int a[3][3],i,j,zero=0,non_zero=0;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			printf("\nEnter Element: ");
			scanf("%d",&a[i][j]);
		}
	}
	printf("\nThe matrix is ");
	for(i=0;i<3;i++){
		printf("\n");
		for(j=0;j<3;j++){
			printf("%d\t",a[i][j]);
		}
	}
//	zero and non zero value counting
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			if(a[i][j]==0){
				zero++;
			}
			else{
				non_zero++;
			}
		}
	}
	if(zero<non_zero){
		printf("\nThis is not a sparse matrix");
	}
	else{
		int sparse[non_zero][3],k=0;
		for(i=0;i<3;i++){
			for(j=0;j<3;j++){
				if(a[i][j]!=0){
					sparse[k][0]=i;
					sparse[k][1]=j;
					sparse[k][2]=a[i][j];
					k++;
				}
			}
		}
		printf("\nThe sparse matrix is");
		printf("\nRow\tCol\tValue");
		for(i=0;i<non_zero;i++){
			printf("\n");
			for(j=0;j<3;j++){
				printf("%d\t",sparse[i][j]);
			}
		}
	}
	
	return 0;
}
