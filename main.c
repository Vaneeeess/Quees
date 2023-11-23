#include <stdio.h>
#include <stdlib.h>
#include "Quees.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	
	
	int data;
	
	Quee *q = createQuees();
	
	char choice;
	do {
		
		printf("Enter the you to add to Quee: ");
		scanf("%d", &data);
		enqueue(q, data);
		
		printf("Do you want to add another? (y/n): ");
		scanf(" %c", &choice);
	}while(choice == 'Y' || choice == 'y');
	
	system("cls");
	
	int choices;
	do {
		
		printf("\n1. Delete 1 Quee\n");
		printf("2. Count the Quee\n");
		printf("3. Get the fornt or peek\n");
		printf("4. Get the rear or idk xd\n");
		printf("5. Check if its empty\n");
		printf("6. Find the Max\n");
		printf("7. Find the Min\n");
		printf("8. Reverse the Quee\n");
		printf("9. if there is two Quess Merged it\n");
		printf("10. Remove the duplicates\n");
		printf("11. Check if is your quee is having duplicate\n");
		printf("12. Get the sum\n");
		printf("13. Get the Average\n");
		printf("14. Get the median\n");
		printf("15. Mode Quee (means it returns the number na ga balik balik xd)\n");
		printf("16. Print the Quees\n");
		printf("100. Exit the Program\n");
		
		printf("Enter your choice majesty: ");
		scanf("%d", &choices);
		
		switch(choices) {
			
			case 1: {
				dequeue(q);
				printf("\nSuccess fully deleted!\n");
				break;
			}
			case 2: {
				printf("\nThe number of Quees: %d\n", count(q));
				break;
			}
			case 3: {
				printf("\nThe front of Quee: %d\n", getFrontQuee(q));
				break;
			}
			case 4: {
				printf("\nThe rear of Quee: %d\n", getRearQuee(q));
				break;
			}
			case 5: {
				printf("\n%d\n", isEmpty(q));
				break;
			}
			case 6: {
				printf("\nThe max number in Quee: %d\n", FindMax(q));
				break;
			}
			case 7: {
				printf("\nThe min number in Quee: %d\n", FindMin(q));
				break;
			}
			case 8: {
				reverseQuee(q);
				printf("\nSuccess fully Reversed!\n");
				break;
			}
			case 9: {
				Quee *q2 = createQuees();
				
				int data; 
				char xd;
				do {
					
					printf("Enter data q2 to add: ");
					scanf("%d", &data);
					enqueue(q2, data);
					
					printf("Do you want to add another (y/n): ");
					scanf(" %c", &xd);
				}while(xd == 'Y' || choice == 'y');
				
				Quee *lol = mergedQuees(q, q2);
				
				printList(lol);
				break;
			}
			case 10: {
				removeduplicate(q);
				printList(q);
				break;
			}
			case 11: {
				printf("\nIf (1) it has duplicats or (0) no duplicats!\n");
				ishavingDup(q);
				break;
			}
			case 12: {
				printf("\nThe sum of Quee is: %d\n", getSum(q));
				break;
			}
			case 13: {
				printf("\nThe average of Quee is: %.2f\n", Average(q));
				break;
			}
			case 14: {
				printf("\nThe median is: %.2lf\n", medianQueue(q));
				break;
			}
			case 15: {
				printf("\nThe number that is ga balik balik is: %d\n", modeQuee(q));
				break;
			}
			case 16: {
				printList(q);
				break;
			}
			case 100: {
				printf("\nExiting The program!\n");
				break;
			}
			default:
				printf("\nInavlid choice!\n");
		}
	}while(choices != 100);
	
	return 0;
}
