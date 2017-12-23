const char *hello(const char *name);

//ch12
void printShortLong();

//ch13
void printbit();

//ch14
void recurrsion();

//ch15
// date, mystruct defined in header file
struct date
{
  int month;
  int day;
};
typedef struct date Date;
struct mystruct
{
  char name[21];
  int number;
  Date date;               // struct has another struct
};                         // DO NOT FORGET the semicolon for struct
typedef struct mystruct M; // define struct mystruct as M
void structure();

//ch16
void file();
void file1();
void file2();
void file3();
void file4();

//ch17
struct node
{
  int num;
  struct node *next; // struct pointer for next node
};
typedef struct node Node;

void linkedlist();
void sortlinkedlist();

struct treenode
{
  int num;
  struct treenode *right;
  struct treenode *left;
};
typedef struct treenode TreeNode;
void binarysearchtree();