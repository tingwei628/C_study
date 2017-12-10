#include <stdio.h>
#include <assert.h>
#include "../index.h"

/*
  write and read from "string" to another "string"
*/
void file4()
{
  FILE *fw, *fr;

  // M is defined in header file
  M m[2] = {
      {"one", 1, {12, 1}},
      {"two", 2, {12, 2}}};

  // write the m to file in binary format;
  fw = fopen("./ch/ch16/fwrite_in_binary.txt", "wb");
  assert(fw != NULL);
  /*
    use fwrite for binary write 
    m is source
    sizeof(M) is each time writable size
    2 is total time
  */
  fwrite(m, sizeof(M), 2, fw);
  fclose(fw);

  /*
    fseek
    offset is the unit of bytes to jump 
    1.SEEK_SET: start from start of file
    2.SEEK_CUR: start from current position
    3.SEEK_END: start from end of file

    ex. fseek(fp, -1 * sizeof(M), SEEK_END);
    offset  = -1 * sizeof(M);
    start from the end of file, and jump -1 *sizeof(M) 
  */
  M b;
  fr = fopen("./ch/ch16/fwrite_in_binary.txt", "rb");

  fseek(fr, -2 * sizeof(M), SEEK_END); // -1 means forwards

  // start from end of file and jump forward two M
  // b is dest, read from fr
  // each time read M
  // total time is 1
  fread(&b, sizeof(M), 1, fr);
  printf("b.name %s\n", b.name); // one, cause it's the first element
  fclose(fr);
}