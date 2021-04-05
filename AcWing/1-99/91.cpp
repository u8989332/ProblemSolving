#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int f[1<<20][20];
int main()
{
    int n;
    int weight[20][20];
    while(cin >> n)
    {
        for(int i = 0 ; i < n;++i)
        {
            for(int j = 0 ; j < n;++j)
            {
                cin >> weight[i][j];
            }
        }

        memset(f, 0x3f, sizeof(f));
        f[1][0] = 0;
        for(int i = 0 ; i < 1 << n;++i)
        {
            for(int j = 0 ; j < n;++j)
            {
                if(i >> j & 1)
                {
                    for(int k = 0 ; k < n;++k)
                    {
                        if(i >> k & 1)
                        {
                            f[i][j] = min(f[i][j], f[i ^ (1 << j)][k] + weight[k][j]);
                        }
                    }
                }
            }
        }

        cout << f[(1 << n) - 1][n-1] << endl;
    }
    return 0;
}
