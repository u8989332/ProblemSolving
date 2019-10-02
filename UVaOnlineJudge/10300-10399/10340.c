#include <stdio.h>
#include <string.h>
int main()
{
    char s[100005];
    char t[100005];
    int i, j, sLen, tLen;
    while(scanf("%s %s", s, t) != EOF)
    {
        i = 0;
        j = 0;
        sLen = strlen(s);
        tLen = strlen(t);
        for(i = 0, j= 0; i < sLen && j < tLen;)
        {
            if(s[i] == t[j])
            {
                i++;
                j++;
            }
            else{
                j++;
            }
        }
        if(i == sLen)
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
    return 0;
}
