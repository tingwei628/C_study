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

//iterate
Node *insert(int data, Node *head)
{
  Node *ptr = (Node *)malloc(sizeof(Node));
  Node *prev;
  Node *curr;
  // from start
  if (head == NULL || head->num <= data)
  {
    ptr->num = data;
    ptr->next = head;
    head = ptr;
    return head;
  }

  curr = head;
  while (curr->num > data)
  {
    prev = curr->next;
    if (prev == NULL || prev->num <= data)
    {
      ptr->num = data;
      ptr->next = prev;
      curr->next = ptr;
      break;
    }
    else
    {
      curr = prev;
    }
  }
  return head;
}
void sortlinkedlist()
{
  // head cannot be moved
  // the end node of linked list is prefered as NULL
  Node *head = NULL;
  int a[5] = {2, 5, 1, 3, 4};
  /*
    head  prev                    
          [5]->[4]->[3]->[2]->[1]->NULL
  */
  int i = 0;
  while (i < 5)
  {
    head = insert(a[i], head);
    i++;
  }

  //print sortlinked list
  for (; head != NULL; head = head->next)
  {
    printf("num: %d\n", head->num);
  }
}