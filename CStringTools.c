// CStringTools.c


#include "CStringTools.h"

void fillWithKeys(char *str, char* keys, char content)
{
    char *tmp = (char *)malloc(sizeof(char) * strlen(str));
    strcpy(tmp, str);

    int index = 0;
    for (int i = 0; i < strlen(tmp); ++i)
    {
        int flag = 0;
        for (int j = 0; j < strlen(keys); ++j)
        {
            if (keys[j] == tmp[i])
            {
                flag = 1;
                break;
            }
        }

        if (flag)
            str[index++] = content;
        str[index++] = tmp[i];
        if (flag)
            str[index++] = content;
    }
    str[index] = '\0';

    free(tmp);
}

int split(char strList[][20], char *str, char *keys)
{
    int cnt = 0;

    str[strlen(str)] = keys[0];
    str[strlen(str)] = '\0';

    int start = -1;
    for (int i = 0; i < strlen(str); ++i)
    {
        int flag = 0;
        for (int j = 0; j < strlen(keys); ++j)
        {
            if (keys[j] == str[i])
            {
                flag = 1;
                break;
            }
        }

        if(flag)
        {
            if (i - start > 1)
            {
                //ÇÐ¸î[start+1,i-1]
                for (int j = start + 1; j <= i - 1; ++j)
                {
                    strList[cnt][j-start-1] = str[j];
                }
                strList[cnt][i - start - 1] = '\0';
                ++cnt;
            }
            start = i;
        }
    }

    return cnt;
}
