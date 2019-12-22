#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <iomanip>
using namespace std;

vector<vector<string>> strs;
int max_lens[1005];
int main()
{
    string s;
    string s2;
    string temp;
    int total = 0;
    memset(max_lens, 0, sizeof(max_lens));
    while(getline(cin, s)){
        vector<string> newV;
        strs.push_back(newV);
        stringstream ss(s);
        int j = 0;
        while(ss >> temp){
            strs[total].push_back(temp);
            if(temp.length() > max_lens[j]){
                max_lens[j] = temp.length();
            }
            j++;
        }
        total++;
    }

    for(int i = 0 ; i < total;++i){
        for(int j = 0 ; j < strs[i].size();++j){
            if(j < strs[i].size() - 1){
                cout << left << setw(max_lens[j] + 1);
            }
            cout << strs[i][j];
        }
        cout << endl;
    }

    return 0;
}
