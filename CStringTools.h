// CStringTools.h文件


#ifndef CSTRINGTOOLS_H_INCLUDED
#define CSTRINGTOOLS_H_INCLUDED

#include <string.h>
#include <malloc.h>

//在str指定字符keys前后填充一个content
void fillWithKeys(char *str, char* keys, char content);

//将字符串str按照分隔符keys分割成strList（上限50个字符串 长度20）
//返回实际分成的字符串的数量
int split(char strList[][20], char *str, char *keys);

#endif // CSTRINGTOOLS_H_INCLUDED
