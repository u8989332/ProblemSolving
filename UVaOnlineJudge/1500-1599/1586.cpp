#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
using namespace std;

double scores[200];

int main()
{
    scores['C'] = 12.01;
    scores['H'] = 1.008;
    scores['O'] = 16.00;
    scores['N'] = 14.01;
    int n;
    int i,j;
    int curNum;
    int len;;
    double sum = 0;
    string s;
    cin >> n;

    while(n--)
    {
        sum = 0;
        cin >> s;
        len = s.length();
        for(i = 0 ;i < len;)
        {
            if(!isdigit(s[i]))
            {
                if(i + 1 < len && !isdigit(s[i+1]))
                {
                    sum += scores[s[i]];
                    i++;
                }
                else if(i + 1 < len && isdigit(s[i+1]))
                {
                    for(j = i + 1; j < len && isdigit(s[j]);++j)
                        ;

                    curNum = stoi(s.substr(i+1, j - (i+1)));
                    sum += curNum * scores[s[i]];
                    i = j;
                }
                else
                {
                    sum += scores[s[i]];
                    i++;
                }
            }
        }

        cout << fixed << setprecision(3) << sum  << endl;
    }

    return 0;
}
