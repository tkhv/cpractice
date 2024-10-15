#include <stdlib.h>
#include <stdio.h>
#include "cvector.h"

vector_t* init_vector(unsigned int capacity)
{
  int* vec_ptr = malloc(sizeof(int) * capacity);
  if (!vec_ptr) {
    free(vec_ptr);
    return NULL;
  }

  vector_t* vec = malloc(sizeof(vector_t));
  if (!vec) {
    free(vec);
    return NULL;
  }
  
  vec->start = vec_ptr;
  vec->end = vec_ptr + capacity;
  vec->size = 0;
  vec->capacity = capacity;

  return vec;
}

void print_vector(vector_t* vec)
{
  if (!vec || !(vec->start)) return;

  printf("vector struct ptr: %p\n", vec);
  printf("vec->start: %p\n", vec->start);
  printf("vec->end: %p\n", vec->end);
  printf("vec->size: %zd\n", vec->size);
  printf("vec->capacity: %zd\n", vec->capacity);

  for (int i = 0; i < vec->size; i++)
  {
    printf("vec[%d]: %d\n", i, *vec->start+i);
  }
}

bool free_vector(vector_t* vec)
{
  if (!vec || !(vec->start)) return false;
  
  free(vec->start);
  free(vec);

  return true;
}

static bool incr_size(vector_t* vec) 
{
  
  int* new_vec_ptr = malloc(vec->capacity * 2 * sizeof(int));
  if (!new_vec_ptr) 
  {
    free(new_vec_ptr);
    return false;
  };

  memcpy(new_vec_ptr, vec->start, (vec->capacity * sizeof(int)));

  vec->start = new_vec_ptr;
  vec->end = new_vec_ptr + vec->size;
  vec->capacity *= 2;
  return true;
}

bool push(vector_t* vec, int integer)
{
  if (!vec || !(vec->start)) return false;

  if (vec->capacity <= vec->size) 
  {
    incr_size(vec);
    if (!vec) return false;
  };
  
  *(vec->start + vec->size) = integer;
  vec->size += 1;

  return true;
}

int pop(vector_t* vec)
{
  if (!vec || !(vec->start) || !vec->size) return false;

  int popped_int = *(vec->start+vec->size-1);
  *(vec->start+vec->size) = 0;
  vec->size -= 1;
  
  return popped_int;
}

