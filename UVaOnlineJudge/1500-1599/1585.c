#include <stdio.h>

int main()
{
    int n;
    int score;
    int curScore;
    int len;
    int i;
    char s[100];
    scanf("%d", &n);
    while(n--)
    {
        scanf("%s", s);
        score = 0;
        curScore = 0;
        len = strlen(s);
        for(i = 0 ; i < len;++i)
        {
            if(s[i] == 'O')
                score += ++curScore;
            else
                curScore = 0;
        }
        printf("%d\n", score);
    }
    return 0;
}
