#include <stdio.h>

char table[200] = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
int main()
{
    char c;
    int i;
    int findFlag = 0;
    while((c = getchar()) != EOF)
    {
        for(i = 1;table[i] && table[i] != c;++i);
        if(table[i]) printf("%c", table[i-1]);
        else printf("%c", c);
    }

    return 0;
}
