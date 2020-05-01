#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int dp[13000];
int w[3500];
int v[3500];
int main()
{
    int N, M;
    while(cin >> N >> M){
        for(int i = 0 ; i < N;++i){
            cin >> w[i] >> v[i];
        }

        memset(dp, 0, sizeof(dp));
        for(int i = 0 ; i < N;++i){
            for(int j = M;j >= w[i];--j){
                dp[j] = max(dp[j], dp[j-w[i]] + v[i]);
            }
        }
        cout << dp[M] << endl;
    }
    return 0;
}
