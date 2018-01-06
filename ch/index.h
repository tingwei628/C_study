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

#define StackSize 100 //declare stack size is 100

//ch18
typedef char Data; //for only defined element data type
typedef struct stack
{
  int ptr;                  //index of element
  Data elements[StackSize]; //for storing element value
} Stack;

void conditioncompile();
void stack();
void init_stack(Stack *p);
void push_stack(Stack *p, Data c);
Data pop_stack(Stack *p);
int isfull_stack(Stack *p);
int isempty_stack(Stack *p);