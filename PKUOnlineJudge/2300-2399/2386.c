#include <stdio.h>
int ans;
int N,M;
char maps[105][105];
int dx[8] = {1,1,0,-1,-1,-1,0,1};
int dy[8] = {0,1,1,1,0,-1,-1,-1};
void dfs(int row, int col)
{
    maps[row][col] = '.';
    int i;
    for(i = 0 ; i < 8;++i)
    {
        int nx = dx[i] + col;
        int ny = dy[i] + row;
        if(nx < M && nx >= 0 && ny < N && ny >= 0 && maps[ny][nx] == 'W')
        {
            dfs(ny, nx);
        }
    }
}

int main()
{
    int i,j;
    while(scanf("%d %d", &N, &M) != EOF)
    {
        for(i = 0;i < N;++i)
        {
            scanf("%s", maps[i]);
        }
        ans = 0;
        for(i = 0 ; i < N ;++i)
        {
            for(j = 0 ; j < M;++j)
            {
                if(maps[i][j] == 'W')
                {
                    ans++;
                    dfs(i, j);
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
