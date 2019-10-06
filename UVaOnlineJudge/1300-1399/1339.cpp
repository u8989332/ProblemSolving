#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
    char s1[105];
    char s2[105];
    int cnt1[26];
    int cnt2[26];
    int len;
    bool isOk;
    while(cin >> s1 >> s2)
    {
        isOk = true;
        len = strlen(s1);
        for(int i = 0 ; i < 26;++i)
        {
            cnt1[i] = 0;
            cnt2[i] = 0;
        }

        for(int i = 0; i < len;++i)
        {
            int curC1 = s1[i] - 'A';
            int curC2 = s2[i] - 'A';
            cnt1[curC1]++;
            cnt2[curC2]++;
        }

        sort(cnt1, cnt1 + 26);
        sort(cnt2, cnt2 + 26);

        for(int i = 0 ; i < 26;++i)
        {
            if(cnt1[i] != cnt2[i])
            {
                isOk = false;
                break;
            }
        }

        if(isOk)
        {
            cout << "YES" <<endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}
