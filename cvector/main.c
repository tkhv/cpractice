#include "cvector.h"

int main(){
  vector_t* vec = init_vector(5);

  print_vector(vec);
  push(vec, 1);
  push(vec, 2);
  push(vec, 3);
  push(vec, 4);
  push(vec, 5);
  print_vector(vec);
  printf("popped: %d\n", pop(vec));
  push(vec, 6);
  printf("popped: %d\n", pop(vec));
  push(vec, 7);
  printf("popped: %d\n", pop(vec));
  printf("popped: %d\n", pop(vec));
  print_vector(vec);

  free_vector(vec);
  return 0;
}