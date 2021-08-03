#include <stdio.h>

#define my_offsetof(ptr, member_name) \
  (((size_t) (&(ptr)->member_name)) - ((size_t) ptr))

typedef struct {
    float f;
    int member;
    char c;
} t_struct;

t_struct* get_struct_ptr(void* member_ptr) {
  t_struct t;
  return (t_struct*)((char*) member_ptr - my_offsetof(&t, member));
}

int main(void) {
  t_struct  test;
  t_struct* ptr;

  // Retrieving the pointer to the structure `test` given a pointer to on of its member.
  ptr = get_struct_ptr(&test.member);
  if (ptr == &test) {
    printf("Address of the structure : %p\n", ptr);
  } else {
    printf("Failed to find the pointer to the structure\n");
  }
  
  return (0);
}