#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int main()
{
    char s[2005];
    int n;
    char c;
    int i;
    while(cin >> n)
    {
        for(i = 0 ; i < n;++i)
        {
            cin >> c;
            s[i] = c;
        }
        int L = 0, R = n-1;
        int left = 0;
        int print_count = 0;
        while(L <= R)
        {
            for(i = 0; L + i <= R;++i)
            {
                if(s[L + i] < s[R - i])
                {
                    left = 1;
                    break;
                }
                else if(s[L + i] > s[R - i])
                {   left = 0;
                    break;
                }
            }
            if(left)
                putchar(s[L++]);
            else
                putchar(s[R--]);

            print_count++;

            if(print_count == 80)
            {
                print_count = 0;
                cout << endl;
            }
        }

        if(print_count)
        {
            cout << endl;
        }
    }
    return 0;
}
