// 5 Write a program that reads a 2D metrics and checks if the metrics is a symmetric metrics or not.
#include<stdio.h>
# define MAX 100
int isSymentric(int matrix[MAX][MAX],int n){
	for (int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(matrix[i][j]!=matrix[j][i]){
				return 0;
			}
		}
	}
	return 1;
}
int main(){
	int matrix[MAX][MAX],n;
	printf("\nEnter the size of the sqare matrix: ");
	scanf("%d",&n);
	
	printf("\nEnter elements of the matrix: ");
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			
			scanf("%d",&matrix[i][j]);
		}
	}
	if(isSymentric(matrix,n)){
		printf("\nThe matrix is symentric");
	}
	else{
		printf("\nThe matrix is not symentric");
	}
	
	return 0;
}
