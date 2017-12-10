#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "../index.h"

/*
  write and read from file to anther file
*/
void file2()
{
  FILE *fw;
  /*
    "r": read, file must exist
    "w": write, file if not exist, create. if exist, it would override.
    "a": append, file if not exist, create. if exist, it would append.
    "r+"
    "w+"
    "a+"
    "rb" : read as Binary format
   */
  // if cannot open, fopen would return NULL
  // NOTE!! This file path is relative to "index.c: main"
  fw = fopen("./ch/ch16/fprinf.txt", "w");
  if (fw == NULL)
    perror("Failed to open file\n"); // perror would print err in detail
  assert(fw != NULL);                // if fr = NULL, then stop!
  for (int i = 0; i < 5; i++)
  {
    // print to fw
    fprintf(fw, "%d\n", i);
  }
  printf("\n");
  fclose(fw);

  int sum = 0;
  int j;
  fw = fopen("./ch/ch16/fprinf.txt", "r");

  // scanf from file and save in j
  while ((fscanf(fw, "%d", &j)) != EOF)
  {
    sum += j;
  }
  printf("sum: %d\n", sum);
  // close file
  fclose(fw);
}