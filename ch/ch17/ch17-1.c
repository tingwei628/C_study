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

Node *delete (int data, Node *head)
{
  if (head == NULL)
    return head;
  Node *after = NULL;
  Node *curr;
  curr = head;
  while (curr != NULL)
  {
    //prev = curr->next;
    if (curr->num == data)
    {
      if (after == NULL)
      {
        head = curr->next;
      }
      else
      {
        after->next = curr->next;
      }
    }
    else
    {
      after = curr;
    }
    curr = curr->next;
  }
  // give it a new head
  return head;
}
void sortlinkedlist()
{
  // head cannot be moved
  // the end node of linked list is prefered as NULL
  Node *head = NULL;
  int a[] = {2, 5, 1, 3, 4};
  int len = sizeof(a) / sizeof(int);
  int input;
  /*
    head  prev                    
          [5]->[4]->[3]->[2]->[1]->NULL
  */
  int i = 0;
  while (i < len)
  {
    head = insert(a[i], head);
    i++;
  }

  printf("input a number to delete\n");
  scanf("%d", &input); // do not use %d\n
  head = delete (3, head);

  //print sortlinked list
  for (; head != NULL; head = head->next)
  {
    printf("num: %d\n", head->num);
  }
}