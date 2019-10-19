#include <stdio.h>
#include <string.h>

int find_bit1_mask;
int change_bit[32];
int prev_bit[32];
int mask[32];
int min_ip[32];
int get_decimal(int *m)
{
   int i;
   int base = 1;
   int sum = 0;
   for(i = 0 ; i < 8;++i)
   {
       if(*m == 1)
       {
           sum += base;
       }
       base <<= 1;
       m++;
   }

   return sum;
}

int main()
{
    int i,j,k, n;
    char s[20];
    int n1[4];
    int start_change;
    int base, bit;
    int curIndex;
    while(scanf("%d", &n) != EOF)
    {
        start_change = 0;
        memset(change_bit, 0, sizeof(change_bit));
        memset(prev_bit, -1, sizeof(prev_bit));
        memset(mask, 1, sizeof(mask));
        memset(min_ip, 1, sizeof(min_ip));
        for(i = 0 ; i < n;++i)
        {
            scanf("%s", s);
            sscanf(s, "%d.%d.%d.%d", &n1[3], &n1[2], &n1[1], &n1[0]);
            for(j = 0 ; j < 4;++j)
            {
                base = 1;
                for(k = 0 ; k < 8;++k)
                {
                    bit = n1[j] & base;
                    curIndex = j * 8 + k;
                    if(prev_bit[curIndex] == -1)
                    {
                        prev_bit[curIndex] = bit;
                    }
                    else if(prev_bit[curIndex] != bit)
                    {
                        change_bit[curIndex] = 1;
                    }
                    base <<= 1;
                }
            }
        }

        for(j = 3 ; j >= 0;--j)
        {
            base = (1 << 7);
            for(k = 7 ; k >= 0;--k)
            {
                curIndex = j * 8 + k;
                if(change_bit[curIndex])
                {
                    start_change = 1;
                }

                if(start_change)
                {
                    min_ip[curIndex] = 0;
                    mask[curIndex] = 0;
                }
                else
                {
                    mask[curIndex] = 1;
                    min_ip[curIndex] = (n1[j] & base) > 0 ? 1 : 0;
                }

                base >>= 1;
            }
        }

        printf("%d.%d.%d.%d\n", get_decimal(min_ip+24), get_decimal(min_ip+16), get_decimal(min_ip+8), get_decimal(min_ip));
        printf("%d.%d.%d.%d\n", get_decimal(mask+24), get_decimal(mask+16), get_decimal(mask+8), get_decimal(mask));
    }
    return 0;
}
