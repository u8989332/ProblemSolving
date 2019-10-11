#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char maps[10000][100];
char originS[10000];
int bases[8] = {1, 2, 5, 12, 27, 58, 121, 248};
void setKey(char c, int n)
{
    int i;
    char s[10];
    for(i = 0 ; i < 7;++i)
    {
        if(n >= bases[i] && n < bases[i+1])
        {
            int base = n - bases[i];
            int j = i;
            s[j+1] = '\0';
            while(base > 0)
            {
                s[j--] = (base % 2) + '0';
                base /= 2;
            }
            while(j >= 0)
            {
                s[j--] = '0';
            }
            strcpy(maps[n-1], s);
            originS[n-1] = c;
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

    i = bases[len-1] - 1;
    for(;;++i)
    {
        if(strcmp(maps[i], s) == 0)
        {
            return originS[i];
        }
    }

}

int getLen()
{
    char s[10];
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
    int i = 2;
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

int main()
{
    char c;
    int counts = 1;
    while((c = getchar()) != EOF)
    {
        setKey(c, counts++);
        while(c = getchar())
        {
            if(c == '\n')
            {
                break;
            }
            setKey(c, counts++);
        }

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
                printf("%c", curC);
            }while(1);
        }while(1);

        printf("\n");
        counts = 1;
    }
    return 0;
}
