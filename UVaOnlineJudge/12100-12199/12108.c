#include <stdio.h>

int n;

int A[11];
int B[11];
int C[11];
int D[11];
int action_index[11];

int get_status(int people)
{
    if(action_index[people] <= A[people])
    {
        return 1;
    }
    return 0;
}

void next_action(int people, int sleep_count, int awake_count)
{
    action_index[people]++;
    if(action_index[people] > D[people])
    {
        action_index[people] = 1;
    }
    else if(awake_count >= sleep_count && action_index[people] == A[people] + 1)
    {
        action_index[people] = 1;
    }
}

int main()
{
    int cases = 1;
    int i,j;
    while(scanf("%d", &n) && n)
    {
        int max_time = 1;
        int cur_time = 1;
        int isOk;
        int sleep_count;
        int awake_count;
        for(i = 0 ; i < n;++i)
        {
            scanf("%d %d %d", &A[i], &B[i], &C[i]);
            D[i] = A[i] + B[i];
            max_time *= D[i];
            action_index[i] = C[i];
        }
        printf("Case %d: ", cases++);

        for(i = 1;i <= max_time;++i)
        {
            sleep_count = 0;
            awake_count = 0;
            for(j = 0 ; j < n;++j)
            {
                if(get_status(j) == 0)
                {
                    sleep_count++;
                }
                else
                {
                    awake_count++;
                }
            }

            if(awake_count == n)
            {
                printf("%d\n", i);
                break;
            }
            for(j = 0 ; j < n;++j)
            {
                next_action(j, sleep_count, awake_count);
            }
        }

        if(i > max_time)
        {
            printf("-1\n");
        }

    }
    return 0;
}
