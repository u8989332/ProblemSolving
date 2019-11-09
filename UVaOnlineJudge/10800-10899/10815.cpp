#include <iostream>
#include <string>
#include <cstring>
#include <set>
#include <vector>

using namespace std;

vector<string> ger_processed_str(string s)
{
    vector<string> result;
    for(int i = 0 ;i < s.length();++i)
    {
        if(isupper(s[i]))
        {
            s[i] = s[i] - 'A' + 'a';
        }
    }
    int i;
    int is_first_letter_index = -1;
    bool finds = false;
    for(i = 0; i < s.length();++i)
    {
        if(isalpha(s[i]))
        {
            if(!finds)
            {
                is_first_letter_index = i;
                finds = true;
            }
        }
        else
        {
            if(finds)
            {
                result.push_back(s.substr(is_first_letter_index, i - is_first_letter_index));
                finds = false;
            }
        }
    }

    if(finds)
    {
        result.push_back(s.substr(is_first_letter_index, s.length() - is_first_letter_index));
    }
    return result;
}

int main()
{
    set<string> sets;
    string s;
    while(cin >> s)
    {
        vector<string> processedStr = ger_processed_str(s);
        for(int i = 0 ; i < processedStr.size();++i)
        {
            sets.insert(processedStr[i]);
        }

    }

    set<string>::iterator itr;
    for(itr = sets.begin();itr != sets.end();++itr)
    {
        cout << *itr << endl;
    }
    return 0;
}
