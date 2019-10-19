#include <iostream>
#include <cstdio>
#include <string>
#include <map>
#define MAX_INF 99999
using namespace std;

map<string, string> maps;
map<int, string> morse;


int cmp(string sourceMorse, string target)
{
    if(sourceMorse == target)
    {
        return 0;
    }
    if(sourceMorse.length() > target.length())
    {
        swap(sourceMorse, target);
    }
    if(sourceMorse == target.substr(0, sourceMorse.length()))
    {
        return target.length() - sourceMorse.length();
    }

    return MAX_INF;

}

string solve(string target)
{
    int curMinLen = MAX_INF;
    int hasMultiSame = -1;
    string ans;
    for(map<string, string>:: iterator it = maps.begin(); it != maps.end(); ++it){
        int cmpResult = cmp(it->second, target);
        if(!cmpResult && !curMinLen)
        {
            return ans + "!";
        }
        if(cmpResult <= curMinLen)
        {
            ans = it->first;
        }
        curMinLen = min(cmpResult, curMinLen);
    }

    if(curMinLen)
        ans += "?";

    return ans;

}


int main()
{
    string s, s2;
    int i,index;
    morse.clear();
    maps.clear();
    while(cin >> s)
    {
        if(s != "*")
        {
            cin >> s2;
            char c1 = s[0];
            morse[c1] = s2;
        }
        else
        {
            index = 0;
            while(cin >> s)
            {
                if(s == "*")
                {
                    break;
                }
                s2 = "";
                for(i = 0; i < s.length();++i)
                {
                    char curC = s[i];
                    string curMorse = morse[curC];
                    s2 = s2.append(curMorse);
                }
                maps[s] = s2;
            }
            while(cin >> s)
            {
                if(s == "*")
                {
                    break;
                }
                cout << solve(s) << endl;
            }

            morse.clear();
            maps.clear();
        }
    }
    return 0;
}
