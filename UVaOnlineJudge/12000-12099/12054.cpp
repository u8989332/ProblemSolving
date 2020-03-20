#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <cstring>
using namespace std;

set<string> keys_1;
set<string> keys_2;
map<string, string> maps_1;
map<string, string> maps_2;

void split(const string& str, set<string>& keys, map<string, string>& maps) {
	const string delim = ",";
	if("" == str) return;

	char * strs = new char[str.length() + 1];
	strcpy(strs, str.c_str());

	char * d = new char[delim.length() + 1];
	strcpy(d, delim.c_str());

	char *p = strtok(strs, d);
	while(p) {
		string s = p;
		int index = s.find(":");
		string key = s.substr(0, index);
		string val = s.substr(index + 1);
		keys.insert(key);
		maps[key] = val;
		p = strtok(NULL, d);
	}
}

int main()
{
    int n;
    cin >> n;
    string s;
    for(int i = 0 ; i < n;++i)
    {
        keys_1.clear();
        keys_2.clear();
        maps_1.clear();
        maps_2.clear();
        bool has_change = false;
        cin >> s;
        split(s.substr(1, s.length() - 2), keys_1, maps_1);
        cin >> s;
        split(s.substr(1, s.length() - 2), keys_2, maps_2);

        set<string> add_set;
        set_difference(keys_2.begin(), keys_2.end(),
                       keys_1.begin(), keys_1.end(),
                       inserter(add_set, add_set.begin()));

        set<string> remove_set;
        set_difference(keys_1.begin(), keys_1.end(),
                       keys_2.begin(), keys_2.end(),
                       inserter(remove_set, remove_set.begin()));

        set<string> same_set;
        set_intersection(keys_1.begin(), keys_1.end(),
                       keys_2.begin(), keys_2.end(),
                       inserter(same_set, same_set.begin()));

        if(add_set.size() > 0)
        {
            has_change = true;
            cout << "+";
            bool firstOk = false;
            for(auto it = add_set.begin(); it != add_set.end();++it)
            {
                if(firstOk)
                {
                    cout << ",";
                }
                cout << *it;

                firstOk = true;
            }
            cout << endl;
        }

        if(remove_set.size() > 0)
        {
            has_change = true;
            cout << "-";
            bool firstOk = false;
            for(auto it = remove_set.begin(); it != remove_set.end();++it)
            {
                if(firstOk)
                {
                    cout << ",";
                }
                cout << *it;

                firstOk = true;
            }
            cout << endl;
        }

        if(same_set.size() > 0)
        {
            bool firstOk = false;
            bool first_star = false;
            for(auto it = same_set.begin(); it != same_set.end();++it)
            {
                if(maps_1[*it] != maps_2[*it])
                {
                    if(!first_star)
                    {
                        cout << "*";
                        first_star = true;
                    }
                    has_change = true;
                    if(firstOk)
                    {
                        cout << ",";
                    }
                    cout << *it;
                    firstOk = true;
                }
            }
            if(first_star){
                cout << endl;
            }
        }

        if(!has_change)
        {
            cout << "No changes" << endl;
        }

        cout << endl;
    }
    return 0;
}
