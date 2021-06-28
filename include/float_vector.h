
#ifndef FLOAT_VECTOR
#define FLOAT_VECTOR



typedef struct float_vector FloatVector;



FloatVector *create(int capacity);
void destroy(FloatVector **vec_ref);
int size(const FloatVector *vec);
int capacity(const FloatVector *vec);
float at(const FloatVector *vec, int index);
float get(const FloatVector *vec, int index);
void append(FloatVector *vec, float value);
void set(FloatVector *vec, int index, float value);
void print(const FloatVector *vec);
void FloatVector_remove(FloatVector *vec, int index);

#endif