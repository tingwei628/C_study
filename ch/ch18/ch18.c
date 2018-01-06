#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "../index.h"
/*
  stack FILO
  init: initialize the stack
  empty: test it is empty
  full: test it is full
  push: insert data
  pop: get data
*/

void init_stack(Stack *p)
{
  p->ptr = 0;
}
int isempty_stack(Stack *p)
{
  return p->ptr <= 0;
}

int isfull_stack(Stack *p)
{
  return p->ptr >= (sizeof(p->elements) / sizeof(int));
}
void push_stack(Stack *p, Data c)
{
  if (isfull_stack(p))
  {
    printf("Stack is full now");
    return;
  }

  p->elements[p->ptr] = c;
  p->ptr++; //next index
}
int pop_stack(Stack *p)
{
  if (isempty_stack(p))
  {
    printf("Stack is empty now");
    return -1;
  }
  p->ptr--;
  return p->elements[p->ptr];
}

//#define DEBUG 1

// if DEBUG is not defined in command line
// DEBUG would be 2
// avoid REdefined
#ifndef DEBUG
#define DEBUG 2
#endif

//defined a function with multiple lines
//don't forget slash(\)
// __FILE__ means in which file
// __LINE__ means in which line
#define assert_me(condition)                             \
  if (!(condition))                                      \
  {                                                      \
    printf("assert me failed: %s\nfile: %s\nline: %d\n", \
           #condition, __FILE__, __LINE__);              \
    exit(0);                                             \
  }
//gcc -Wall -std=c11 ./ch/ch18/*.c ./ch/index.c  -o e -DDEBUG=100

void stack()
{
#if DEBUG > 0 // condition compile
  printf("print %d in DEBUG mode\n", DEBUG);
  assert_me(DEBUG == 0);
#endif
}