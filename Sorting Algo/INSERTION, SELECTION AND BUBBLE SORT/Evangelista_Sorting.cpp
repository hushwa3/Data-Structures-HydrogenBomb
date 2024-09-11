#include<stdio.h>
#include<stdlib.h>
#define MAX 6


int bubbleSort(int array[]){
	int index, i, temp; 
	for(int i = 0; i < MAX; i++){
		index = MAX - 1;
		printf("i = %d\n", i);
	while(index >= (i + 1)){
		if(array[index - 1] > array[index]){
			temp = array[index];
			array[index] = array[index - 1];
			array[index - 1] = temp;
		}
		index = index - 1;
		printf("\t");
		for(int i = 0; i < MAX; i++){
			printf("%d ", array[i]);
		}
		printf("\n");
	}
}
	
}
int main(){
	int choice;
	int array[MAX];
	do{
		printf("1 - Bubble Sort\n");
		printf("2 - Display\n");
		printf("3 - Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);
		switch(choice){
		
		case 1:
			printf("Enter %d numbers: ", MAX);
			for(int i = 0; i < MAX; i++){
				scanf("%d", &array[i]);
			}
			bubbleSort(array);
			break;
		case 2:
			break;
		case 3:
			exit(0);
		default:
			printf("Wrong input.\n");
		}
	}while(choice != 3);
	
	return 0;
}
