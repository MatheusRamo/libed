#include "float_vector.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct float_vector
{
	int capacity;
	int size;
	float *data;
};

bool indexInvalid(FloatVector *vec, int index)
{
	if (index < 0 || index >= vec->size)
		return true;
	else
		return false;
}

FloatVector *create(int capacity)
{
	FloatVector *vec = (FloatVector *)calloc(1, sizeof(FloatVector));
	vec->size = 0;
	vec->capacity = capacity;
	vec->data = (float *)calloc(capacity, sizeof(float));

	return vec;
}

void destroy(FloatVector **vec_ref)
{
	FloatVector *vec = *vec_ref;
	free(vec->data);
	free(vec);
	*vec_ref = NULL;
}

int size(const FloatVector *vec)
{
	return vec->size;
}

int capacity(const FloatVector *vec)
{
	return vec->capacity;
}

float at(const FloatVector *vec, int index)
{
	if (index < 0 || index >= vec->size)
	{
		fprintf(stderr, "ERROR in 'at'\n");
		fprintf(stderr, "index error\n");
		exit(EXIT_FAILURE);
	}

	return vec->data[index];
}

float get(const FloatVector *vec, int index)
{
	return vec->data[index];
}

void append(FloatVector *vec, float value)
{
	if (vec->size == vec->capacity)
	{
		fprintf(stderr, "ERROR in 'append'\n");
		fprintf(stderr, "vector is full\n");
		exit(EXIT_FAILURE);
	}

	vec->data[vec->size] = value;
	vec->size++;
}

void set(FloatVector *vec, int index, float value)
{
	if (index < 0 || index >= vec->size)
	{
		fprintf(stderr, "ERROR in 'set'\n");
		fprintf(stderr, "index not exist\n");
		exit(EXIT_FAILURE);
	}

	vec->data[index] = value;
}

void FloatVector_remove(FloatVector *vec, int index)
{
	if (!indexInvalid(vec, index))
	{
		int i;
		for (i = index; i < vec->size - 1; i++)
		{
			vec->data[i] = vec->data[i + 1];
		}
		vec->data[i] = 0.0;
		vec->size--;
	}
	else
	{
		fprintf(stderr, "Index Invalid\n");
	}
}

void print(const FloatVector *vec)
{
	puts("================================");
	printf("size: %d\n", vec->size);
	printf("capacity: %d\n", vec->capacity);

	for (int i = 0; i < vec->size; i++)
	{
		printf("[%d] = %f\n", i, vec->data[i]);
	}
	puts("================================");
}