#include <stdio.h>
#include <stdlib.h>


#define SIZE 3

struct stack
{
    int Top;
    int arr[SIZE];
};
typedef struct stack STACK;
STACK s;

void Push();
void Pop();
void print();

int main()
{
	int Option;
	while (1)
	{
		printf("\nStadium Ticket Bookking System");

		printf("\nSelect:");
		printf("\n1. Book Tickets | 2. Unbook | 3. quit\n");
		scanf("%d", &Option);

		switch (Option)
		{
		case 1:
			Push();
			break;
		case 2:
			Pop();
			break;
		case 3:
			printf("Hope to see you next time !! ");
			exit(0);

		default:
			printf("\nInvalid");
		}
	}
}

void Push()
{
	int a;

	if (s.Top == SIZE - 1)
	{
		printf("\nPlease select a valid Option.");
	}
	else
	{
		printf("\nEnter tickets to be booked: ");
		scanf("%d", &a);
		s.Top = s.Top + 1;
		s.arr[s.Top] = a;
		printf(" %d Tickets booked \n \n \n",a);
	}
}

void print() {
	if (s.Top == -1) {
		printf("\nSelect a valid choice");
	}
	else { 
		printf("\n Enter no. of tickets to unbook: \n");
		for (int i = s.Top; i >= 1; --i)
			printf("Ticket %d: %d\n", i, s.arr[i]);
	}
}

void Pop()

{
	if (s.Top == -1)
	{
		printf("\nInvalid Option");
	}
	else
	{
		printf("\n Available Seats:  %d",s.arr[s.Top]);
		int temp;
		temp = s.arr[s.Top];
		s.Top = s.Top - 1;

	}
	}