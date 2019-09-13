#include <stdio.h>
int cycle[3005];
int pos[3005];
int main()
{
    int i,j,m,n;
    int tempM, tempN;
    int quotient, remainder;
    int maxLen = 50;
    int cycleLen;
    while(scanf("%d %d", &m, &n) == 2){
        tempM = m;
        tempN = n;

        for(i = 0 ; i < n;++i)
        {
            pos[i] = -1;
        }

        i = 0;
        remainder = m % n;
        quotient = m / n;
        while(remainder && pos[remainder] == -1) {

            pos[remainder] = i;
            cycle[i++] = remainder * 10 / n;
            remainder = (remainder * 10) % n;
        }


        printf("%d/%d = %d.", m, n, quotient);

        if(remainder) {
            for(j = 0 ; j < pos[remainder];++j)
            {
                printf("%d", cycle[j]);
            }

            printf("(");
            for(;j < i && j < maxLen;++j)
            {
                printf("%d", cycle[j]);
            }

            if(j == i)
            {
                printf(")\n");
            }
            else
            {
                printf("...)\n");
            }
        }
        else{
            for(j = 0 ; j < i;++j){
                printf("%d", cycle[j]);
            }
            printf("(0)\n");
        }

        cycleLen = remainder ? i - pos[remainder] : 1;
        printf("   %d = number of digits in repeating cycle\n\n", cycleLen);



    }
    return 0;
}






























