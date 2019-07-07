#include <stdio.h>
#include <string.h>
char table[200];
int main()
{
    table['A'] = 'A';
    table['B'] = ' ';
    table['C'] = ' ';
    table['D'] = ' ';
    table['E'] = '3';
    table['F'] = ' ';
    table['G'] = ' ';
    table['H'] = 'H';
    table['I'] = 'I';
    table['J'] = 'L';
    table['K'] = ' ';
    table['L'] = 'J';
    table['M'] = 'M';
    table['N'] = ' ';
    table['O'] = 'O';
    table['P'] = ' ';
    table['Q'] = ' ';
    table['R'] = ' ';
    table['S'] = '2';
    table['T'] = 'T';
    table['U'] = 'U';
    table['V'] = 'V';
    table['W'] = 'W';
    table['X'] = 'X';
    table['Y'] = 'Y';
    table['Z'] = '5';

    table['1'] = '1';
    table['2'] = 'S';
    table['3'] = 'E';
    table['4'] = ' ';
    table['5'] = 'Z';
    table['6'] = ' ';
    table['7'] = ' ';
    table['8'] = '8';
    table['9'] = '9';

    char s[1000];
    int i, len, mid;
    int isMirror, isSame;
    while(scanf("%s", s) != EOF)
    {
        isMirror = 1;
        isSame = 1;
        len = strlen(s);
        mid = len / 2;
        for(i = 0 ;i <= mid;++i)
        {
            if(s[i] != table[s[len - i - 1]])
            {
                isMirror = 0;
            }

            if(s[i] != s[len - i - 1])
            {
                isSame = 0;
            }
        }

        if(isMirror && isSame)
        {
            printf("%s -- is a mirrored palindrome.\n\n", s);
        }
        else if(isMirror)
        {
            printf("%s -- is a mirrored string.\n\n", s);
        }
        else if(isSame)
        {
            printf("%s -- is a regular palindrome.\n\n", s);
        }
        else
        {
            printf("%s -- is not a palindrome.\n\n", s);
        }
    }
    return 0;
}
