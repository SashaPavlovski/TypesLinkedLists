#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#pragma warning(disable: 4996)

struct Item
{
	int val;
	int val2;
	int id;
	struct Item* next;
	struct Item* prev;
};


struct Item* head = NULL;
struct Item* tail = NULL;
struct Item* old;
int count = 0;


void push(int val, int val2)
{
	struct Item* move = (struct Item*)malloc(sizeof(struct Item));

	if (!move)
	{
		exit(1);
	}
	if (head == NULL)
	{
		head = move;
		tail = move;
		move->prev = NULL;
		move->next = NULL;
	}
	else
	{
		tail = move;
		move->next = NULL;
		move->prev = old;
		old->next = move;
	}
	count++;
	move->id = count;
	move->val = val;
	move->val = val2;
	old = move;

}

void pop()
{
	struct Item* move = tail;
	struct Item* current = tail;

	if (move != NULL)
	{
		current = move;
		move = move->prev;
		move->next = NULL;
		tail = move;

		return current;
	}

}

void Search(int id)
{
	struct Item* move = head;
	struct Item* current = head;

	while (move != NULL)
	{
		current = move;
		move = move->next;
        if(current->id == id)
		{
			printf("The first value %d\nThe second value %d\nID number %d\n",current->val,current->val2,current->id);
        }

	}

}


void printing_all()
{
	struct Item* move = head;
	struct Item* current = head;

	while (move != NULL)
	{
		current = move;
		move = move->next;
        printf("The first value %d\nThe second value %d\nID number %d\n", current->val, current->val2, current->id);


	}

}




void Sum()
{
	struct Item* move = head;
	struct Item* current = head;
	int sum = 0;

	for (int i = 0; i < 10; i++)
	{
		current = move;
		move = move->next;
		sum = sum + current->val;

	}
	printf("%d\n", sum);

}


int main()
{
	srand(time());
	int num_1;
	int num_2;
	int ID_number;
	char userResponse = '1';
	while (userResponse != 'E')
	{
		printf("Press E to exit the program\nPress I to add two random numbers to the program\nPress P to enter an ID number and get a value\nPress L to print all lists\nPress B to insert 100 random items into database\nPress Z to perform a multiple withdrawal, this action removes 10 items from the stack and prints their val sum\");
		userResponse = getch();

		switch (userResponse)
		{
		case 'E': printf("The program is over\n");
			exit(1);
			break;
		case 'I': printf("The numbers have been added\n");
			num_1 = rand();
			num_2 = rand();
			push(num_1, num_2);
			break;
		case 'p': printf("enter the ID you want to print\n");
			scanf("%d",&ID_number);
			Search(ID_number);ä
			break;
		default:
		case 'L': printf("Printing all documents\n");
			printing_all();
			break;
		case 'B': printf("100 random numbers were entered\n");
			for (int i = 0; i < 100; i++)
			{
				num_1 = rand();
				num_2 = rand();
				push(num_1, num_2);
			}

			break;
		case 'Z': printf("The sum of 10 numbers is\n");
			Sum();
			break;
		}
	}

	return 0;
}