#include <iostream>
#include <cstring>
typedef long long ll;

using namespace std;

ll dp[1 << 13][13][13];
bool G[13][13];
ll num[1 << 13][13][13];
ll v[13];
int main()
{
    int q;
    cin >> q;
    while(q--)
    {
        int n,m;
        int s,t;
        memset(G, false, sizeof(G));
        cin >> n >> m;
        for(int i = 0;i < n;++i)
        {
            cin >> v[i];
        }

        for(int i = 0 ; i < m;++i)
        {
            cin >> s >> t;
            s--;
            t--;
            G[s][t] = G[t][s] = true;
        }

        if(n == 1)
        {
            cout << v[0] << " 1" << endl;
            continue;
        }

        memset(dp, -1, sizeof(dp));
        memset(num, 0, sizeof(num));

        for(int i = 0 ; i < n;++i)
        {
            for(int j = 0 ; j < n;++j)
            {
                if(i != j && G[i][j])
                {
                    dp[(1<<i) | (1 << j)][i][j] = v[i] + v[j] + v[i]*v[j];
                    num[(1<<i) | (1 << j)][i][j] = 1;
                }
            }
        }

        for(int state = 1; state < (1 << n);++state)
        {
            for(int i = 0 ; i < n;++i)
            {
                if(state >> i & 1)
                {
                    for(int j = 0 ; j < n;++j)
                    {
                        if(i != j && G[i][j] && (state >> j & 1) && dp[state][i][j] != -1)
                        {
                            for(int k = 0 ;k < n;++k)
                            {
                                if(i != k && j != k && !(state >> k & 1) && G[j][k])
                                {
                                    ll temp = dp[state][i][j] + v[k] + v[j]*v[k];

                                    if(G[i][k])
                                    {
                                        temp += v[i]*v[j]*v[k];
                                    }

                                    if(dp[state | (1 << k)][j][k] < temp)
                                    {
                                        dp[state | (1 << k)][j][k] = temp;
                                        num[state | (1 << k)][j][k] = num[state][i][j];
                                    }
                                    else
                                    {
                                        if(dp[state | (1 << k)][j][k] == temp)
                                        {
                                            num[state | (1 << k)][j][k] += num[state][i][j];
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

        ll ansV = 0;
        ll ansN = 0;
        for(int i = 0 ; i < n;++i)
        {
            for(int j = 0 ; j < n;++j)
            {
                if(i != j && G[i][j])
                {
                    if(dp[(1 << n) - 1][i][j] > ansV)
                    {
                        ansV = dp[(1 << n) - 1][i][j];
                        ansN = num[(1 << n) - 1][i][j];
                    }
                    else if(dp[(1 << n) - 1][i][j] == ansV)
                    {
                        ansN += num[(1 << n) - 1][i][j];
                    }
                }
            }
        }

        cout << ansV << " " << (ansN/2) << endl;
    }
    return 0;
}
