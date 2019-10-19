#include <stdio.h>


char s1[7];
char s2[7];

int cmp()
{
    int i;
    for(i = 0 ; i < 6;++i)
    {
        if(s1[i] != s2[i])
        {
            return 0;
        }
    }

    return 1;
}

void swap(int i1, int i2)
{
    char temp = s1[i1];
    s1[i1] = s1[i2];
    s1[i2] = temp;
}

void rotate_180()
{
    swap(0, 2);
    swap(2, 3);
    swap(2, 5);
}

void rotate_right()
{
    swap(1, 3);
    swap(1, 2);
    swap(2, 4);
}

void rotate_up()
{
    swap(0, 1);
    swap(1, 4);
    swap(1, 5);
}

void printftest()
{
    printf("1 = %s\n2 = %s\n\n",s1, s2);
}

int main()
{
    int i,j, ok;
    char s[13];
    while(scanf("%s", s) != EOF)
    {
        ok = 0;
        for(i = 0, j = 6; i < 6;++i, ++j)
        {
            s1[i] = s[i];
            s2[i] = s[j];
        }

        for(i = 0 ; i < 4;++i)
        {
            for(j = 0; j < 4;++j)
            {
                if(cmp())
                {
                    ok = 1;
                    break;
                }
                rotate_right();
            }
            if(ok)
            {
                break;
            }
            rotate_up();
        }

        if(!ok)
        {
            rotate_180();
            for(i = 0 ; i < 4;++i)
            {
                for(j = 0; j < 4;++j)
                {
                    if(cmp())
                    {
                        ok = 1;
                        break;
                    }
                    rotate_right();
                }
                if(ok)
                {
                    break;
                }
                rotate_up();
            }
        }

        if(ok)
        {
            printf("TRUE\n");
        }
        else
        {
            printf("FALSE\n");
        }

    }
    return 0;
}
