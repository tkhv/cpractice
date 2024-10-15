#ifndef CVECTOR_H
#define CVECTOR_H

#include <stdbool.h>
#include <stddef.h>

typedef struct {
  int* start;
  int* end;
  size_t size;
  size_t capacity;
} vector_t;

vector_t* init_vector(unsigned int capacity);

bool free_vector(vector_t* vec);

void print_vector(vector_t* vec);

bool push(vector_t* vec, int integer);

int pop(vector_t* vec);

#endif