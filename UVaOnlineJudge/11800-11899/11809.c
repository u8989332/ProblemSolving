#include <stdio.h>
#include <string.h>
#include <math.h>

#define MIN_ERROR 1e-5

double A[10][31];
long long B[10][31];

void buildTable()
{
    int i,j;
    for(i = 0 ; i <= 9;++i)
    {
        for(j = 1; j <= 30;++j)
        {
            double m = 1 - pow(2, -i-1);
            long long e = pow(2, j) - 1;
            double t = log10(m) + log10(2) * e;
            B[i][j] = t / 1;
            A[i][j] = pow(10, t - B[i][j]);
        }
    }
}

int main()
{
    buildTable();
    char s[100];
    int i, j;
    int ok;
    double a;
    int b;
    while(scanf("%s", s) != EOF)
    {
        if(strcmp(s, "0e0") == 0)
        {
            break;
        }

        for(i = 0 ; i < strlen(s);++i)
        {
            if(s[i] == 'e')
            {
                s[i] = ' ';
                break;
            }
        }

        sscanf(s, "%lf %d", &a, &b);
        ok = 0;
        for(i = 0 ; i <= 9;++i)
        {
            for(j = 1; j <= 30;++j)
            {
                if(B[i][j] == b && fabs(a - A[i][j]) < MIN_ERROR)
                {
                    printf("%d %d\n", i, j);
                    ok = 1;
                    break;
                }
            }
            if(ok)
            {
                break;
            }
        }
    }
    return 0;
}
