#ifndef QUEES_H
#define QUEES_H


typedef struct Qnode {
	
	int data;
	struct Qnode *next;
}Qnode;

typedef struct Quee{
	Qnode *front, *rear;
}Quee;

typedef struct Stack {
	
	Qnode *top;
}Stack;

Qnode *createNode(int data);
Quee *createQuees();
Stack *createStacK();
void enqueue(Quee *q, int data);
int dequeue(Quee *q);
int count(Quee *q);
int getFrontQuee(Quee *q);
int getRearQuee(Quee *q);
int isEmpty(Quee *q);
int isEmptyStack(Stack *stack);
int FindMax(Quee *q);
int FindMin(Quee *q);
void push(Stack *stack, int data);
int pop(Stack *stack);
void reverseQuee(Quee *q);
Quee *mergedQuees(Quee *q1, Quee *q2);
void removeduplicate(Quee *q);
int havingDuplicate(Quee *q);
void ishavingDup(Quee *q);
int getSum(Quee *q);
float Average(Quee *q);
double medianQueue(Quee *q);
int modeQuee(Quee *q);
void printList(Quee *q);
#endif
