#include <iostream>
#include <cstdio>
#define MAXN 150005

using namespace std;

int ranks[MAXN];
int pre[MAXN];

void init(int n)
{
    for(int i = 0 ; i < n; ++i)
    {
        pre[i] = i;
        ranks[i] = 0;
    }
}

int findl(int x)
{
    if(pre[x] == x)
    {
        return x;
    }
    else
    {
        return pre[x] = findl(pre[x]);
    }
}

void unite(int x, int y)
{
    x = findl(x);
    y = findl(y);

    if(x == y)
    {
        return;
    }

    if(ranks[x] < ranks[y])
    {
        pre[x] = y;
    }
    else
    {
        pre[y] = x;
        if(ranks[x] == ranks[y])
        {
            ranks[x]++;
        }
    }
}

bool same(int x, int y)
{
    return findl(x) == findl(y);
}

int main()
{
    int N, K;
    int D, X, Y;
    scanf("%d %d", &N, &K);
    int ans = 0;
    init(N * 3);
    for(int i = 0 ; i < K; ++i)
    {
        scanf("%d %d %d", &D, &X, &Y);
        X = X - 1;
        Y = Y - 1;

        if(X < 0 || X >= N || Y < 0 || Y >= N)
        {
            ans++;
            continue;
        }

        if(D == 1)
        {
            if(same(X, Y + N) || same(X, Y + 2 * N))
            {
                ans++;
            }
            else
            {
                unite(X, Y);
                unite(X + N, Y + N);
                unite(X + 2 * N, Y + 2 * N);
            }
        }
        else if(D == 2)
        {
            if(same(X, Y) || same(X, Y + 2 * N))
            {
                ans++;
            }
            else
            {
                unite(X, Y + N);
                unite(X + N, Y + N * 2);
                unite(X + 2 * N, Y);
            }
        }
    }

    printf("%d\n", ans);
    return 0;
}