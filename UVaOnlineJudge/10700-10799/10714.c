#include <stdio.h>
#define max(x,y) (x > y ? x : y)
#define min(x,y) (x < y ? x : y)
#define diff(x,y) (x > y ? x-y : y-x)
int main()
{
    int cases, totalLen, minTime, maxTime, n, curTime, curMinTime, curMaxTime;
    scanf("%d", &cases);
    while(cases--)
    {
        minTime = 0;
        maxTime = 0;
        scanf("%d", &totalLen);
        scanf("%d", &n);
        while(n--)
        {
            scanf("%d", &curTime);

            curMinTime = min(curTime, diff(totalLen, curTime));
            minTime = max(minTime, curMinTime);

            curMaxTime = max(curTime, diff(totalLen, curTime));
            maxTime = max(maxTime, curMaxTime);
        }
        printf("%d %d\n", minTime, maxTime);
    }
    return 0;
}
