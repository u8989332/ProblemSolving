#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <string>
#include <sstream>
#include <map>
#include <cstring>
using namespace std;

struct BigInteger{
    static const int BASE = 100000000;
    static const int WIDTH = 8;
    vector<int> s;
    BigInteger(long long num = 0){
        *this = num;
    }
    BigInteger operator = (long long num){
        s.clear();
        do{
            s.push_back(num % BASE);
            num /= BASE;
        }while(num > 0);
        return *this;
    }
    BigInteger operator = (const string& str){
        s.clear();
        int x, len = (str.length() - 1) / WIDTH + 1;
        for(int i = 0; i < len;i++){
            int end = str.length() - i*WIDTH;
            int start = max(0, end-WIDTH);
            sscanf(str.substr(start, end-start).c_str(), "%d", &x);
            s.push_back(x);
        }
        return *this;
    }

    BigInteger operator + (const BigInteger& b) const{
        BigInteger c;
        c.s.clear();
        for(int i = 0, g = 0;;i++){
            if(g == 0 && i >= s.size() && i >= b.s.size()) break;
            int x = g;
            if(i < s.size()) x+=s[i];
            if(i < b.s.size()) x+=b.s[i];
            c.s.push_back(x % BASE);
            g = x / BASE;
        }
        return c;
    }
};

ostream& operator << (ostream &out, const BigInteger& x){
    out << x.s.back();
    for(int i = x.s.size()-2; i >= 0;i--){
        char buf[20];
        sprintf(buf, "%08d", x.s[i]);
        for(int j = 0; j< strlen(buf);j++){
            out << buf[j];
        }
    }

    return out;
}

istream& operator >> (istream &in, BigInteger& x){
    string s;
    if(!(in >> s))
        return in;

    x = s;
    return in;
}

struct Trie{
    int c[5000005][10];
    int val[5000005];
    int sz;
    int getIndex(char c){
        return c - '0';
    }
    void init(){
        memset(c[0], 0, sizeof(c[0]));
        memset(val, -1, sizeof(val));
        sz = 1;
    }

    void insert(BigInteger x, int v){
        int u = 0;
        int max_len_count = 0;
        int firstNum = x.s.back();
        char firstBuf[20];
        sprintf(firstBuf, "%d", firstNum);
        for(int j = 0; j < strlen(firstBuf);j++){
            int index = getIndex(firstBuf[j]);
            if(!c[u][index]){
                memset(c[sz], 0 , sizeof(c[sz]));
                val[sz] = v;
                c[u][index] = sz++;
            }
            u = c[u][index];
            max_len_count++;
        }

        for(int i = x.s.size()-2; i >= 0;i--){
            char buf[20];
            sprintf(buf, "%08d", x.s[i]);
            for(int j = 0; j < strlen(buf) && max_len_count < 50;j++){
                int index = getIndex(buf[j]);
                if(!c[u][index]){
                    memset(c[sz], 0 , sizeof(c[sz]));
                    val[sz] = v;
                    c[u][index] = sz++;
                }
                u = c[u][index];
                max_len_count++;
            }
            if(max_len_count >= 50){
                break;
            }
        }
    }

    int find(const char* s){
        int u = 0;
        int n = strlen(s);
        for(int i = 0 ; i < n;++i)
        {
            int index = getIndex(s[i]);
            if(!c[u][index]){
                return -1;
            }
            u = c[u][index];
        }
        return val[u];
    }
} trie;

int main()
{
    trie.init();
    BigInteger f1 = 1;
    BigInteger f2 = 1;
    BigInteger curF = 1;
    trie.insert(curF, 0);
    for(int i = 2;i < 100000;++i){
        curF = f1 + f2;
        trie.insert(curF, i);
        f1 = f2;
        f2 = curF;
    }
    int tc;
    cin >> tc;
    getchar();
    char s[50];
    for(int c = 1 ; c <= tc ;++c){
        cin.getline(s, 50);
        cout << "Case #" << c << ": " << trie.find(s) << endl;

    }
    return 0;
}
