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
TreeNode *inserttreenode(int data, TreeNode *root)
{
  // from start
  if (root == NULL)
  {
    TreeNode *ptr = (TreeNode *)malloc(sizeof(TreeNode));
    ptr->num = data;
    ptr->left = NULL;
    ptr->right = NULL;
    root = ptr;
    return root;
  }
  if (data < root->num)
  {
    root->left = inserttreenode(data, root->left);
  }
  else
  {
    root->right = inserttreenode(data, root->right);
  }
  return root;
}
void searchtreenode(TreeNode *root)
{
  if (root == NULL)
    return;

  searchtreenode(root->left);
  printf("root: %d\n", root->num);
  searchtreenode(root->right);
}
void binarysearchtree()
{
  /*
    NULL is a kind of binarysearchtree
    right child node > parent node
    left child node < parent node
  */
  TreeNode *root = NULL;
  int a[] = {2, 5, 1, 3, 4};
  int len = sizeof(a) / sizeof(int);
  /*
     example:
      [2]
      / \
    [1]  [4]
         / \
      [3]   [5]

   first element as root
  */
  int i = 0;
  while (i < len)
  {

    // get ptr next pointer and assign to ptr
    root = inserttreenode(a[i], root);
    i++;
  }

  //print binary search tree
  searchtreenode(root);

  // free, but it would automatically free when it exits the program
  free(root);
}