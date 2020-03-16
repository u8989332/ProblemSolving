#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

map<string, string> titleToAuthor;
struct ReturnBook{
    string title;
    string author;
};
bool cmp(string b1, string b2)
{
    string a1 = titleToAuthor[b1];
    string a2 = titleToAuthor[b2];
    if(a1 != a2)
    {
        return a1 < a2;
    }
    return b1 < b2;
}

bool cmp_return(ReturnBook b1, ReturnBook b2)
{
    if(b1.author != b2.author)
    {
        return b1.author < b2.author;
    }
    return b1.title < b2.title;
}
int main()
{
    string s;

    vector<string> shelve;
    vector<ReturnBook> returnBooks;
    while(getline(cin, s))
    {
        if(s == "END")
        {
            break;
        }
        else
        {
            int index = s.find("\" by");
            string title = s.substr(0, index + 1);
            string author = s.substr(index + 4);
            titleToAuthor[title] = author;
            shelve.push_back(title);
        }
    }

    sort(shelve.begin(), shelve.end(), cmp);

    while(getline(cin, s))
    {
        if(s == "END")
        {
            break;
        }
        else if(s == "SHELVE")
        {
            sort(returnBooks.begin(), returnBooks.end(), cmp_return);
            for(int i = 0 ; i < returnBooks.size();++i)
            {
                auto it = lower_bound(shelve.begin(), shelve.end(), returnBooks[i].title, cmp);
                if(it == shelve.begin())
                {
                    cout << "Put " << returnBooks[i].title << " first" << endl;
                }
                else
                {
                    int lastIndex = it - shelve.begin() - 1;
                    cout << "Put " << returnBooks[i].title << " after " << shelve[lastIndex] << endl;
                }
                shelve.insert(it, returnBooks[i].title);
            }
            returnBooks.clear();
            cout << "END" << endl;
        }
        else
        {
            int index = s.find("\"");
            string title = s.substr(index);
            if(s[0] == 'B')
            {
                auto borrowedBook = lower_bound(shelve.begin(), shelve.end(), title, cmp);
                shelve.erase(borrowedBook);
            }
            else
            {
                ReturnBook book;
                book.author = titleToAuthor[title];
                book.title = title;
                returnBooks.push_back(book);
            }
        }
    }
    return 0;
}
