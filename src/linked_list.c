#include "linked_list.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct _node
{
	int val;
	struct _node *next;
} Node;

typedef struct _linked_list
{
	Node *begin;
} LinkedList;

Node *Node_create(int val)
{
	Node *node = (Node *)calloc(1, sizeof(Node));
	node->next = NULL;
	node->val = val;

	return node;
}

LinkedList *LinkedList_create()
{
	LinkedList *link = (LinkedList *)calloc(1, sizeof(LinkedList));
	link->begin = NULL;

	return link;
}

void LinkedList_add_first(LinkedList *link, int val)
{
	Node *p = Node_create(val);
	p->next = link->begin;
	link->begin = p;
}

void LinkedList_print(const LinkedList *link)
{
	Node *p = link->begin;
	printf("[ ");
	while (p != NULL)
	{
		printf("[%d] ", p->val);
		p = p->next;
	}
	printf("]\n");
	
}
