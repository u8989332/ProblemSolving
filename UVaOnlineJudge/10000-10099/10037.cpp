#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int arr[1005];
int n;

queue<int> walkPeople;
int ans, solution1, solution2, littleSol_1, littleSol_2;
int main()
{
    int cases;
    bool flag = false;
    cin >> cases;
    while(cases--)
    {
        ans = 0;
        if(flag) cout << endl;
        cin >> n;
        for(int i = 1;i <= n;++i)
        {
            cin >> arr[i];
        }

        if(n == 1)
        {
            cout << arr[1] << endl;
            cout << arr[1] << endl;
        }
        else
        {
            sort(arr+1, arr+(n+1));
            while(n > 3)
            {
                littleSol_1 = arr[1] + arr[n-1];
                littleSol_2 = arr[2] * 2;
                solution1 = arr[1] * 2 + arr[n] + arr[n-1];
                solution2 = arr[2] * 2 + arr[1] + arr[n];
                if(littleSol_1 < littleSol_2)
                {
                    ans += solution1;
                    walkPeople.push(arr[1]);
                    walkPeople.push(arr[n]);
                    walkPeople.push(arr[1]);
                    walkPeople.push(arr[1]);
                    walkPeople.push(arr[n-1]);
                    walkPeople.push(arr[1]);
                }
                else
                {
                    ans += solution2;
                    walkPeople.push(arr[1]);
                    walkPeople.push(arr[2]);
                    walkPeople.push(arr[1]);
                    walkPeople.push(arr[n-1]);
                    walkPeople.push(arr[n]);
                    walkPeople.push(arr[2]);
                }
                n -= 2;
            }

            if(n == 3)
            {
                ans += arr[3] + arr[1] + arr[2];
                walkPeople.push(arr[1]);
                walkPeople.push(arr[3]);
                walkPeople.push(arr[1]);
                walkPeople.push(arr[1]);
                walkPeople.push(arr[2]);
            }
            else
            {
                ans += arr[2];
                walkPeople.push(arr[1]);
                walkPeople.push(arr[2]);
            }
            cout << ans << endl;
            while(!walkPeople.empty())
            {
                cout << walkPeople.front();
                walkPeople.pop();

                cout << " " << walkPeople.front();
                walkPeople.pop();

                cout << endl;

                if(walkPeople.empty())
                {
                    break;
                }

                cout << walkPeople.front();
                walkPeople.pop();

                cout << endl;
            }
        }

        flag = true;
    }
    return 0;
}
