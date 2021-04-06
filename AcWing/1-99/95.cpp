#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

int maps[5][5];
int backup[5][5];
int dx[5] = {1,0,-1,0,0};
int dy[5] = {0,1,0,-1,0};
void debug()
{
    cout <<"Debug\n";
    for(int i = 0 ; i < 5;++i)
    {
        for(int j = 0 ; j < 5;++j)
        {
            cout << maps[i][j];
        }
        cout << endl;
    }
}
void turnLight(int r,int c)
{
    for(int i = 0 ; i < 5;++i)
    {
        int ny = r + dy[i];
        int nx = c + dx[i];
        if(ny < 0 || ny >= 5 || nx < 0 || nx >= 5)
        {
            continue;
        }

        maps[ny][nx] ^= 1;
    }
}
int main()
{
    int n;
    cin >> n;
    while(n--)
    {
        for(int i = 0 ; i < 5;++i)
        {
            for(int j = 0 ; j < 5;++j)
            {
                scanf("%1d", &maps[i][j]);
            }
        }
        int ans = 99;
        for(int op = 0 ; op < 32;++op)
        {
            int steps = 0;
            memcpy(backup, maps, sizeof(backup));
            for(int i = 0 ; i < 5;++i)
            {
                if(op >> i & 1)
                {
                    turnLight(0, i);
                    steps++;
                    //debug();
                }
            }

            for(int i = 0;i < 4;++i)
            {
                for(int j = 0 ; j < 5;++j)
                {
                    if(maps[i][j] == 0)
                    {
                        turnLight(i+1, j);
                        steps++;
                        //debug();
                    }
                }
            }

            bool isDark = false;
            for(int i = 0 ; i < 5;++i)
            {
                if(maps[4][i] == 0)
                {
                    isDark = true;
                    break;
                }
            }

            if(!isDark)
            {
                ans = min(ans, steps);
            }

            memcpy(maps, backup, sizeof(maps));
        }

        if(ans > 6)
        {
            cout << "-1" << endl;
        }
        else
        {
            cout << ans << endl;
        }


    }
    return 0;
}
