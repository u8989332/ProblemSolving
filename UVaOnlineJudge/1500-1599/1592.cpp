#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;



vector<string> split(const string& str, const string& delim) {
	vector<string> res;
	if("" == str) return res;

	char * strs = new char[str.length() + 1] ;
	strcpy(strs, str.c_str());

	char * d = new char[delim.length() + 1];
	strcpy(d, delim.c_str());

	char *p = strtok(strs, d);
	while(p) {
		string s = p;
		res.push_back(s);
		p = strtok(NULL, d);
	}

	return res;

}

vector<string> str_table[10005];
int main()
{
    int n,m;
    string s;
    bool find_ans = false;
    bool is_PNF = true;
    int r1, r2, c1, c2;
    map<string, vector<int>> col_str_mapping_index[11];
    while(cin >> n >> m)
    {
        find_ans = false;
        is_PNF = true;
        for(int i = 0 ; i < n;++i)
        {
            str_table[i].clear();
        }
        for(int i = 0 ; i < m;++i)
        {
            col_str_mapping_index[i].clear();
        }

        if(m == 1)
        {
            find_ans = true;
        }
        getchar();
        for(int i = 0 ; i < n;++i)
        {
            getline(cin, s);
            if(!find_ans)
            {
                vector<string> arr = split(s, ",");
                vector<int> should_check_col;
                vector<string> should_check_str;
                for(int j = 0 ; j < m;++j)
                {
                    string cur_s = arr[j];
                    str_table[i].push_back(cur_s);
                    if(col_str_mapping_index[j].find(arr[j]) == col_str_mapping_index[j].end())
                    {
                        col_str_mapping_index[j][arr[j]].push_back(i);
                    }
                    else
                    {
                        col_str_mapping_index[j][arr[j]].push_back(i);
                        should_check_col.push_back(j);
                    }
                }
                for(int j = 0 ;j < should_check_col.size();++j)
                {
                    int check_col = should_check_col[j];
                    for(int target_col = 0 ; target_col < m;++target_col)
                    {
                        if(target_col == check_col)
                        {
                            continue;
                        }

                        vector<int> col_str_indexes = col_str_mapping_index[check_col][str_table[i][check_col]];
                        vector<int> col_target_str_indexes = col_str_mapping_index[target_col][str_table[i][target_col]];
                        vector<int> result;
                        set_intersection(col_str_indexes.begin(),
                                         col_str_indexes.end(),
                                         col_target_str_indexes.begin(),
                                         col_target_str_indexes.end(),
                                         inserter(result,
                                         result.begin()) );

                        if(result.size() >= 2)
                        {
                            find_ans = true;
                            is_PNF = false;
                            r1 = result[0] + 1;
                            r2 = result[1] + 1;
                            if(target_col < check_col)
                            {
                                c1 = target_col;
                                c2 = check_col;
                            }
                            else
                            {
                                c1 = check_col;
                                c2 = target_col;
                            }
                            c1++;
                            c2++;
                        }

                    }
                }
            }
        }

        if(is_PNF)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
            cout << r1 << " " << r2 << endl;
            cout << c1 << " " << c2 << endl;
        }
    }
    return 0;
}
