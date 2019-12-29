#include <iostream>
#include <algorithm>
#include <cstdio>
#define MAXN 500005
using namespace std;

int from[MAXN], to[MAXN];
int main()
{
    int n;
    while(scanf("%d", &n) && n)
    {
        bool ok = true;
        for(int i = 0 ; i < n;++i){
            scanf("%d%d", from + i, to + i);
        }
        if(n % 2){
            ok = false;
        }
        else{
            sort(from, from + n);
            sort(to, to + n);
            for(int i = 0 ; i < n;++i){
                if(from[i] != to[i]){
                    ok = false;
                    break;
                }
            }
        }

        printf("%s\n", (ok ? "YES" : "NO"));
    }
    return 0;
}
