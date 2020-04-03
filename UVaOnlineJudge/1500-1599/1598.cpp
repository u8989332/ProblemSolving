#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>
#include <cstdio>
using namespace std;

struct Exchange
{
    int index;
    int s;
};

struct BuySell
{
    bool isBuy;
    int price;
};

priority_queue<int, vector<int>, less<int>> buy_price;
priority_queue<int, vector<int>, greater<int>> sell_price;
map<int, vector<Exchange>> buy_price_map_size;
map<int, vector<Exchange>> sell_price_map_size;
void check_top_is_empty()
{
    while(!buy_price.empty())
    {
        auto buy = buy_price_map_size.find(buy_price.top());
        if(buy == buy_price_map_size.end())
        {
            buy_price.pop();
            continue;
        }
        else if((buy->second).empty())
        {
            buy_price.pop();
            buy_price_map_size.erase(buy);
            continue;
        }
        else
        {
            break;
        }
    }

    while(!sell_price.empty())
    {
        auto sell = sell_price_map_size.find(sell_price.top());
        if(sell == sell_price_map_size.end())
        {
            sell_price.pop();
            continue;
        }
        else if((sell->second).empty())
        {
            sell_price.pop();
            sell_price_map_size.erase(sell);
            continue;
        }
        else
        {
            break;
        }
    }
}
void check_bid(char opr)
{
    check_top_is_empty();
    while(!buy_price.empty() && !sell_price.empty())
    {
        if(buy_price.top() >= sell_price.top())
        {
            auto buy = buy_price_map_size.find(buy_price.top());
            auto sell = sell_price_map_size.find(sell_price.top());
            int aud_price = opr == 'B' ? sell->first : buy->first;
            vector<Exchange>& buy_ex = buy->second;
            vector<Exchange>& sell_ex = sell->second;
            while(!buy_ex.empty() && !sell_ex.empty())
            {
                int min_s = buy_ex[0].s > sell_ex[0].s ? sell_ex[0].s : buy_ex[0].s;
                printf("TRADE %d %d\n", min_s, aud_price);
                if(min_s == buy_ex[0].s)
                {
                    buy_ex.erase(buy_ex.begin(), buy_ex.begin() + 1);
                }
                else
                {
                    buy_ex[0].s -= min_s;
                }

                if(min_s == sell_ex[0].s)
                {
                    sell_ex.erase(sell_ex.begin(), sell_ex.begin() + 1);
                }
                else
                {
                    sell_ex[0].s -= min_s;
                }
            }

            if(buy_ex.empty())
            {
                buy_price_map_size.erase(buy_price.top());
                buy_price.pop();
            }

            if(sell_ex.empty())
            {
                sell_price_map_size.erase(sell_price.top());
                sell_price.pop();
            }
        }
        else
        {
            break;
        }
    }

    check_top_is_empty();
    printf("QUOTE ");
    if(!buy_price.empty())
    {
        int sum_buy = 0;
        auto buy = buy_price_map_size.find(buy_price.top());
        vector<Exchange> buy_ex = buy->second;
        for(int i = 0 ; i < buy_ex.size(); ++i)
        {
            sum_buy += buy_ex[i].s;
        }
        printf("%d %d", sum_buy, buy_price.top());
    }
    else
    {
        printf("0 0");
    }
    printf(" - ");
    if(!sell_price.empty())
    {
        int sum_sell = 0;
        auto sell = sell_price_map_size.find(sell_price.top());
        vector<Exchange> sell_ex = sell->second;
        for(int i = 0 ; i < sell_ex.size(); ++i)
        {
            sum_sell += sell_ex[i].s;
        }
        printf("%d %d", sum_sell, sell_price.top());
    }
    else
    {
        printf("0 99999");
    }
    printf("\n");
}
int main()
{
    int N;
    int index;
    int s, price;
    bool hasFirst = false;
    char opr[100];
    while(scanf("%d", &N) == 1)
    {
        if(hasFirst)
        {
            printf("\n");
        }
        BuySell buySell[10005];
        buy_price = priority_queue<int, vector<int>, less<int>>();
        sell_price = priority_queue<int, vector<int>, greater<int>>();
        buy_price_map_size.clear();
        sell_price_map_size.clear();
        for(int i = 0 ; i < N; ++i)
        {
            scanf("%s", opr);
            if(opr[0] == 'B')
            {
                buySell[i].isBuy = true;
                scanf("%d %d", &s, &price);
                buySell[i].price = price;
                Exchange ex;
                ex.index = i;
                ex.s = s;
                auto findMap = buy_price_map_size.find(price);
                if(findMap == buy_price_map_size.end())
                {
                    buy_price.push(price);
                    buy_price_map_size[price].push_back(ex);
                }
                else
                {
                    (findMap->second).push_back(ex);
                }
                check_bid('B');
            }
            else if(opr[0] == 'S')
            {
                buySell[i].isBuy = false;
                scanf("%d %d", &s, &price);
                buySell[i].price = price;
                Exchange ex;
                ex.index = i;
                ex.s = s;

                auto findMap = sell_price_map_size.find(price);
                if(findMap == sell_price_map_size.end())
                {
                    sell_price.push(price);
                    sell_price_map_size[price].push_back(ex);
                }
                else
                {
                    (findMap->second).push_back(ex);
                }
                check_bid('S');
            }
            else
            {
                scanf("%d", &index);
                index--;
                if(buySell[index].isBuy)
                {
                    auto buy = buy_price_map_size.find(buySell[index].price);
                    if(buy != buy_price_map_size.end())
                    {
                        vector<Exchange>& exs = buy->second;
                        for(auto itr = exs.begin(); itr != exs.end(); itr++)
                        {
                            if((*itr).index == index)
                            {
                                exs.erase(itr);
                                break;
                            }
                        }
                        if(exs.empty())
                        {
                            buy_price_map_size.erase(buy);
                            if(buySell[index].price == buy_price.top())
                            {
                                buy_price.pop();
                            }
                        }
                    }
                }
                else
                {
                    auto sell = sell_price_map_size.find(buySell[index].price);
                    if(sell != sell_price_map_size.end())
                    {
                        vector<Exchange>& exs = sell->second;
                        for(auto itr = exs.begin(); itr != exs.end(); itr++)
                        {
                            if((*itr).index == index)
                            {
                                exs.erase(itr);
                                break;
                            }
                        }
                        if(exs.empty())
                        {
                            sell_price_map_size.erase(sell);
                            if(buySell[index].price == sell_price.top())
                            {
                                sell_price.pop();
                            }
                        }
                    }
                }
                check_bid(' ');
            }
        }
        hasFirst = true;
    }
    return 0;
}
