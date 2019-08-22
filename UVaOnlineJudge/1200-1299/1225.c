#include <stdio.h>

int digits[10005][10];
int main()
{
    int i,j;
    int curN;
    int curDigit;
    int N, cases;
    for(i = 0 ; i <= 9 ;++i)
    {
        digits[0][i] = 0;
    }

    for(i = 1 ; i < 10000;++i)
    {
        for(j = 0; j <= 9; ++j)
        {
            digits[i][j] = digits[i-1][j];
        }

        curN = i;
        while(curN > 0)
        {
            curDigit = curN % 10;
            digits[i][curDigit]++;
            curN /= 10;
        }
    }

    scanf("%d", &cases);
    while(cases--)
    {
        scanf("%d", &N);
        for(i = 0 ; i <= 9;++i)
        {
            if(i > 0)
                printf(" ");
            printf("%d", digits[N][i]);
        }
        printf("\n");
    }

    return 0;
}
