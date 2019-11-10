#include <iostream>
#include <string>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;
set<string> ans_dic;
map<string, int> sort_case_dic;
string str_index[9999];
int main()
{
    string s;
    int index = 0;
    while(cin >> s)
    {
        if(s == "#")
        {
            set<string>::iterator ans_it = ans_dic.begin();
            for(;ans_it != ans_dic.end();++ans_it)
            {
                cout << *ans_it << endl;
            }
            ans_dic.clear();
            sort_case_dic.clear();
            index = 0;
        }
        string lower_s(s.length(), ' ');
        for(int i = 0 ; i < s.length();++i)
        {
            if(isupper(s[i]))
            {
                lower_s[i] = s[i] - 'A' + 'a';
            }
            else
            {
                lower_s[i] = s[i];
            }
        }
        sort(lower_s.begin(), lower_s.end());
        map<string,int>::iterator it = sort_case_dic.find(lower_s);
        if(it != sort_case_dic.end())
        {
            string ori_index_str = str_index[it->second];
            ans_dic.erase(ori_index_str);
        }
        else
        {
            str_index[index] = s;
            sort_case_dic[lower_s] = index++;
            ans_dic.insert(s);
        }
    }
    return 0;
}
