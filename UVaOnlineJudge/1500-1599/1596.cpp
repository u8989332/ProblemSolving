#include <iostream>
#include <string>
#include <map>
#include <cstdlib>
using namespace std;

struct MyVar {
    string name;
    int index;

    bool operator< (const MyVar &x) const {
        return name < x.name || name == x.name && index < x.index;
    }
};
map<string, int> variable_def;
map<MyVar, int> variable_val;

bool isOverIndex(MyVar x){
    return x.index >= variable_def[x.name];
}

bool isAssigned(MyVar x){
    return variable_val.find(x) != variable_val.end();
}

bool parse_variable(string s, MyVar& x){
    int lp = s.find("[");
    x.name = s.substr(0, lp);
    s = s.substr(lp + 1);
    s.pop_back();

    if(s.back() == ']'){
        MyVar y;
        if(parse_variable(s, y) && !isOverIndex(y) && isAssigned(y)){
            x.index = variable_val[y];
        }
        else{
            return false;
        }
    }
    else{
        x.index = stoi(s);
    }

    return true;
}

void declare(const string& s){
    int lp = s.find('[');
    int rp = s.find_last_of(']');
    int v = stoi(s.substr(lp + 1, rp - lp - 1));
    string name = s.substr(0, lp);
    variable_def[name] = v;
}


int main()
{
    string s;
    string arr[1005];

    int index = 0;
    int errorIndex = -1;
    while(cin >> s)
    {
        if(s == ".")
        {
            if(index == 0)
            {
                break;
            }
            for(int i = 0 ;i < index;++i)
            {
                string curS = arr[i];
                int eq = curS.find("=");
                if(eq == string::npos){
                    declare(curS);
                }
                else
                {
                    MyVar lv;
                    bool ok_left = parse_variable(curS.substr(0, eq), lv);
                    if(!ok_left || isOverIndex(lv)){
                        errorIndex = i;
                        break;
                    }

                    string rs = curS.substr(eq+1);
                    if(isdigit(rs[0]))
                    {
                        variable_val[lv] = stoi(rs);
                    }
                    else{
                        MyVar rv;
                        bool ok_right = parse_variable(curS.substr(eq+1), rv);
                        if(!ok_right || isOverIndex(rv) || !isAssigned(rv)){
                            errorIndex = i;
                            break;
                        }

                        variable_val[lv] = variable_val[rv];
                    }
                }
            }

            if(errorIndex == -1)
            {
                cout << 0 << endl;
            }
            else
            {
                cout << errorIndex +1  << endl;
            }

            errorIndex = -1;
            variable_def.clear();
            variable_val.clear();
            index = 0;
        }
        else
        {
            arr[index++] = s;
        }
    }
    return 0;
}
