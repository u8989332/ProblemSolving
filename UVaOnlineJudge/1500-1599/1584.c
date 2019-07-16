#include <stdio.h>
#include <string.h>

int main()
{
    int n,i ,j;
    int minIndex = 0;
    int len;
    scanf("%d", &n);
    char s[105];
    while(n--)
    {
        scanf("%s", s);
        minIndex = 0;
        len = strlen(s);
        for(i = 1; i < len;++i)
        {
            for(j = 0;j < len;++j)
            {
                if(s[(i+j)%len] < s[(minIndex+j)%len])
                {
                    minIndex = i;
                    break;
                }
                else if(s[(i+j)%len] == s[(minIndex+j)%len])
                {
                    continue;
                }
                else
                {
                    break;
                }
            }
        }
        for(i = 0;i < len;++i)
        {
            printf("%c", s[(minIndex+i)%len]);
        }
        printf("\n");
    }
    return 0;
}
