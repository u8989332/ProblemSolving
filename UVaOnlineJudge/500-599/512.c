#include <stdio.h>
#include <string.h>
#define OFFSET 10000
#define maxd 100
int r,c;
int maps[maxd][maxd];
int copyMaps[maxd][maxd];
int ans[maxd][maxd];
int cols[maxd];

void copy(char type, int s, int t)
{
    int i;
    if(type == 'R')
    {
        for(i = 1;i <= c;++i)
        {
            maps[s][i] = copyMaps[t][i];
        }
    }
    else{
        for(i = 1;i <= r;++i)
        {
            maps[i][s] = copyMaps[i][t];
        }
    }
}

void del(char type)
{
    memcpy(copyMaps, maps, sizeof(maps));
    int i;
    int newRC = 1;
    int maxRC = type == 'R' ? r : c;
    for(i = 1;i <= maxRC;++i)
    {
        if(!cols[i])
        {
            copy(type, newRC++, i);
        }
    }
    newRC--;
    if(type == 'R')
    {
        r = newRC;
    }
    else
    {
        c = newRC;
    }
}

void insert(char type)
{
    memcpy(copyMaps, maps, sizeof(maps));
    int i;
    int newRC = 1;
    int maxRC = type == 'R' ? r : c;
    for(i = 1;i <= maxRC;++i)
    {
        if(cols[i])
        {
            copy(type, newRC++, 0);
        }
        copy(type, newRC++, i);
    }
    newRC--;
    if(type == 'R')
    {
        r = newRC;
    }
    else
    {
        c = newRC;
    }
}

void exchange(int r1, int c1, int r2, int c2)
{
    int temp = maps[r1][c1];
    maps[r1][c1] = maps[r2][c2];
    maps[r2][c2] = temp;
}

/*
DEBUG
*/
void printCell()
{
    int i,j;
    for(i = 1 ; i <= r;++i)
    {
        for(j = 1 ; j <= c;++j)
        {
            printf(" %d ", maps[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int cmdCount;
    int DICount;
    int DICol;
    char cmds[5];
    int i,j;
    int spreads = 1;
    int query;
    int qr, qc;
    while(scanf("%d %d", &r, &c) != EOF && r && c)
    {
        if(spreads > 1)
        {
            printf("\n");
        }
        printf("Spreadsheet #%d\n", spreads++);

        scanf("%d", &cmdCount);
        memset(maps, 0, sizeof(maps));
        memset(ans, 0, sizeof(ans));
        for(i = 1 ; i <= r;++i)
        {
            for(j = 1 ; j <= c;++j)
            {
                maps[i][j] = i * OFFSET + j;
            }
        }

        while(cmdCount--)
        {
            scanf("%s", cmds);
            if(strcmp(cmds, "EX")==0)
            {
                int r1, c1, r2, c2;
                scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
                exchange(r1, c1, r2, c2);
            }
            else{
                scanf("%d", &DICount);
                memset(cols, 0, sizeof(cols));
                for(i = 1 ; i <= DICount;++i)
                {
                    scanf("%d", &DICol);
                    cols[DICol] = 1;
                }
                if(cmds[0] == 'D')
                {
                    del(cmds[1]);
                }
                else
                {
                    insert(cmds[1]);
                }
                /*printCell();*/
            }
        }

        for(i = 1 ; i <= r;++i)
        {
            for(j = 1 ; j <= c;++j)
            {
                ans[maps[i][j] / OFFSET][maps[i][j] % OFFSET] = i*OFFSET + j;
            }
        }

        scanf("%d", &query);
        while(query--)
        {
            scanf("%d %d", &qr, &qc);
            printf("Cell data in (%d,%d) ", qr, qc);
            if(ans[qr][qc])
            {
                printf("moved to (%d,%d)\n", ans[qr][qc] / OFFSET, ans[qr][qc] % OFFSET);
            }
            else{
                printf("GONE\n");
            }
        }

    }
    return 0;
}
