#include <iostream>
#include <cstdio>
using namespace std;

struct Point{
    int x,y;
};


bool has_symmetry(Point ps[], int source, int n, int midX)
{
    for(int i = 0 ; i < n;++i)
    {
        if(ps[i].y == ps[source].y && ps[i].x + ps[source].x == midX * 2)
        {
            return true;
        }
    }

    return false;
}

int main()
{
    int t;
    scanf("%d", &t);
    int n;
    Point ps[1005];
    int left_x, right_x;
    while(t--)
    {
        scanf("%d", &n);
        left_x = 20005;
        right_x = -20005;
        for(int i = 0; i < n;++i){
            scanf("%d%d", &ps[i].x, &ps[i].y);
            ps[i].x *= 2;
            if(ps[i].x < left_x)
                left_x = ps[i].x;

            if(ps[i].x > right_x)
                right_x = ps[i].x;


        }
        if(n == 1)
        {
            puts("YES");
            continue;
        }

        int midX = (left_x + right_x) / 2;
        bool ok = true;
        for(int i = 0; i < n; ++i)
        {
           if(!has_symmetry(ps, i, n, midX))
           {
               ok = false;
               break;
           }
        }

        if(ok)
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}
