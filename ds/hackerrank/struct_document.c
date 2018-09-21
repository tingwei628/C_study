#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5
/*
  1. 同時多個切割字串時, 使用strtok_r
	2.  struct pointer 的加減 也同其他type pointer 規格
	例: ((Doc.data)+(k-1));
	注意: 這是錯的用法 => ((Doc.data) + (k-1) * sizeof(struct paragraph))
	3. strncpy 複製字串到 char*
*/
struct word {
	char* data;
};

struct sentence {
	struct word* data;
	int word_count; //denotes number of words in a sentence
};

struct paragraph {
	struct sentence* data  ;
	int sentence_count;//denotes number of sentences in a paragraph
};

struct document {
	struct paragraph* data;
	int paragraph_count;//denotes number of paragraphs in a document
};

struct document get_document(char* text) {
  struct document d = { .paragraph_count = 0, .data = NULL };
  struct paragraph* pptr = NULL;
  char deli[] = "\n";
  char deli1[] = ".";
  char deli2[] = " ";
  char* s0_save_ptr= NULL;
  char* s1_save_ptr = NULL;
  char* s2_save_ptr = NULL;
  char* s0 = strtok_r(text, deli, &s0_save_ptr);
  while (s0 != NULL) {
      d.paragraph_count++;
      struct paragraph* npptr = (struct paragraph*)realloc(pptr, sizeof(struct paragraph) * d.paragraph_count);
      if (!npptr) { // if pptr is NULL
          exit(EXIT_FAILURE);
      }
      pptr = npptr;
      int sentence_count = 0;
       
      struct sentence* sptr = NULL;
      char* s1 = strtok_r(s0, deli1, &s1_save_ptr);
      while (s1 != NULL) {
          sentence_count++;
          struct sentence* nsptr = (struct sentence*)realloc(sptr, sizeof(struct sentence) * sentence_count);
           
          if (!nsptr) {
              exit(EXIT_FAILURE);
          }
          sptr = nsptr;
          int word_count = 0;
          char* s2 = strtok_r(s1, deli2, &s2_save_ptr);
          struct word* wptr = NULL;
          while (s2 != NULL) {
             word_count++;
             struct word* nwptr = (struct word*)realloc(wptr, sizeof(struct word) * word_count);
             
             size_t s2_len = strlen(s2);
             char* word_data = (char*)calloc(s2_len + 1, sizeof(char));
                          
             if (!nwptr || !word_data) {
                 exit(EXIT_FAILURE);
             }
             wptr = nwptr;
            strncpy(word_data, s2, s2_len);
            (wptr + (word_count -1))->data = word_data;
            s2 = strtok_r(NULL, deli2, &s2_save_ptr);
          }
          struct sentence *_sptr =(sptr + (sentence_count -1));
          _sptr ->word_count = word_count;
          _sptr ->data = wptr;
          s1 = strtok_r(NULL, deli1, &s1_save_ptr);
      }
      struct paragraph *_pptr = (pptr + (d.paragraph_count - 1));
      _pptr ->sentence_count = sentence_count;
      _pptr ->data = sptr;
      s0 = strtok_r(NULL, deli, &s0_save_ptr);
  }
  d.data = pptr;
 
  return d;
}

struct word kth_word_in_mth_sentence_of_nth_paragraph(struct document Doc, int k, int m, int n) {
    // return Doc.data[n-1].data[m-1].data[k-1];
    return *((((Doc.data)+(n-1))->data+ m-1)->data + k-1);
}

struct sentence kth_sentence_in_mth_paragraph(struct document Doc, int k, int m) { 
    //return Doc.data[m-1].data[k-1];
    return *(((Doc.data)+(m-1))->data+ k-1);
}

struct paragraph kth_paragraph(struct document Doc, int k) {
     return *((Doc.data)+(k-1));
    // return Doc.data[k-1];
}

/*
char text* = "Learning C is fun.\nLearning pointers is more fun.It is good to have pointers."

*/



