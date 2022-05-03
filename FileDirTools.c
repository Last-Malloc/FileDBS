//FileDirTools.c


#include "FileDirTools.h"

int createDir(char* path)
{
    if (0 != access(path, 0))
    {
        return mkdir(path);
    }
    else
    {
        return 1;
    }
}

int dropDir(char* path)
{
    if (0 == access(path, 0))
    {
        return rmdir(path);
    }
    else
    {
        return 1;
    }
}

void cascadeDropDir(char* path)
{
    char *tPath = (char*)malloc(sizeof(char) * (strlen(path) + 3));
    strcpy(tPath, path);
    tPath[strlen(path)] = '\\';
    tPath[strlen(path) + 1] = '*';
    tPath[strlen(path) + 2] = '\0';

    //参考 https://baijiahao.baidu.com/s?id=1634104829954130656&wfr=spider&for=pc
    struct _finddata_t data;

    long handle = _findfirst(tPath , &data);//-1表示没有文件
    int ret = handle;
    while(ret >= 0)
    {
        if (data.attrib != _A_SUBDIR)
        {
            char t[1000];
            strcpy(t, path);
            strcat(t, "\\");
            strcat(t, data.name);

            remove(t);
        }

        ret = _findnext(handle, &data);
    }
    _findclose(handle);

    dropDir(path);

    free(tPath);

}

int listDir(char *path, char dirList[][20])
{
    char *tPath = (char*)malloc(sizeof(char) * (strlen(path) + 3));
    strcpy(tPath, path);
    tPath[strlen(path)] = '\\';
    tPath[strlen(path) + 1] = '*';
    tPath[strlen(path) + 2] = '\0';

    //参考 https://baijiahao.baidu.com/s?id=1634104829954130656&wfr=spider&for=pc
    struct _finddata_t data;
    int cnt = 0;

    long handle = _findfirst(tPath , &data);//-1表示没有文件
    int ret = handle;
    while(ret >= 0)
    {
        if (data.attrib == _A_SUBDIR && data.name[0] != '.')
            strcpy(dirList[cnt++], data.name);

        ret = _findnext(handle, &data);
    }
    _findclose(handle);

    free(tPath);

    return cnt;
}

int createFile(char *path)
{
    return creat(path, 7)>=0?0:-1;
}

int dropFile(char *path)
{
    return remove(path)>=0?0:-1;
}

int listFile(char *path, char fileList[][20])
{
    char *tPath = (char*)malloc(sizeof(char) * (strlen(path) + 3));
    strcpy(tPath, path);
    tPath[strlen(path)] = '\\';
    tPath[strlen(path) + 1] = '*';
    tPath[strlen(path) + 2] = '\0';

    //参考 https://baijiahao.baidu.com/s?id=1634104829954130656&wfr=spider&for=pc
    struct _finddata_t data;
    int cnt = 0;

    long handle = _findfirst(tPath , &data);//-1表示没有文件
    int ret = handle;
    while(ret >= 0)
    {
        if (data.attrib != _A_SUBDIR)
            strcpy(fileList[cnt++], data.name);

        ret = _findnext(handle, &data);
    }
    _findclose(handle);

    free(tPath);

    return cnt;
}
