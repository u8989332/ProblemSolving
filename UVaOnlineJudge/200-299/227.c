#include <stdio.h>
#include <string.h>

char maps[5][5];
int main()
{
    int firstFlag = 1;
    int findStart = 0;
    int isOk = 1;
    int x,y;
    int index = 1, i, j ;
    char temp;
    char cmd;

    while((temp = getchar()) != EOF && temp != 'Z')
    {
        maps[0][0] = temp;
        if(!firstFlag)
            printf("\n");

        printf("Puzzle #%d:\n", index++);
        findStart = 0;
        isOk = 1;

        for(i = 1 ; i < 5;++i)
        {
            temp = getchar();
            maps[0][i] = temp;
        }
        getchar();

        for(i = 1 ; i < 5;++i)
        {
            for(j = 0 ; j < 5;++j)
            {
                temp = getchar();
                maps[i][j] = temp;
            }
            getchar();
        }

        for(i = 0 ; i < 5;++i)
        {
            for(j = 0 ; j < 5;++j)
            {
                if(maps[i][j] == ' ')
                {
                    y = i;
                    x = j;
                    findStart = 1;
                    break;
                }
            }
            if(findStart)
                break;
        }

        while((cmd = getchar()) != EOF)
        {
            if(cmd == '0')
            {
                break;
            }
            if(cmd == 'A'){
                if(y == 0){
                    isOk = 0;
                    break;
                }
                else{
                    temp = maps[y-1][x];
                    maps[y-1][x] = ' ';
                    maps[y][x] = temp;
                    y = y - 1;
                }
            }
            else if(cmd == 'B'){
                if(y == 4){
                    isOk = 0;
                    break;
                }
                else{
                    temp = maps[y+1][x];
                    maps[y+1][x] = ' ';
                    maps[y][x] = temp;
                    y = y + 1;
                }
            }
            else if(cmd == 'L'){
                if(x == 0){
                    isOk = 0;
                    break;
                }
                else{
                    temp = maps[y][x-1];
                    maps[y][x-1] = ' ';
                    maps[y][x] = temp;
                    x = x - 1;
                }
            }
            else if(cmd == 'R'){
                if(x == 4){
                    isOk = 0;
                    break;
                }
                else{
                    temp = maps[y][x+1];
                    maps[y][x+1] = ' ';
                    maps[y][x] = temp;
                    x = x + 1;
                }
            }
        }

        if(cmd != '0')
        {
            while((cmd = getchar()) != EOF && cmd != '0')
                ;
        }

        getchar();

        if(!isOk)
            printf("This puzzle has no final configuration.\n");
        else{
            for(i = 0 ; i < 5;++i)
            {
                for(j = 0 ; j < 5 ; ++j)
                {
                    if(j > 0) printf(" ");
                    printf("%c",maps[i][j]);
                }
                printf("\n");
            }
        }


        firstFlag = 0;
    }
    return 0;
}
