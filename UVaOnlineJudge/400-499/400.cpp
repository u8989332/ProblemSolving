#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void print_left_white(int n)
{
    for(int i = 0 ; i < n;++i)
    {
        cout << " ";
    }
}
int main()
{
    int n;
    string s;
    int max_len;
    vector<string> arr;
    while(cin >> n)
    {
        max_len = -1;
        arr.clear();
        for(int i = 0; i < n;++i)
        {
            cin >> s;
            int len = s.length();
            if(len > max_len)
            {
                max_len = len;
            }
            arr.push_back(s);
        }
        sort(arr.begin(), arr.end());
        int cols = (60 - max_len) / (max_len + 2) + 1;
        int rows = n / cols + (n % cols == 0 ? 0 : 1);
        cout << "------------------------------------------------------------" << endl;
        int counts = 0;
        for(int i = 0 ; i < rows;++i)
        {
            for(int j = 0 ; j < cols;++j)
            {
                int index = j * rows + i;
                if(index >= n)
                {
                    break;
                }
                cout << arr[index];
                if(j < cols -1)
                {
                    print_left_white(max_len-arr[index].length() + 2);
                }
                counts++;
                if(counts >= n)
                {
                    break;
                }
            }
            cout << endl;
            if(counts >= n)
            {
                break;
            }
        }
    }
    return 0;
}
