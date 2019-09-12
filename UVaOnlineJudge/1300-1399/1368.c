#include <stdio.h>
#include <string.h>
#include <limits.h>
int nums[55];
char dnas[55][1005];
char const_dna[4] = {'T', 'G', 'C', 'A'};
int main()
{
    int cases,i,j,k,n,m;
    int minNum;
    int minDnaIndex;
    char ansDns[1005];
    int ansSum, tempSum;
    scanf("%d", &cases);
    while(cases--){
        scanf("%d %d", &m, &n);
        for(i = 0 ; i < m;++i){
            nums[i] = 0;
            scanf("%s", dnas[i]);
        }

        ansSum = 0;
        for(i = 0 ; i < n ;++i){
            minNum = INT_MAX;
            minDnaIndex = -1;
            for(j = 0 ; j < 4;++j)
            {
                tempSum = 0;
                for(k = 0 ; k < m;++k)
                {
                    if(const_dna[j] != dnas[k][i]){
                        tempSum++;
                    }
                }

                if(tempSum <= minNum){
                    minDnaIndex = j;
                    minNum = tempSum;
                }
            }
            ansSum += minNum;
            ansDns[i] = const_dna[minDnaIndex];
        }
        ansDns[n] = '\0';

        printf("%s\n%d\n", ansDns, ansSum);
    }
    return 0;
}
