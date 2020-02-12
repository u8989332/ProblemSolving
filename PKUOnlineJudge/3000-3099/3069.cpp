#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int R,N;
    int X[1005];
    while(cin >> R >> N)
    {
        if(R == -1 && N == -1)
            break;

        for(int i = 0 ; i < N;++i)
        {
            cin >> X[i];
        }

        sort(X, X+N);

        int ans = 0;
        int s = 0;
        int p = 0;
        int i = 0;

        while(i < N)
        {
            s = X[i++];
            while(i < N && s + R >= X[i])
                i++;

            p = X[i-1];

            while(i < N && p + R >= X[i])
                i++;
            ans++;
        }

        cout << ans << endl;
    }
    return 0;
}
