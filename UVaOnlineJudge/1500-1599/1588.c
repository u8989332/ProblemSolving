#include <stdio.h>
#include <string.h>
#define MAX_LEN 9999
int main()
{
    char s1[105];
    char s2[105];
    int i,j,k;
    int isOk;
    while(scanf("%s %s", s1, s2) != EOF)
    {
        int minLen = MAX_LEN;
        int len1 = strlen(s1);
        int len2 = strlen(s2);

        /* s1 buttom, s2 top */
        for(i = 0 ; i < len1;++i)
        {
            isOk = 1;
            for(j = i, k = 0 ; j < len1 && k < len2;++k,++j)
            {
                if(!(s1[j] == '2' && s2[k] == '1' || s1[j] == '1' && s2[k] == '2' || s1[j] == '1' && s2[k] == '1'))
                {
                    isOk = 0;
                    break;
                }
            }
            if(isOk)
            {
                j--;
                k--;
                int curLen = (i + len2) < len1 ? len1 : i + len2;
                if(curLen < minLen)
                {
                    minLen = curLen;
                }
            }
        }

        /* s2 buttom, s1 top */
        for(i = 0; i < len2;++i)
        {
            isOk = 1;
            for(j = i, k = 0 ; j < len2 && k < len1;++k,++j)
            {
                if(!(s1[k] == '2' && s2[j] == '1' || s1[k] == '1' && s2[j] == '2' || s1[k] == '1' && s2[j] == '1'))
                {
                    isOk = 0;
                    break;
                }
            }
            if(isOk)
            {
                j--;
                k--;
                int curLen = (i + len1) < len2 ? len2 : i + len1;
                if(curLen < minLen)
                {
                    minLen = curLen;
                }
            }
        }

        if(minLen == MAX_LEN)
        {
            printf("%d\n", len1 + len2);
        }
        else
        {
            printf("%d\n", minLen);
        }
    }
    return 0;
}
