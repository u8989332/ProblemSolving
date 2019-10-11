#include <stdio.h>
int maps[25];
int N,m,k;

void move_right_circle(int *right)
{
    int* i = right;
    do
    {
        *i = (*i) + 1;
        if(*i > N)
        {
            *i = 1;
        }
    }while(maps[*i] == -1);
}

void move_left_circle(int *left)
{
    int* i = left;

    do
    {
        *i = (*i) - 1;
        if(*i < 1)
        {
            *i = N;
        }
    }while(maps[*i] == -1);
}
int main()
{
    int i,j;
    int right, left;
    int counts ;
    while(scanf("%d %d %d", &N, &m, &k) == 3 && N && m && k)
    {
        for(i =1 ; i <= N ;++i)
        {
            maps[i] = 1;
        }
        counts = 0;
        right = N;
        left = 1;
        do
        {
            for(j = 0 ; j < k;++j)
            {
                move_left_circle(&left);
            }

            for(j = 0 ; j < m;++j)
            {
                move_right_circle(&right);
            }
            maps[left] = -1;
            maps[right] = -1;
            if(left == right)
            {
                counts++;
                printf("%3d", left);
            }
            else
            {
                counts+=2;
                printf("%3d%3d",right, left);
            }
            if(counts < N)
            {
                printf(",");
            }
            else
            {
                printf("\n");
            }
        }while(counts < N);
    }
    return 0;
}
