#include "linked_list.h"

typedef struct _node
{
	int val;
	struct _node *next;
} Node;

typedef struct _linked_list
{
	int size;
	Node *begin;
} LinkedList;
