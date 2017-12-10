#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "../index.h"

/*
  read and write line by line with file
*/
void file1()
{
  FILE *fr;
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
  fr = fopen("./ch/ch16/mytxt.txt", "r");
  int each_time_bytes = 12;
  char str[each_time_bytes];
  if (fr == NULL)
    perror("Failed to open file\n"); // perror would print err in detail
  assert(fr != NULL);                // if fr = NULL, then stop!
  // read from file, line by line
  // read and save to str
  while (fgets(str, each_time_bytes, fr) != NULL)
  {
    // each time read each_time_bytes
    printf("%s\n", str);
    // each time read string length
    printf("strlen: %lu\n", strlen(str));
  }
  printf("\n");

  while (!feof(fr)) // this is the same as fgets(str, each_time_bytes, fr) != NULL
  {
    // each time read each_time_bytes
    printf("%s\n", str);
    // each time read string length
    printf("strlen: %lu\n", strlen(str));
  }
  printf("\n");
  // close file
  fclose(fr);
}