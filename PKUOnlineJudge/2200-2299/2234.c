#include <stdio.h>

int main()
{
    int n, tmp, ans;
    while(scanf("%d", &n) != EOF)
    {
        ans = 0;
        while(n--)
        {
            scanf("%d", &tmp);
            ans ^= tmp;
        }
        printf("%s\n", ans ? "Yes" : "No");
    }
    return 0;
}
