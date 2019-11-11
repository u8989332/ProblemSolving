#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <string>


#define ALL(x) x.begin(), x.end()
#define INS(x) inserter(x, x.begin())

using namespace std;


typedef set<int> Set;
vector<Set> set_stack;
map<Set,int> set_to_id;
vector<int> ids;


int get_id(Set x)
{
    if(set_to_id.count(x))
    {
        return set_to_id[x];
    }

    set_stack.push_back(x);
    return set_to_id[x] = set_stack.size() - 1;
}
int main()
{
    int n;
    int op_no;
    string op;
    cin >> n;

    for(int i = 0 ;i < n;++i)
    {
        cin >> op_no;
        for(int j = 0; j < op_no;++j)
        {
            cin >> op;
            if(op[0] == 'P')
            {
                ids.push_back(get_id(Set()));
            }
            else if(op[0] == 'D')
            {
                ids.push_back(ids.back());
            }
            else
            {
                Set s1 = set_stack[ids.back()];
                ids.pop_back();
                Set s2 = set_stack[ids.back()];
                ids.pop_back();
                Set result;
                if(op[0] == 'U')
                {
                    set_union(ALL(s1), ALL(s2), INS(result));
                }
                else if(op[0] == 'I')
                {
                    set_intersection(ALL(s1), ALL(s2), INS(result));
                }
                else if(op[0] == 'A')
                {
                    result = s2;
                    result.insert(get_id(s1));
                }

                ids.push_back(get_id(result));
            }
            cout << set_stack[ids.back()].size() << endl;
        }
        cout << "***" << endl;
    }
    return 0;
}
