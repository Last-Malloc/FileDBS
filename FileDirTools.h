//FileDirTools.h


#ifndef FILEDIRTOOLS_H_INCLUDED
#define FILEDIRTOOLS_H_INCLUDED

#include <direct.h>
#include <io.h>
#include <malloc.h>
#include <string.h>

//在指定路径下创建文件夹
//返回值   0创建成功 1文件夹已存在 -1不存在且创建失败
int createDir(char* path);

//在指定路径下删除文件夹（里面有内容将失败返回-1）
//返回值   0删除成功 1文件夹不存在 -1存在且删除失败
int dropDir(char* path);

//级联删除指定路径下的文件夹以及文件夹下的普通文件
void cascadeDropDir(char* path);

//返回指定路径下的所有文件夹名（上限50个目录 长度20）
//path路径   dirList文件夹名列表  返回值为文件夹名列表长度
int listDir(char *path, char dirList[][20]);

//创建文件 成功0失败-1
int createFile(char *path);

//删除文挨 成功0失败-1
int dropFile(char *path);

//返回指定路径下的所有文件名（上限50个文件 长度20）
//path路径   fileList文件名列表  返回值为文件名列表长度
int listFile(char *path, char fileList[][20]);

#endif // FILEDIRTOOLS_H_INCLUDED
