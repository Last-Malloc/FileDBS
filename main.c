#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "CStringTools.h"
#include "FileDirTools.h"

//当前数据库
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
            if (!strcmp(cmdList[1], "database"))
            {
                char tmpBuffer[1000];
                strcpy(tmpBuffer, "Database\\");
                strcat(tmpBuffer, cmdList[2]);
                int f = createDir(tmpBuffer);
                if (f == 0)
                    printf("Database %s is created successfully.\n", cmdList[2]);
                else if (f == 1)
                    printf("Database %s already exists.\n", cmdList[2]);
                else
                    printf("Database %s fails to be created.\n", cmdList[2]);
            }
            //create table xxx (col_type col_name1, col_type col_name2, … );
            else if (!strcmp(cmdList[1], "table"))
            {

            }
            else
            {
                printf("Command not found.\n");
            }
        }
        else if (!strcmp(cmdList[0], "drop"))
        {
            //drop database xxx;
            if (!strcmp(cmdList[1], "database"))
            {
                char tmpBuffer[1000];
                strcpy(tmpBuffer, "Database\\");
                strcat(tmpBuffer, cmdList[2]);
                int f = dropDir(tmpBuffer);
                if (f == 0)
                {
                    printf("Database %s is dropped successfully.\n", cmdList[2]);
                    if (!strcmp(curDB, cmdList[2]))
                    {
                        strcpy(curDB, "");
                    }
                }
                else if (f == 1)
                    printf("Database %s does not exist.\n", cmdList[2]);
                else
                    printf("Database %s contains tables and fails to be dropped.\n", cmdList[2]);
            }
            //drop table xxx;
            else if (!strcmp(cmdList[1], "table"))
            {

            }
            else
            {
                printf("Command not found.\n");
            }
        }
        else if (!strcmp(cmdList[0], "use"))
        {
            //use xxx;

            char tmpBuffer[50][20];
            int tCnt = listDir("Database", tmpBuffer);
            int flag = 0;
            for (int i = 0; i < tCnt; ++i)
            {
                if (!strcmp(tmpBuffer[i], cmdList[1]))
                {
                    flag = 1;
                    break;
                }
            }
            if (flag)
            {
                //printf("%d   %s", i + 1, tmpBuffer[i]);
            }
            else
                printf("Database %s not found", tmpBuffer);

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
            if (!strcmp(cmdList[1], "database"))
            {
                char tmpBuffer[50][20];
                int tCnt = listDir("Database", tmpBuffer);
                for (int i = 0; i < tCnt; ++i)
                    printf("%d   %s\n", i + 1, tmpBuffer[i]);
            }
            //list table;
            else if (!strcmp(cmdList[1], "table"))
            {

            }
            else
            {
                printf("Command not found.\n");
            }
        }
        else
        {
            printf("Command not found.\n");
        }
    }
    printf("Exit database system...\n");

    return 0;
}
