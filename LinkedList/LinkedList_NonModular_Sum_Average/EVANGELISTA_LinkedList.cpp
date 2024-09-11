#include<stdio.h>
#include<stdlib.h>

struct node{
	int x;
	struct node *next;
};
typedef struct node nd;
nd *head, *p;
int main(){
	int num, ans, sum=0, counter = 1;
	float ave;
	
	head = (nd*)malloc(sizeof(nd));
	p = head;
	printf("Enter a number: ");
	scanf("%d", &p->x);
	printf("Press 1 to enter another num or any number to quit: ");
	scanf("%d", &ans);	
	
	p = head;
	
	while(ans == 1){
		p->next = (nd*)malloc(sizeof(nd));
		printf("Enter a number: ");
		scanf("%d", &num);
		p->next->x = num;
		p = p->next;
		printf("Press 1 to enter another num or any number to quit: ");
		scanf("%d", &ans);
		counter++;
	}
	p->next = NULL;
	
	p=head;
	while(p != NULL){
		sum += p->x;
		p = p->next;
		ave = (float) sum / counter;
	}
	printf("\nSum: %d", sum);
	printf("\nAverage: %.2f", ave);
	return 0;
}
