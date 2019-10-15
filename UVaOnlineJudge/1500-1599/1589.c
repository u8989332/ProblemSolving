#include <stdio.h>
#include <string.h>

int red_count;
char maps[11][11];
struct Red{
    int r;
    int c;
    char Piece;
} reds[10];

void swap(int *x, int *y)
{
    int temp = *x;
    *y = *x;
    *x = temp;
}
int horse_dr[8] = {-2, -2, -1, 1, 2, 2, 1, -1};
int horse_dc[8] = {-1, 1, 2, 2, 1, -1, -2, -2};
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int get_blocks_between(int r1, int c1, int r2, int c2)
{
    int blocks = 0;
    int i;
    if(r1 != r2 && c1 != c2)
    {
        return -1;
    }
    if(r1 == r2 && c1 == c2)
    {
        return -1;
    }

    if(r1 == r2)
    {
        int tempC1 = c1;
        int tempC2 = c2;
        if(tempC1 > tempC2)
        {
            swap(&tempC1, &tempC2);
        }

        for(i = tempC1 + 1 ; i < tempC2;++i)
        {
            if(maps[r1][i] != ' ')
            {
                blocks++;
            }
        }
    }
    else
    {
        int tempR1 = r1;
        int tempR2 = r2;
        if(tempR1 > tempR2)
        {
            swap(&tempR1, &tempR2);
        }

        for(i = tempR1 + 1 ; i < tempR2;++i)
        {
            if(maps[i][c1] != ' ')
            {
                blocks++;
            }
        }
    }

    return blocks;
}


int can_red_general_check(int blackR, int blackC, int redR, int redC)
{
    return get_blocks_between(blackR, blackC, redR, redC) == 0;
}

int can_red_chariot_check(int blackR, int blackC, int redR, int redC)
{
    return get_blocks_between(blackR, blackC, redR, redC) == 0;
}

int can_red_cannon_check(int blackR, int blackC, int redR, int redC)
{
    return get_blocks_between(blackR, blackC, redR, redC) == 1;
}

int can_red_horse_check(int blackR, int blackC, int redR, int redC)
{
    int i;
    int newR, newC;
    for(i = 0 ; i < 8;++i)
    {
        newR = horse_dr[i] + redR;
        newC = horse_dc[i] + redC;

        if(newR <= 10 && newC <= 9 && newR >= 1 && newC >= 1)
        {
            if((i == 0 || i == 1) && maps[redR-1][redC] == ' ' && newR == blackR && newC == blackC)
            {
                return 1;
            }
            else if((i == 2 || i == 3) && maps[redR][redC+1] == ' ' && newR == blackR && newC == blackC)
            {
                return 1;
            }
            else if((i == 4 || i == 5) && maps[redR+1][redC] == ' ' && newR == blackR && newC == blackC)
            {
                return 1;
            }
            else if((i == 6 || i == 7) && maps[redR][redC-1] == ' ' && newR == blackR && newC == blackC)
            {
                return 1;
            }
            else
            {
                continue;
            }
        }
    }

    return 0;

}


int main()
{
    int n, blackR, blackC, i,j;
    int redR, redC;
    int next_black_R, next_black_C;
    int red_G_R, red_G_C;
    int can_red_beat;
    int one_win_road;
    char piece;
    while(scanf("%d %d %d", &n, &blackR, &blackC)!= EOF && n && blackC && blackR)
    {
        one_win_road = 0;
        memset(maps, ' ', sizeof(maps));
        red_G_R = red_G_C = 0;
        for(i = 0 ; i < n;++i)
        {
            scanf(" %c %d %d", &piece, &redR, &redC);
            reds[i].r = redR;
            reds[i].c = redC;
            reds[i].Piece = piece;
            maps[redR][redC] = piece;
            if(piece == 'G')
            {
                red_G_R = redR;
                red_G_C = redC;
            }
        }

        /*
        black check red
        */
        if(red_G_C != 0)
        {
            if(can_red_general_check(blackR, blackC, red_G_R, red_G_C))
            {
                printf("NO\n");
                continue;
            }
        }

        /*
        will any red whether check black
        */
        for(i = 0 ; i < 4;++i)
        {
            next_black_R = dy[i] + blackR;
            next_black_C = dx[i] + blackC;
            if(next_black_R <= 3 && next_black_R >= 1 && next_black_C >= 4 && next_black_C <= 6)
            {
                can_red_beat = 0;
                for(j = 0;j < n;++j)
                {
                    int curRedC = reds[j].c;
                    int curRedR = reds[j].r;
                    if(reds[j].Piece == 'G' && can_red_general_check(next_black_R, next_black_C, curRedR, curRedC))
                    {
                        can_red_beat = 1;
                        break;
                    }
                    else if(reds[j].Piece == 'H' && can_red_horse_check(next_black_R, next_black_C, curRedR, curRedC))
                    {
                        can_red_beat = 1;
                        break;
                    }
                    else if(reds[j].Piece == 'C' && can_red_cannon_check(next_black_R, next_black_C, curRedR, curRedC))
                    {
                        can_red_beat = 1;
                        break;
                    }
                    else if(reds[j].Piece == 'R' && can_red_chariot_check(next_black_R, next_black_C, curRedR, curRedC))
                    {
                        can_red_beat = 1;
                        break;
                    }
                }
                if(!can_red_beat)
                {
                    one_win_road = 1;
                    break;
                }
            }
        }

        if(one_win_road)
        {
            printf("NO\n");
        }
        else
        {
            printf("YES\n");
        }
    }
    return 0;
}
