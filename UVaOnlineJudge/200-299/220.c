#include <stdio.h>
#include <string.h>

char maps[10][10];
int dx[8] = {1,1,0,-1,-1,-1,0,1};
int dy[8] = {0,1,1,1,0,-1,-1,-1};
char currentPlayer;
int is_possible_move(int direction, int r, int c)
{
    int curR = r, curC = c;
    while(curR <= 8 && curR >= 1 && curC <= 8 && curC >= 1)
    {
        if(maps[curR][curC] == currentPlayer)
        {
            return 1;
        }
        else if(maps[curR][curC] == '-')
        {
            return 0;
        }
        curR = dy[direction] + curR;
        curC = dx[direction] + curC;
    }

    return 0;
}

int is_enemy(int r, int c)
{
    if(currentPlayer == 'B' && maps[r][c] == 'W')
    {
        return 1;
    }
    else if(currentPlayer == 'W' && maps[r][c] == 'B')
    {
        return 1;
    }

    return 0;
}

int print_possible_moves(int is_print)
{
    int i, j, m;
    int counts = 0;
    int next_y, next_x;
    for(i = 1 ; i <= 8;++i)
    {
        for(j = 1; j <= 8;++j)
        {
            if(maps[i][j] == '-')
            {
                for(m = 0 ; m < 8;++m)
                {
                    next_y = dy[m] + i;
                    next_x = dx[m] + j;
                    if(next_y >= 1 && next_y <= 8 && next_x >= 1 && next_x <= 8)
                    {
                        if(is_enemy(next_y, next_x) && is_possible_move(m, next_y, next_x))
                        {
                            if(is_print)
                            {
                                if(counts > 0)
                                {
                                    printf(" ");
                                }
                                printf("(%d,%d)", i, j);
                            }
                            counts++;
                            break;
                        }
                    }
                }
            }
        }
    }
    if(is_print)
    {
        if(counts == 0)
        {
            printf("No legal move.\n");
        }
        else
        {
            printf("\n");
        }
    }
    return counts;
}

void change_player()
{
    if(currentPlayer == 'B')
    {
        currentPlayer = 'W';
    }
    else
    {
        currentPlayer = 'B';
    }
}

void move_piece(int r, int c)
{
    if(print_possible_moves(0) == 0)
    {
        change_player();
    }
    maps[r][c] = currentPlayer;
    int i, j, m,next_y, next_x;
    int bn = 0, wn = 0;
    for(m = 0 ; m < 8;++m)
    {
        next_y = dy[m] + r;
        next_x = dx[m] + c;
        if(next_y >= 1 && next_y <= 8 && next_x >= 1 && next_x <= 8)
        {
            if(is_enemy(next_y, next_x) && is_possible_move(m, next_y, next_x))
            {
                for(i = next_y, j = next_x; i >= 1 && i <= 8 && j >= 1 && j <= 8 && maps[i][j] != currentPlayer;i += dy[m], j += dx[m])
                {
                    maps[i][j] = currentPlayer;
                }
            }
        }
    }

    for(i = 1 ; i <= 8;++i)
    {
        for(j = 1 ; j <= 8;++j)
        {
            if(maps[i][j] == 'B')
            {
                bn++;
            }
            else if(maps[i][j] == 'W')
            {
                wn++;
            }
        }
    }
    printf("Black -%3d White -%3d\n", bn, wn);

    change_player();
}

void print_maps()
{
    int i,j;
    for(i = 1 ; i <= 8;++i)
    {
        for(j = 1 ; j <= 8;++j)
        {
            printf("%c", maps[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int cases;
    int i,j,k;
    char cmds[10];
    char c;
    scanf("%d", &cases);
    while(k < cases)
    {
        if(k > 0)
        {
            printf("\n");
        }
        getchar();
        for(i = 1 ; i <= 8;++i)
        {
            for(j = 1 ; j <= 8;++j)
            {
                c = getchar();
                maps[i][j] = c;
            }
            getchar();
        }

        scanf(" %c", &currentPlayer);

        while(scanf("%s", cmds) != EOF)
        {
            if(strcmp(cmds, "Q") == 0)
            {
                print_maps();
                break;
            }

            if(cmds[0] == 'L')
            {
                print_possible_moves(1);
            }
            else if(cmds[0] == 'M')
            {
                move_piece(cmds[1] - '0' , cmds[2] - '0');
            }
        }

        k++;
    }
    return 0;
}
