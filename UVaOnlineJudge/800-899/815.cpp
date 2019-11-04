#include <iostream>
#include <algorithm>
#include <cstdio>
#define EPS 1e-8
using namespace std;

int main()
{
    double h[999];
    int m,n, all_n;
    double V;
    double curV;
    double curH;
    double base = 100;
    int i;
    int cases = 1;
    while(scanf("%d %d", &m, &n) != EOF && m && n)
    {
        all_n = m * n;
        for(int i = 0 ; i < all_n;++i)
        {
            scanf("%lf", &h[i]);
        }
        scanf("%lf", &V);
        sort(h, h + all_n);
        curV = V + h[0] * base;
        curH = curV / base + EPS;
        for(i = 1 ; i < all_n;++i)
        {
            if(curH <= h[i])
            {
                break;
            }

            curV = curV + h[i] * base;
            curH = curV / ((i + 1) * base) + EPS;

        }

        printf("Region %d\n", cases++);
        printf("Water level is %.2f meters.\n", curH);
        printf("%.2f percent of the region is under water.\n", (double)(i * 100)/ all_n + EPS);
        printf("\n");

    }
    return 0;
}
