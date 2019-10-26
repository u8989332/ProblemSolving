#include <stdio.h>

char disks[7][6500];
int d, s, b;
char parity;
int parity_bit;

int validation()
{
    int i, j,k;
    int full_s = s * b;
    int cur_bit;
    int error_bit;
    for(i = 0 ; i < full_s;++i)
    {
        cur_bit = 0;
        error_bit = -1;
        for(j = 0 ; j < d;++j)
        {
            if(disks[j][i] == 'x')
            {
                if(error_bit != -1) return 0;

                error_bit = j;
            }
            else
            {
                cur_bit ^= (disks[j][i] - '0');
            }
        }

        if(error_bit != -1)
        {
            disks[error_bit][i] = parity_bit == cur_bit ? '0' : '1';
        }
        else
        {
            if(cur_bit != parity_bit) return 0;
        }
    }
    return 1;
}


void print_disk_value()
{
    int i,j,k,m;
    int counts = 3;
    int nums[4];
    int col;

    int sum = 0 , cnt = 0;
    for(i = 0; i < b;++i)
    {
        col = i * s;
        for(j = 0 ; j < d;++j)
        {
            if(j == (i%d))
                continue;


            for(k = col, m = 0 ; m < s;++m, ++k)
            {
                sum <<= 1; sum += disks[j][k] == '1'; cnt++;
				if (cnt == 4)
				{
				    printf("%X", sum);
					sum = 0; cnt = 0;
				}
            }
        }
    }
    if (cnt) printf("%X", sum << (4 - cnt));
    printf("\n");

}

int main()
{
    int i;
    int cases = 1;
    while(scanf("%d", &d) != EOF && d)
    {
        scanf("%d %d", &s, &b);
        scanf(" %c", &parity);
        parity_bit = parity == 'E' ? 0 : 1;
        for(i = 0 ; i  < d;++i)
        {
            scanf("%s", disks[i]);
        }

        if(validation())
        {
            printf("Disk set %d is valid, contents are: ", cases);
            print_disk_value();

        }
        else
        {
            printf("Disk set %d is invalid.\n",cases);
        }

        cases++;
    }
    return 0;
}
