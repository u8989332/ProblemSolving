#include <iostream>
#include <string>
#include <set>
using namespace std;

set<string> s_set;
int main()
{
    string s;
    while(cin >> s)
    {
        s_set.insert(s);
    }

    set<string>::iterator it = s_set.begin();
    for(;it != s_set.end();++it)
    {
        string curS = (*it);
        if(curS.length() == 1)
        {
            continue;
        }

        for(int j = 1 ; j < curS.length();++j)
        {
            string s1 = curS.substr(0, j);
            string s2 = curS.substr(j);
            if(s_set.count(s1) && s_set.count(s2))
            {
                cout << curS << endl;
                break;
            }
        }
    }

    return 0;
}
