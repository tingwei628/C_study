# C_study

### Introduction
  - JUST PRACTICE

### How to compile C ?

```c
$gcc -o [exe] [source.file]

// example
$gcc -o mycode source.c // it will compile source.c and execute mycode

// execute a exe
$./mycode

```
>Debug with GDB

```c
$gcc -g -o [exe] [source.file]
$sudo gdb [exe]    // run as root
```

>Compiled with C11 (C standard released in 2011)

```c
$gcc -std=c11 -o mycode source.c ./mycode
```

> Usage of math.h

```
$gcc -o mycode source.c -lm
```

## Content

## [Write a Makefile](https://github.com/tingwei628/Coursera_NTU_C_HW/tree/master/examples/write_a_makefile)

## [Docs](https://github.com/tingwei628/Coursera_NTU_C_HW/wiki/)
It includes questions, terms, and usage of vim...

## Reference
- [「你所不知道的 C 語言」系列講座 @jserv](http://hackfoldr.org/dykc/)
- [How to write a Makefile](http://mropengate.blogspot.tw/2015/06/makefile-makefile.html)
- [Makefile in python](http://krzysztofzuraw.com/blog/2016/makefiles-in-python-projects.html)
- [GCC howto](http://wiki.ubuntu.org.cn/Gcchowto)
- [C booklist](http://stackoverflow.com/questions/562303/the-definitive-c-book-guide-and-list)


### 參考影片
  - [C語言教學 by劉邦鋒](https://www.youtube.com/playlist?list=PLOvZ8aEg7xDkpKHk3hAwQxLAlpZ1Q3wKH)
  - [C語言從菜鳥到高手 by尹成](http://www.bilibili.com/video/av5120945/index_1.html)
