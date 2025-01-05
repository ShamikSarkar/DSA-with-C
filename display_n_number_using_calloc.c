// 7 Write a program to display n number of elements. Memory should be allocated dynamically using calloc( ).
#include<stdio.h>
#include<stdlib.h>
int main(){
	int n;
	int *arr;
	
	printf("\nEnter the number of elements: ");
	scanf("%d",&n);
	
	arr=(int *)calloc(n,sizeof(int));
	if(arr==NULL){
		printf("\nMemory allocation failed");
	}
	else{
		for(int i=0;i<n;i++){
			printf("\nEnter  element: ");
			scanf("%d",&arr[i]);
		}
		for(int i=0;i<n;i++){
			printf("%d\t",arr[i]);
		}
	}
	free(arr);
	return 0;
}
