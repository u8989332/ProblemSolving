#include <stdio.h>
#include <math.h>

int table[2050];
int main()
{
    int n;
    double sum;
    int baseYear = 1960;
    int maxYear = 2160;
    int diff;
    int maxPow;
    int i,j;

    for(n = baseYear; n <= maxYear;n+=10)
    {
        maxPow = 4;
        diff = n - baseYear;
        while(diff / 10 > 0)
        {
            maxPow *= 2;
            diff -= 10;
        }

        i = 1;
        sum = 0;
        while(sum < maxPow)
        {
            double cur = log((double)++i) / log((double)2);
            sum += cur;
        }
        for(j = n;j <= n + 9;++j)
        {
            table[j] = i-1;
        }
    }

    while(scanf("%d", &n) && n)
    {
        printf("%d\n", table[n]);
    }
    return 0;
}
