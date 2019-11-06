#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n, q;
    int temp;
    int cases = 1;
    vector<int> arr;
    vector<int>::iterator low;
    while(cin >> n >> q && n && q)
    {
        arr.clear();
        for(int i = 0 ; i  < n;++i)
        {
            cin >> temp;
            arr.push_back(temp);
        }

        sort(arr.begin(), arr.end());
        cout << "CASE# " << cases++ << ":" << endl;
        for(int i = 0 ; i < q;++i)
        {
            cin >> temp;
            low = lower_bound(arr.begin(),arr.end(),temp);
            if(low == arr.end() || *low != temp)
            {
                cout << temp << " not found" << endl;
            }
            else{
                cout << temp << " found at " << (low- arr.begin()) + 1 << endl;
            }
        }
    }
    return 0;
}
