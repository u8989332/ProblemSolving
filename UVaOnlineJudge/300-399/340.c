#include <stdio.h>
#define min(a,b) (a < b ? (a):(b))
int main()
{
    int len;
    int i, j;
    int ans[1005];
    int target[1005];
    int sumAns[10];
    int sumTarget[10];
    int A, B;
    int game = 1;
    while(scanf("%d", &len) && len)
    {
        printf("Game %d:\n", game++);

        for(i = 0 ; i < len; ++i)
        {
            scanf("%d", &ans[i]);
        }

        while(1)
        {
            A = 0,  B = 0;
            for(i = 0 ; i < len; ++i)
            {
                scanf("%d", &target[i]);
            }
            if(!target[0])
                break;

            for(i = 0; i < len; ++i)
            {
                if(ans[i] == target[i])
                    ++A;
            }

            for(i = 1 ; i <= 9; ++i)
            {
                sumAns[i] = 0;
                sumTarget[i] = 0;
            }

            for(i = 0 ; i < len; ++i)
            {
                sumAns[ans[i]]++;
                sumTarget[target[i]]++;
            }

            for(i = 1 ; i <= 9; ++i)
            {
                B += min(sumAns[i], sumTarget[i]);
            }
            printf("    (%d,%d)\n", A, B-A);
        }

    }
    return 0;
}
