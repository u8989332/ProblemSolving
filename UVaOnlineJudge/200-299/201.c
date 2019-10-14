#include <stdio.h>
#include <string.h>
int maps[12][12][12][12];
int n;

int v_has_line(int x, int y1, int y2)
{
    int diff = y2-y1;
    int i,j;
    int ok = 1;
    for(i = 0,j = y1 ; i < diff;++i, ++j)
    {
        if(!maps[x][j][x][j+1])
        {
            ok = 0;
            break;
        }
    }
    return ok;
}

int h_has_line(int y, int x1, int x2)
{
    int diff = x2-x1;
    int i,j;
    int ok = 1;
    for(i = 0,j = x1 ; i < diff;++i, ++j)
    {
        if(!maps[j][y][j+1][y])
        {
            ok = 0;
            break;
        }
    }
    return ok;
}

int main()
{
    int i, e;
    char d;
    int n1, n2;
    int x,y, nx, ny;
    int diff;
    int ans[11];
    int cases = 1;
    int foundAns = 0;
    while(scanf("%d", &n) != EOF)
    {
        if(cases > 1)
        {
            printf("\n**********************************\n\n");
        }
        printf("Problem #%d\n\n", cases);

        foundAns = 0;
        memset(ans, 0, sizeof(ans));
        memset(maps, 0, sizeof(maps));
        scanf("%d", &e);
        for(i = 0 ; i < e;++i)
        {
            scanf(" %c %d %d", &d, &n1, &n2);
            if(d == 'H')
            {
                maps[n2][n1][n2+1][n1] = maps[n2+1][n1][n2][n1] = 1;
            }
            else
            {
                maps[n1][n2+1][n1][n2] = maps[n1][n2][n1][n2+1] = 1;
            }
        }

        for(y = 1 ; y < n;++y)
        {
            for(x = 1 ; x < n;++x)
            {
                for(diff = 1; diff + x <= n && diff + y <= n;++diff)
                {
                    nx = x + diff;
                    ny = y + diff;
                    if(v_has_line(x, y, ny) && v_has_line(nx, y, ny)
                       && h_has_line(y, x, nx) && h_has_line(ny, x, nx))
                    {
                        ans[diff]++;
                        foundAns = 1;
                    }
                }
            }
        }

        if(foundAns)
        {
            for(i = 1;i < n;++i)
            {
                if(ans[i])
                {
                    printf("%d square (s) of size %d\n", ans[i], i);
                }
            }
        }
        else
        {
            printf("No completed squares can be found.\n");
        }

        cases++;
    }
    return 0;
}
