#include <stdio.h>
#include <string.h>
#define MAX_ERROR 7
char s1[10005];
char s2[10005];

int main()
{
    int round;
    int win, lose;
    int i,j;
    int len1, len2;
    int errorCount;
    int okCount;
    while(scanf("%d", &round) != EOF)
    {
        if(round == -1)
            break;

        scanf("%s %s", s1, s2);
        win = 0;
        lose = 0;
        errorCount = 0;
        okCount = 0;
        len1 = strlen(s1);
        len2 = strlen(s2);
        for(i = 0 ; i < len2;++i)
        {
            char curC = s2[i];
            int hasMatch = 0;
            for(j = 0 ; j < len1;++j)
            {
                if(curC == s1[j])
                {
                    okCount++;
                    s1[j] = '-';
                    hasMatch = 1;
                }
            }
            if(okCount >= len1)
            {
                win = 1;
                break;
            }
            else if(!hasMatch)
            {
                errorCount++;
                if(errorCount >= MAX_ERROR)
                {
                    lose = 1;
                    break;
                }
            }
        }
        printf("Round %d\n", round);
        if(lose)
        {
            printf("You lose.\n");
        }
        else if(win)
        {
            printf("You win.\n");
        }
        else
        {
            printf("You chickened out.\n");
        }

    }
    return 0;
}
