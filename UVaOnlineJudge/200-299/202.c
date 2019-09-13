#include <stdio.h>
char cycle[35000];
int pos[35000];
int main()
{
    int i,j,m,n;
    int tempM, tempN;
    int quotient, remainder, tempRemainder;
    int isDigit, cycleLen, noCycle = 0;
    while(scanf("%d %d", &m, &n) == 2){
        tempM = m;
        tempN = n;

        for(i = 0 ; i < n * 10;++i)
        {
            pos[i] = -1;
        }

        isDigit = 0;
        i = 0;
        noCycle = 0;
        quotient = m/n;
        remainder = m % n;
        if(remainder != 0){
            isDigit = 1;
        }
        else{
            noCycle = 1;
        }

        if(isDigit) {
            while(1){
                remainder *= 10;
                if(pos[remainder] != -1){
                    break;
                }
                if(remainder < n){
                    cycle[i] = '0';
                    pos[remainder] = i;
                }
                else{
                    cycle[i] = (remainder / n) + '0';
                    pos[remainder] = i;
                    tempRemainder = remainder % n;
                    if(tempRemainder == 0){
                        noCycle = 1;
                        break;
                    }
                    remainder = tempRemainder;
                }
                i++;
            }

            if(i >= 50){
                cycle[50] = '\0';
            }
            else{
                cycle[i+1] = '\0';
            }
        }

        if(noCycle){
            cycleLen = 1;
        }
        else{
            cycleLen = i - pos[remainder];
        }

        printf("%d/%d = %d", m, n, quotient);
        if(isDigit){
            printf(".");
            if(noCycle){
                printf("%s(0)\n", cycle);
            }
            else{
                for(j = 0;j < (i >= 50 ? 50 : i);++j)
                {
                    if(j == pos[remainder])
                    {
                        printf("(");
                    }
                    printf("%c", cycle[j]);
                }
                if(i >= 50){
                    printf("...)\n");
                }
                else{
                    printf(")\n");
                }
            }
        }
        else{
            printf(".(0)\n");
        }
        printf("   %d = number of digits in repeating cycle\n\n", cycleLen);

    }
    return 0;
}
