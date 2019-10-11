#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char maps[8][100];
char originS[10000];
void setKey(int n)
{
    int i,j;
    int maxJ;
    int counts = 0;
    char s[10];
    for(i = 1 ; i <= 7;++i)
    {
        maxJ = (1 << i)-1;
        for(j = 0;j < maxJ;++j)
        {
            maps[i-1][j] = originS[counts];
            counts++;
            if(counts == n)
            {
                break;
            }
        }
        if(counts == n)
        {
            break;
        }
    }
}

int getKey(int len)
{
    char s[10] = {'\0'};
    int i;
    int isAllOne = 1;
    for(i = 0 ; i < len;++i)
    {
        char c = getchar();
        if(c == '\n')
        {
            i--;
            continue;
        }
        s[i] = c;
        if(c == '0')
        {
            isAllOne = 0;
        }
    }
    s[i] = '\0';

    if(isAllOne)
    {
        return -1;
    }

    int sum = getDecimal(s);

    return maps[len-1][sum];
}

int getDecimal(char *s)
{
    int i = strlen(s) - 1;
    int sum = 0, base = 1;
    for(;i >= 0;--i)
    {
        if(s[i] == '1')
        {
            sum += base;
        }
        base *= 2;
    }
    return sum;
}

int getLen()
{
    char s[10] = {'\0'};
    int j;
    for(j = 0 ; j < 3;++j)
    {
        char c = getchar();
        if(c == '\n')
        {
            j--;
            continue;
        }
        s[j] = c;
    }
    int sum = getDecimal(s);

    return sum;
}

int main()
{
    char c;
    int counts = 0;
    while((c = getchar()) != EOF)
    {
        originS[counts++] = c;
        while(c = getchar())
        {
            if(c == '\n')
            {
                originS[counts] = '\0';
                break;
            }
            originS[counts++] = c;
        }
        setKey(counts);

        do
        {
            int len = getLen();
            if(len == 0)
            {
                getchar();
                break;
            }
            do
            {
                int curC = getKey(len);
                if(curC == -1)
                {
                    break;
                }
                printf("%c", (char)curC);
            }while(1);
        }while(1);

        printf("\n");
        counts = 0;
    }
    return 0;
}
