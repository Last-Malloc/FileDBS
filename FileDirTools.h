//FileDirTools.h


#ifndef FILEDIRTOOLS_H_INCLUDED
#define FILEDIRTOOLS_H_INCLUDED

#include <direct.h>
#include <io.h>
#include <malloc.h>
#include <string.h>

//��ָ��·���´����ļ���
//����ֵ   0�����ɹ� 1�ļ����Ѵ��� -1�������Ҵ���ʧ��
int createDir(char* path);

//��ָ��·����ɾ���ļ��У����������ݽ�ʧ�ܷ���-1��
//����ֵ   0ɾ���ɹ� 1�ļ��в����� -1������ɾ��ʧ��
int dropDir(char* path);

//����ɾ��ָ��·���µ��ļ����Լ��ļ����µ���ͨ�ļ�
void cascadeDropDir(char* path);

//����ָ��·���µ������ļ�����������50��Ŀ¼ ����20��
//path·��   dirList�ļ������б�  ����ֵΪ�ļ������б���
int listDir(char *path, char dirList[][20]);

//�����ļ� �ɹ�0ʧ��-1
int createFile(char *path);

//ɾ���İ� �ɹ�0ʧ��-1
int dropFile(char *path);

//����ָ��·���µ������ļ���������50���ļ� ����20��
//path·��   fileList�ļ����б�  ����ֵΪ�ļ����б���
int listFile(char *path, char fileList[][20]);

#endif // FILEDIRTOOLS_H_INCLUDED
