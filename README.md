#Coursera_NTU_C_HW

###Introduction
  - JUST PRACTICE

###How to compile C ?

```c
$gcc -o [obj.file] [source.file] && ./[source.file]

// example
$gcc -o mycode source.c ./mycode // it will compile source.c and execute mycode

```
###Makefile

- Make a Makefile

Step1:

```c
$touch Makefile
```
Step2

```c
$vim Makefile
```

Inside Makefile

```c
CC = gcc
all: t.c
	gcc -o app t.c && ./app
clean:
	rm -f app

```

- Execute Makefile

```c
$make
```

- Clean app (delete app.exe)

```c
$make clean
```

##Reference
- [How to write a Makefile](http://mropengate.blogspot.tw/2015/06/makefile-makefile.html)
- [Makefile in python](http://krzysztofzuraw.com/blog/2016/makefiles-in-python-projects.html)

###題目來源:
  - Coursera_計算機程式設計_by 劉邦鋒 Pangfeng Liu
  - 由片語學習C語言

###參考影片
  - [C語言教學 by劉邦鋒](https://www.youtube.com/playlist?list=PLOvZ8aEg7xDkpKHk3hAwQxLAlpZ1Q3wKH)
  - [C語言從菜鳥到高手 by尹成](http://www.bilibili.com/video/av5120945/index_1.html)
