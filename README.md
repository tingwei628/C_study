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
 - [Coursera_NTU_C_HW](https://github.com/tingwei628/C_study/tree/master/Coursera_NTU_C_HW)
 - [Examples](https://github.com/tingwei628/C_study/tree/master/examples)


## [Write a Makefile](https://github.com/tingwei628/Coursera_NTU_C_HW/tree/master/examples/write_a_makefile)

## [Docs](https://github.com/tingwei628/Coursera_NTU_C_HW/wiki/)
It includes questions, terms, and usage of vim...

## Test

### unit test

- [Criterion@Snaipe](https://github.com/Snaipe/Criterion)

### glibc source code online

[glibc](https://code.woboq.org/userspace/glibc/)

## Reference
- [「你所不知道的 C 語言」系列講座 @jserv](http://hackfoldr.org/dykc/)
- [Project-Based-Tutorials-in-C@rby90](https://github.com/rby90/Project-Based-Tutorials-in-C)
- [Makefile in python](http://krzysztofzuraw.com/blog/2016/makefiles-in-python-projects.html)
- [Makefile howto](http://wiki.ubuntu.org.cn/%E8%B7%9F%E6%88%91%E4%B8%80%E8%B5%B7%E5%86%99Makefile)


### 參考影片
  - [C語言教學 by劉邦鋒](https://www.youtube.com/playlist?list=PLOvZ8aEg7xDkpKHk3hAwQxLAlpZ1Q3wKH)
  - [C語言從菜鳥到高手 by尹成](http://www.bilibili.com/video/av5120945/index_1.html)
