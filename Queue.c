#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
int id_counter = 0;

void removeitemfromtail()
{
	struct Item* move = head;
	head = head->next;

	free(move);
}

void PrintList()
{
	struct Item* move = head;
	struct Item* prev = head;

	while (move != NULL)
	{
		prev = move;
		move = move->next;
		printf("%d, %d, %d", prev->val, prev->val2, prev->id);

	}

}
void AddItemToHead(int val, int val2)
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
		move->next = NULL;
		move->prev = NULL;
	}
	else
	{
		tail = move;
		move->prev = old;
		move->next = NULL;
		old->next = move;
	}
	id_counter++;
	move->val = val;
	move->val2 = val2;
	move->id = id_counter;
	old = move;

	PrintList();
	removeitemfromtail();
}


int main()
{
	AddItemToHead(5, 6);
	AddItemToHead(7, 3);
	return 0;
}











