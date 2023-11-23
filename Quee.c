#include <stdio.h>
#include <stdlib.h>
#include "Quees.h"

Qnode *createNode(int data) {
	
	Qnode *newNode = (Qnode*)malloc(sizeof(Qnode));
	
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}


Quee *createQuees() {
	
	Quee *q = (Quee*)malloc(sizeof(Quee));
	
	q->front = q->rear = NULL;
	return q;
}

Stack *createStacK() {
	
	Stack *stack = (Stack*)malloc(sizeof(Stack));
	
	stack->top = NULL;
	return stack;
}
void enqueue(Quee *q, int data) {
	
	Qnode *newNode = createNode(data);
	
	if(q->front == NULL) {
		
		q->front = q->rear = newNode;
	}
	
	q->rear->next = newNode;
	q->rear = newNode;
}

int dequeue(Quee *q) {
	
	if(q->front == NULL) {
		printf("No Quee to delete!");
		return -1;
	}
	
	Qnode *temp = q->front;
	int item = temp->data;
	q->front = q->front->next;
	free(temp);
	return item;
}


int count(Quee *q) {
	
	Qnode *temp = q->front;
	
	int count = 0;
	while(temp != NULL) {
		count++;
		temp = temp->next;
	}
	
	return count;
}

int getFrontQuee(Quee *q) {
	return (q->front != NULL) ? (q->front)->data : -1;
}

int getRearQuee(Quee *q) {
	return (q->rear != NULL) ? (q->rear)->data : -1;
}


int isEmpty(Quee *q) {
	return (q->front == NULL);
}

int isEmptyStack(Stack *stack) {
	return (stack->top == NULL);
}
int FindMax(Quee *q) {
	
	if(isEmpty(q)) {
		return -1;
	}
	
	Qnode *temp = q->front;
	int max = q->front->data;
	
	while(temp != NULL) {
		if(temp->data > max) {
			max = temp->data;
		}
		temp = temp->next;
	}
	
	return max;
}

int FindMin(Quee *q) {
	
	if(isEmpty(q)) {
		return -1;
	}
	
	Qnode *temp = q->front;
	int min = q->front->data;
	
	while(temp != NULL) {
		if(temp->data < min) {
			min = temp->data;
		}
		temp = temp->next;
	}
	
	return min;
}

void push(Stack *stack, int data) {
	
	Qnode *newNode = createNode(data);
	
	if(stack->top == NULL) {
		stack->top = newNode;
	}
	
	newNode->next = stack->top;
	stack->top = newNode;
}

int pop(Stack *stack) {
	
	if(stack->top == NULL) {
		printf("No to pop!");
		return -1;
	}
	
	Qnode *temp = stack->top;
	int item = temp->data;
	stack->top = stack->top->next;
	free(temp);
	return item;
}


void reverseQuee(Quee *q) {
	
	Stack *stack = createStacK();
	
	while(!isEmpty(q)) {
		push(stack, dequeue(q));
	}
	
	while(!isEmptyStack(stack)) {
		enqueue(q, pop(stack));
	}
	
	free(stack);
}

Quee *mergedQuees(Quee *q1, Quee *q2) {
	
	Quee *tempQuee = createQuees();
	
	while(!isEmpty(q1)) {
		enqueue(tempQuee, dequeue(q1));
	}
	
	while(!isEmpty(q2)) {
		enqueue(tempQuee, dequeue(q2));
	}
	
	return tempQuee;
}

void removeduplicate(Quee *q) {
	
	if(isEmpty(q)) {
		return;
	}
	
	Qnode *temp = q->front;
	
	while(temp != NULL && temp->next != NULL) {
		if(temp->data == temp->next->data) {
			Qnode *toremove = temp->next;
			temp->next = toremove->next;
			free(toremove);
			if(toremove == q->rear) {
				q->rear = temp;
			}
		}else {
			temp = temp->next;
		}
	}
}

int havingDuplicate(Quee *q) {
	
	if(isEmpty(q)) {
		return -1;
	}
	
	Qnode *temp = q->front;
	
	while(temp != NULL && temp->next != NULL) {
		if(temp->data == temp->next->data) {
			return 1;
		}
		temp = temp->next;
	}
}

void ishavingDup(Quee *q) {
	
	if(isEmpty(q)) {
		return;
	}
	
	if(havingDuplicate(q)) {
		printf("The Quess is having duplicate!");
		return;
	}else {
		printf("The Quess is not having duplicate!");
	}
}

int getSum(Quee *q) {
	
	if(isEmpty(q)) {
		return -1;
	}
	
	Qnode *temp = q->front;
	
	int sum = 0;
	while(temp != NULL) {
		sum+=temp->data;
		temp = temp->next;
	}
	
	return sum;
}

float Average(Quee *q) {
	
	float avg = 0.0;
	if(isEmpty(q)) {
		return avg;
	}
	
	avg = (float) getSum(q) / count(q);
	
	return avg;
}

double medianQueue(Quee *q) {
	
	if(isEmpty(q)) {
		return -1;
	} 
	Quee *tempQuee = createQuees();
	
	Qnode *temp = q->front;
	
	int size = 0;
	while(temp != NULL) {
		enqueue(tempQuee, dequeue(q));
		temp = temp->next;
		size++;
	}
	
	int middle = size / 2;
	
	for(int i = 0; i < middle; i++) {
		dequeue(tempQuee);
	}
	
	double median;
	
	if(size % 2 == 0) {
		median = (tempQuee->front->data + tempQuee->front->next->data) / 2.0;
	}else {
		median = tempQuee->front->data;
	}
	
	free(tempQuee);
	
	return median;
}

int modeQuee(Quee *q) {
	
	if(isEmpty(q)) {
		return -1;
	}
	
	Qnode *temp = q->front;
	
	int count[1000] = {0};
	int xd = -1;
	int max = 0;
	
	while(temp != NULL) {
		count[temp->data]++;
		if(count[temp->data] > max) {
			max = count[temp->data];
			xd = temp->data;
		}
		temp = temp->next;
	}
	
	return xd;
}

void printList(Quee *q) {
	
	Qnode *temp = q->front;
	
	while(temp != NULL) {
		printf("%d -> ", temp->data);
		temp = temp->next;
	}
	
	printf("NULL\n");
}



