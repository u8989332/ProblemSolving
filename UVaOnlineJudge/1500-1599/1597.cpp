#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <algorithm>
#include <map>
#include <cstring>
using namespace std;

typedef bool lines[1505];

string texts[1505];
map<string, lines> word_to_lines;
int text_size[101];

void debug_print(int n){
    for(int i = 0 ; i < n;++i)
    {
        for(int j = 0 ; j < text_size[i];++j)
        {
            cout << texts[i][j] << endl;
        }
    }
}
int main()
{
    int n;
    int m;
    int lines = 0;
    int all_lines_num = 0;
    string temp;

    cin >> n;
    getchar();
    text_size[0] = 0;
    for(int c = 0 ; c < n;++c)
    {
        while(getline(cin, temp))
        {
            if(temp == "**********")
            {
                break;
            }
            texts[all_lines_num] = temp;
            for(int k = 0 ; k < temp.length();++k)
            {
                if(isalpha(temp[k]))
                {
                    temp[k] = tolower(temp[k]);
                }
                else
                {
                    temp[k] = ' ';
                }
            }
            stringstream ss(temp);
            string temp2;
            while(ss >> temp2)
            {
                if(temp2.length() > 0)
                {
                    word_to_lines[temp2][all_lines_num] = true;
                }
            }
            all_lines_num++;

        }
        text_size[c + 1] = all_lines_num;
    }

    cin >> m;
    getchar();
    for(int q = 0 ; q < m;++q)
    {
        getline(cin, temp);
        bool should_print_texts[1505];
        memset(should_print_texts, false, sizeof(should_print_texts));

        bool has_print = false;
        if(temp.find(" AND ") != string::npos)
        {
            stringstream ss(temp);
            string s1, t, s2;
            ss >> s1 >> t >> s2;
            auto s1_lines = word_to_lines[s1];
            auto s2_lines = word_to_lines[s2];
            for(int i = 0 ; i < n;++i)
            {
                bool in_this_text_1 = false;
                bool in_this_text_2 = false;
                for(int j = text_size[i]; j < text_size[i + 1];++j)
                {
                    if(s1_lines[j]){
                        in_this_text_1 = true;
                    }
                    if(s2_lines[j]){
                        in_this_text_2 = true;
                    }

                    if(in_this_text_1 && in_this_text_2)
                        break;
                }
                if(in_this_text_1 && in_this_text_2){
                    for(int j = text_size[i]; j < text_size[i + 1];++j)
                    {
                        if(s1_lines[j] || s2_lines[j]){
                            should_print_texts[j] = true;
                            has_print = true;
                        }
                    }
                }
            }
        }
        else if(temp.find(" OR ") != string::npos)
        {
            stringstream ss(temp);
            string s1, t, s2;
            ss >> s1 >> t >> s2;
            auto s1_lines = word_to_lines[s1];
            auto s2_lines = word_to_lines[s2];
            for(int i = 0 ; i < n;++i)
            {
                for(int j = text_size[i]; j < text_size[i + 1];++j)
                {
                    if(s1_lines[j] || s2_lines[j]){
                        should_print_texts[j] = true;
                        has_print = true;
                    }
                }
            }
        }
        else if(temp.find("NOT ") != string::npos)
        {
            auto s_lines = word_to_lines[temp.substr(4)];
            for(int i = 0 ; i < n;++i)
            {
                bool in_this_text = false;
                for(int j = text_size[i]; j < text_size[i + 1];++j)
                {
                    if(s_lines[j]){
                        in_this_text = true;
                        break;
                    }
                }

                if(!in_this_text)
                {
                    for(int j = text_size[i]; j < text_size[i + 1];++j)
                    {
                        should_print_texts[j] = true;
                        has_print = true;
                    }
                }
            }
        }
        else
        {
            auto s_lines = word_to_lines[temp];
            for(int i = 0 ; i < all_lines_num; ++i)
            {
                if(s_lines[i])
                {
                    should_print_texts[i] = true;
                    has_print = true;
                }
            }
        }

        if(has_print)
        {
            bool firstOk = false;
            bool has_print_this_text = false;
            for(int i = 0 ; i < n;++i)
            {
                bool this_text_should_print = false;
                for(int j = text_size[i]; j < text_size[i + 1];++j)
                {
                    if(should_print_texts[j]){
                        if(firstOk)
                        {
                            cout << "----------" << endl;
                            firstOk = false;
                        }
                        has_print_this_text = true;
                        cout << texts[j] << endl;
                    }
                }
                if(has_print_this_text)
                {
                    firstOk = true;
                }
            }
        }
        else
        {
            cout << "Sorry, I found nothing." << endl;
        }
        cout << "==========" << endl;
    }
    return 0;
}
