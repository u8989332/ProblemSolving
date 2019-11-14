#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <cstdio>

using namespace std;

queue<int> teams[1005];
queue<int> big_team;
map<int, int> player_to_team;
int main()
{
    int t;
    int n;
    int no;
    char cmd[10];
    int cases = 1;
    while(scanf("%d", &t) != EOF && t)
    {
        printf("Scenario #%d\n", cases++);
        player_to_team.clear();
        big_team = queue<int>();
        for(int i = 0 ; i < t;++i)
        {
            teams[i] = queue<int>();
            scanf("%d", &n);
            for(int j = 0 ; j < n;++j)
            {
                scanf("%d", &no);
                player_to_team[no] = i;
            }
        }
        while(scanf("%s", cmd))
        {
            if(cmd[0] == 'S')
            {
                printf("\n");
                break;
            }

            if(cmd[0] == 'E')
            {
                scanf("%d", &no);
                if(teams[player_to_team[no]].size() == 0)
                {
                    big_team.push(player_to_team[no]);
                }
                teams[player_to_team[no]].push(no);
            }
            else if(cmd[0] == 'D')
            {
                int front_team = big_team.front();
                printf("%d\n", teams[front_team].front());
                teams[front_team].pop();
                if(teams[front_team].size() == 0)
                {
                    big_team.pop();
                }
            }
        }
    }
    return 0;
}
