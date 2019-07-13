#include <stdio.h>
#include <string.h>

int table[100005];
int main()
{
    int i ;
    int tmp;
    int sum;
    int N;
    int target;
    memset(table,0,sizeof(table));
    for(i = 100000;i >= 1 ;--i)
    {
        sum = i;
        tmp = i;
        while(tmp > 0)
        {
            sum += tmp % 10;
            tmp /= 10;
        }
        table[sum] = i;
    }
    scanf("%d", &N);
    for(i = 0 ; i < N;++i)
    {
        scanf("%d", &target);
        printf("%d\n", table[target]);
    }
    return 0;
}
