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