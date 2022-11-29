#include <stdio.h>
#include<stdlib.h>

typedef struct cell
{
	int val;
	struct cell* next;
}CELL;

void create(CELL* list, int val);
void index(CELL* list);

int main()
{
	int val;
	//�擪�̃Z����錾
	CELL head;
	head.next = nullptr;

	while (true)
	{
		printf(" \n");

		scanf_s("%d", &val);

		create(&head, val);

		index(&head);
	}
	return 0;
}

void create(CELL* list, int val) {
	CELL* NewCell;
	NewCell = (CELL*)malloc(sizeof(CELL));

	NewCell->val = val;
	NewCell->next = nullptr;

	while (list->next != nullptr) {
		list = list->next;
	}
	list->next = NewCell;
}

void index(CELL* list)
{
	while (list->next != nullptr)
	{
		list = list->next;
		printf("[%d]\n", list->val);
	}
}


