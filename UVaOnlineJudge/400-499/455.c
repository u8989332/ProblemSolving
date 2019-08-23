#include <stdio.h>
#include <string.h>

int main()
{
    char s[85];
    int n;
    int index;
    int len;
    int i,j,k;
    int curMin;
    int minLen;
    scanf("%d", &n);
    for(index = 0 ; index < n; ++index)
    {
        if(index > 0)
        {
            printf("\n");
        }

        scanf("%s", s);
        len = strlen(s);
        curMin = len;
        minLen = len / 2;
        for(i = 1;i <= minLen;++i)
        {
            if(len % i != 0)
                continue;

            for(j = 0, k = 0; j < len;)
            {
                if(s[j] == s[k])
                {
                    j++;
                    k++;
                }
                else
                {
                    break;
                }
                if(k == i)
                    k = 0;

            }
            if(j == len)
            {
                curMin = i;
                break;
            }
        }
        printf("%d\n", curMin);
    }
    return 0;
}
