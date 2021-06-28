#include "float_vector.h"
#include "hello.h"
#include <stdio.h>

int main()
{
	FloatVector *vec = create(2);
	append(vec, 1.0);
	append(vec, 2.0);
	print(vec);

	hello();

	destroy(&vec);

	return 0;
}