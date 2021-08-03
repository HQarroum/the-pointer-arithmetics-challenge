#include <stdio.h>

/**
 * A cross-platform and compiler independant implementation
 * of offsetof.
 */
#define my_offsetof(ptr, member_name) \
  (((size_t) (&(ptr)->member_name)) - ((size_t) ptr))

/**
 * An example structure that holds members of different
 * types and sizes that we will be using in our example.
 */
typedef struct {
    float f;
    int member;
    char c;
} t_struct;

/**
 * A function returning a pointer to a structure of type `t_struct`
 * given a pointer to one of its member.
 */
t_struct* get_struct_ptr(void* member_ptr) {
  t_struct t;
  return (t_struct*)((char*) member_ptr - my_offsetof(&t, member));
}

/**
 * Implements an example in which we declare a structure that is
 * initialized to known values and try to retrieve its address given
 * a pointer to one of its member.
 */
int main(void) {
  t_struct  test = {
    .f = 1.0,
    .member = 42,
    .c = 0x42
  };
  ;

  // Retrieving the pointer to the structure `test` given a pointer to one of its member.
  t_struct* ptr = get_struct_ptr(&test.member);
  
  if (ptr == &test) {
    printf("Address of the structure : %p, Value of member : %d\n", ptr, ptr->member);
  }
  
  return (0);
}