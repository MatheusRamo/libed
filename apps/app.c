#include "float_vector.h"
#include "linked_list.h"
#include <stdio.h>

int main()
{
	FloatVector *vec = create(2);
	append(vec, 1.0);
	append(vec, 2.0);
	print(vec);

	LinkedList *list = LinkedList_create();
	LinkedList_add_first(list, 2);
	LinkedList_add_first(list, 1);
	LinkedList_print(list);

	destroy(&vec);

	return 0;
}
