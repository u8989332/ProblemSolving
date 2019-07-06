#include <stdio.h>

int main()
{
    char c;
    int flag = 1;
    while((c = getchar()) != EOF)
    {
        if(c == '"'){
            if(flag) {
               printf("``");
            }
            else{
                printf("''");
            }
            flag = !flag;
        }
        else{
            printf("%c", c);
        }
    }


    return 0;
}
