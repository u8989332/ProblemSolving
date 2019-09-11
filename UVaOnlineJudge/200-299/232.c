#include <stdio.h>

char maps[15][15];
int nums[15][15];
int main()
{
    int r,c;
    int index = 1;
    int counts = 1;
    int firstFlag = 1;
    int i, j, k;
    while(scanf("%d", &r) && r != 0)
    {
        scanf("%d", &c);
        if(!firstFlag)
            printf("\n");

        counts = 1;
        printf("puzzle #%d:\n", index++);
        for(i = 0 ; i < r;++i)
        {
            scanf("%s", maps[i]);
        }

        for(i = 0 ; i < r;++i)
        {
            for(j = 0 ; j < c;++j)
            {
                if(maps[i][j] != '*' && (i == 0 || j == 0 || maps[i-1][j] == '*' || maps[i][j-1] == '*'))
                {
                    nums[i][j] = counts++;
                }
            }
        }
        printf("Across\n");
        for(i = 0 ; i < r;++i)
        {
            for(j = 0 ; j < c;)
            {
                if(maps[i][j] != '*'){
                    printf("%3d.", nums[i][j]);
                    for(k = j;k < c && maps[i][k] != '*';++k)
                    {
                        printf("%c", maps[i][k]);
                    }
                    printf("\n");
                    j = k + 1;
                }
                else{
                    j++;
                }
            }
        }

        printf("Down\n");
        for(i = 0 ; i < r;++i)
        {
            for(j = 0 ; j < c;++j)
            {
                if(maps[i][j] != '*' && (i == 0 || maps[i-1][j] == '*')){
                    printf("%3d.", nums[i][j]);
                    for(k = i;k < r && maps[k][j] != '*';++k)
                    {
                        printf("%c", maps[k][j]);
                    }
                    printf("\n");
                }
            }
        }

        firstFlag = 0;
    }
    return 0;
}
