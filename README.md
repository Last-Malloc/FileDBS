﻿以最简单的方式实现几个C语言课程设计的常见题目，适合大一或者刚学习C语言的同学学习参考。使用Code::Blocks编译器创建的纯C项目，将其中的源码粘贴进其他编译器或C++项目也可直接运行。因为部分同学没有学习过数据结构，所以尽量使用传统的数组进行存储，规避没有学习过的知识点，但鼓励大家自己改进。为了使得程序更加简单方便阅读，基本上没有进行对用户输入的容错，可以自己添加。

Code::Blocks安装和使用 https://blog.csdn.net/qq_42283621/article/details/124055391?spm=1001.2014.3001.5501

项目地址：https://github.com/Last-Malloc/FileDBS

[TOC]

# 需求分析

**以文件系统实现数据库的重要操作，包括：**
	**创建、删除、选择数据库**
	**创建、删除、显示表**
	**插入、删除、查询表记录**

命令以分号结尾；一个数据库可包括不超过 10 个数据表；一个数据表可包括不超过 10 个字段和不超过 1000 条记录 

## 创建、删除、选择数据库

1. create database xxx; 

2. drop database xxx; 

3. use xxx;
   选择数据库后，该数据库为默认数据库，后续操作均在该数据库上进行。

## 创建、删除、显示表

1.  create table xxx (col_type col_name1, col_type col_name2, … ); 
   col_type 为字段类型，至少支持整数（int），浮点数（float），字符串（string）
2. drop table xxx;
3. info table xxx； 显示表信息

## 插入、删除、查询表记录

1. insert into xxx set col_name1=col_value1,col_name2=col_value2,…;

2. delete from xxx [where condition];
3. select col_name1,col_name2, … from xxx [where condition] [order by col_name] [asc/desc] ; 

## 新增

为了稍微使得系统可用性更高，我们添加一下几个数据库指令：
	list database;	 显示存在的数据库
	list table;			显示存在的表

系统指令：
	exit	  退出系统

# 总体框架

**以文件夹表示数据库（数据库名即为文件夹名），以txt文件表示表（表名即为txt文件名），在txt文件的第1行存储各种表相关的信息，从第2行开始存储数据库记录**

文件和文件夹的操作见：https://blog.csdn.net/qq_42283621/article/details/124370828，这里直接使用成品\#include "FileDirTools.h"

对于输入的指令，首先需要对字符串进行分割，产生一个一个的单词，分割字符串的方法在下一节具体说明。然后根据指令中的第一个单词（成为保留字）进行不同的操作。保留字包括：

```sql
保留字
    create drop use info insert delete select list exit
```

程序的总体框架为：

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "CStringTools.h"

//当前数据库名
char curDB[20];

int main()
{
    //输入的指令
    char cmd[1000];
    //对cmd进行字符串分割
    char cmdList[50][20];

    strcpy(curDB, "NULL");

    while(1)
    {
        //输入指令并分割字符串
        printf("%s>>>", curDB);
        gets(cmd);

        fillWithKeys(cmd, "=><*", ' ');
        int cntList = split(cmdList, cmd, " ;,()");
        if (!strcmp(cmdList[0], "exit"))
        {
            break;
        }
        else if (!strcmp(cmdList[0], "create"))
        {
            //create database xxx;
            //create table xxx (col_type col_name1, col_type col_name2, … );
        }
        else if (!strcmp(cmdList[0], "drop"))
        {
            //drop database xxx;
            //drop table xxx;
        }
        else if (!strcmp(cmdList[0], "use"))
        {
            //use xxx;
        }
        else if (!strcmp(cmdList[0], "info"))
        {
            //info table xxx;
        }
        else if (!strcmp(cmdList[0], "insert"))
        {
            //insert into xxx set col_name1=col_value1,col_name2=col_value2,…;

        }
        else if (!strcmp(cmdList[0], "delete"))
        {
            //delete from xxx [where condition];

        }
        else if (!strcmp(cmdList[0], "select"))
        {
            //select col_name1,col_name2, … from xxx [where condition] [order by col_name] [asc/desc] ;

        }
        else if (!strcmp(cmdList[0], "list"))
        {
            //list database;
            //list table;
        }
        else
        {
            printf("Command not found.\n");
        }
    }
    printf("Exit database system...\n");

    return 0;
}
```

![image-20220423190613423](https://img-blog.csdnimg.cn/img_convert/fc0521f83f5ff9d7ad8906e295d1b600.png)

# 分割字符串

首先，指令中的 “空格 ; , ( )”5种字符作为分割的标志，并且将其舍弃。
例如：

```sql
create table testTable1(string col1, float col2, int col3);

分割完成后为
create 
table 
testTable1
string 
col1
float 
col2
int 
col3
```

然后，指令中的“= > < *”4种字符也要作为分割的标志，但是并不能将其舍弃。例如：

```sql
delete from testTable1 where col2>100;

分割完成后为
delete 
from 
testTable1 
where 
col2 
> 
100
```

为满足上面两种要求，我们可以在“= > < *”4种字符前后添加空格，再用 “空格 ; , ( )”5种字符作为分割符来分割字符串。分割函数的设计和实现见https://blog.csdn.net/qq_42283621/article/details/124364562

即：

```c
char cmd[1000];
char cmdList[50][20];
fillWithKeys(cmd, "=><*", ' ');
split(cmdList, cmd, " ;,()");
```

# 函数实现

略，详细见代码

# 结果展示

# 附录

```sql
-- 测试数据
create table testDB1;
drop table testDB1;
use testDB1;

create table testTable1(string col1, float col2, int col3);
drop table testTable1;
info table testTable1;

insert into testTable1 set col1 = 'abc', col2 = 123.6, col3 = 100;
delete from testTable1 where col2 > 100;
delete from testTable1 where col2 < 100;
delete from testTable1 where col1 = 'abc';
delete from testTable1;
select * from testTable1;
select col11, col2 from testTable1;
select col11, col2 from testTable1 where col2 > 100;
select col11, col2 from testTable1 where col2 > 100 order by col2 desc;
```
