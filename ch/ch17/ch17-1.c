#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "../index.h"
/*
  stdlib.h
  malloc
  free

  basic:
    struct node *ptr;
    // cast to struct node *
    ptr = (struct node *)malloc(sizeof(struct node));

    //relase memory to the system
    free(ptr);
    
    //NOTE: malloc return void *, it is undefined type pointer
*/
void sortlinkedlist()
{
  // head cannot be moved
  // the end node of linked list is prefered as NULL
  Node *head;
  Node *prev = NULL;
  int a[5] = {1, 2, 3, 4, 5};
  /*
    head prev                    
    [5]->[4]->[3]->[2]->[1]->NULL
  */
  int i = 0;
  while (i < 5)
  {

    // get ptr next pointer and assign to ptr
    head = (Node *)malloc(sizeof(Node));
    head->num = a[i];
    head->next = prev;
    prev = head; // give new address to prev, it means "move prev"
    i++;
  }

  //print linked list
  for (; head != NULL; head = head->next)
  {
    printf("num: %d\n", head->num);
  }
}