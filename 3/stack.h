#include<stdlib.h>

struct node{
	int i;
	int j;
	int num;
	struct node* next;
};

struct node* stack;

int pop(){
	if(stack == NULL){return -1;}
	struct node* p;
	int num = stack -> num;
	if(stack -> next != NULL){
		p = stack;
		stack = stack -> next;
	}
	else{
		p = stack;
		stack = NULL;
	}
	free(p);
	return num;
}

void push(int i, int j, int num){
	struct node* p = (struct node*)malloc(sizeof(struct node));
	p -> i = i;
	p -> j = j;
	p -> num = num;
	if(stack == NULL){
		stack = p;
	}
	else{
		p -> next = stack;
		stack = p;
	}
}
