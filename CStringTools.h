// CStringTools.h�ļ�


#ifndef CSTRINGTOOLS_H_INCLUDED
#define CSTRINGTOOLS_H_INCLUDED

#include <string.h>
#include <malloc.h>

//��strָ���ַ�keysǰ�����һ��content
void fillWithKeys(char *str, char* keys, char content);

//���ַ���str���շָ���keys�ָ��strList������50���ַ��� ����20��
//����ʵ�ʷֳɵ��ַ���������
int split(char strList[][20], char *str, char *keys);

#endif // CSTRINGTOOLS_H_INCLUDED
