#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>

using namespace std;

const int maxn=145;

int n, place;
double total_price;
double percent[70];
struct Player
{
    char name[25];
    bool isAmature;
    double prize;
    int RD[4];
    bool displayT;
    int total;
    int first_cut_total;
    int dq;
    int ranks;
} players[maxn];


bool cmp_first_cut(const Player &a,const Player &b)
{
    if(a.dq > -3 && b.dq > -3)
        return a.first_cut_total < b.first_cut_total;
    return a.dq > b.dq;
}

bool cmp(const Player &a,const Player &b)
{
    if(a.dq != b.dq) return a.dq > b.dq;
    if(a.total != b.total) return a.total < b.total;
    return strcmp(a.name, b.name) < 0;
}

void init(){
    memset(players,0,sizeof(players));
    scanf("%lf",&total_price);
    for(int i = 0 ; i < 70;++i)
    {
        scanf("%lf",&percent[i]);
        percent[i] = percent[i] / 100.0 * total_price;
    }

    scanf("%d\n",&n);
    char s[40];
    for(int i=0;i<n;++i){
        fgets(players[i].name, 20, stdin);
        if(strchr(players[i].name,'*')) players[i].isAmature=true;
        for(int j=0;j<4;++j){
            if(!scanf("%d",&players[i].RD[j])){players[i].dq=j-4;break;}
            if(j<2) players[i].first_cut_total+=players[i].RD[j];
            players[i].total+=players[i].RD[j];
        }
        fgets(s, 40, stdin);
    }
    return;
}

void solve(){
    sort(players, players + n, cmp_first_cut);
    place = 0;
    while(place < min(n, 70) && players[place].dq > -3)
        ++place;
    while(players[place].dq > -3 && players[place].first_cut_total == players[place-1].first_cut_total)
        ++place;

    sort(players, players + place, cmp);

    int prize_cal_index = 0;
    int rk = 0;
    int prk = 0;
    while(prize_cal_index < place)
    {
        if(players[prize_cal_index].dq)
            break;

        int sta = prize_cal_index, prerk = rk + 1, cnt = 0;
        double sum = 0;
        while(!players[sta].dq && players[prize_cal_index].total == players[sta].total){
            if(!players[sta].isAmature)
                sum += percent[prk + cnt++];
            ++rk, ++sta;
        }

        sum /= cnt;
        for(int i = prize_cal_index ; i <= sta;++i)
        {
            players[i].ranks = prerk;
            if(prk > 69)
                players[i].isAmature = true, players[i].displayT = false;
            if(!players[i].isAmature)
                players[i].prize = sum, players[i].displayT = cnt > 1;
        }

        prize_cal_index = sta -1, prize_cal_index++;
        prk += cnt;
    }
}
void print_ans(){
    printf("Player Name          Place     RD1  RD2  RD3  RD4  TOTAL     Money Won\n");
    printf("-----------------------------------------------------------------------\n");
    for(int i=0;i<place;++i){
        printf("%-21s",players[i].name);
        if(players[i].dq) printf("          ");
        else{
            char t[5];
            sprintf(t,"%d%c",players[i].ranks,players[i].displayT?'T':' ');
            printf("%-10s",t);
        }
        for(int j=-4;j<players[i].dq;++j) printf("%-5d",players[i].RD[4+j]);
        for(int j=players[i].dq;j<0;++j) printf("     ");
        if(players[i].dq) printf("%s","DQ");
        else if(!players[i].isAmature) printf("%-10d",players[i].total);
        else printf("%d",players[i].total);
        if(players[i].dq||players[i].isAmature){printf("\n");continue;}
        printf("$%9.2lf\n",players[i].prize);
    }

}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        init();
        solve();
        print_ans();
        if(T) printf("\n");
    }
    return 0;
}
