#include <stdio.h>
#include <assert.h>
#include "../index.h"
/*
  read and write char by char with file
*/
void file()
{
  FILE *fr, *fw;
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

  // NOTE!! This file path is relative to "index.c main"
  fr = fopen("./ch/ch16/mytxt.txt", "r");
  fw = fopen("./ch/ch16/newmytxt.txt", "w");
  if (fr == NULL)
    perror("Failed to open file\n"); // perror would print err in detail
  assert(fr != NULL);                // if fr = NULL, then stop!
  assert(fw != NULL);                // if fw = NULL, then stop!
  char c = '\0';
  // read from file, char by char
  while ((c = fgetc(fr)) != EOF)
  {
    fputc(c, fw); // read fr and write to fw
    printf("%c", c);
  }
  printf("\n");

  // close file
  fclose(fr);
  fclose(fw);

  fw = fopen("./ch/ch16/newmytxt.txt", "r");
  while ((c = fgetc(fw)) != EOF)
    fputc(c, stdout); // as same as printf
  printf("\n");
  fclose(fw);

  //r+ support write, and relplace some content
  fr = fopen("./ch/ch16/mytxt.txt", "r+");
  for (int i = 0; i < 3; i++)
    fputc('R', fr);
  fclose(fr);

  // w+ support read, and erase old content
  fr = fopen("./ch/ch16/mytxt.txt", "w+");
  for (int i = 0; i < 3; i++)
    fputc('R', fr);
  fclose(fr);
}