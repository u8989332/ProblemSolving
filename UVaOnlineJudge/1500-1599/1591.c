#include <stdio.h>
int main()
{

    long long int N,SP, SQ;
    long long int maxI;
    long long int maxB;
    long long int maxPofs;
    long long int i, j;
    long long int ansK, ansA, ansB;
    long long int tempK, minK;
    while(scanf("%lld %lld %lld", &N, &SP, &SQ) != EOF)
    {
        maxI = N - 1;
        maxPofs = maxI * SP;
        ansK = (long long int)1 << 62;
        minK = SQ * N;
        for(i = 0 ; i < 32;++i)
        {
            for(j = 0 ; j < 32;++j)
            {
                tempK = ((maxPofs + (maxPofs << i)) >> j) + SQ;
                if(tempK < ansK && tempK >= minK)
                {
                    ansK = tempK;
                    ansA = i;
                    ansB = j;
                }
            }
        }
        printf("%lld %lld %lld\n", ansK, ansA, ansB);
    }
    return 0;
}
