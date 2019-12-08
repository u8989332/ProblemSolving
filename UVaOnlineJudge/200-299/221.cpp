#include <iostream>
#include <algorithm>
#define MAXN 120
using namespace std;

struct building{
    int id;
    double x,y,w,d,h;
    bool operator < (const building &a) const
	{
		return x < a.x || (x == a.x && y < a.y);
	}

} buildings[MAXN];

int n;
double x[MAXN * 2];

bool cover (int i, double mx)
{
	return buildings[i].x <= mx && buildings[i].x + buildings[i].w >= mx;
}


bool visible (int i, double mx)
{
	if (!cover(i, mx)) return false;
	for (int k = 0; k < n; k++)
	if (buildings[k].y < buildings[i].y && buildings[k].h >= buildings[i].h && cover(k, mx))
        return false;
	return true;
}

int main()
{
    int cases = 0;
    while(cin >> n && n){
        for(int i = 0 ;i < n;++i){
            cin >> buildings[i].x >> buildings[i].y >> buildings[i].w >> buildings[i].d >> buildings[i].h ;
            x[i * 2] = buildings[i].x;
            x[i * 2 + 1] = buildings[i].x + buildings[i].w;
            buildings[i].id = i +1;
        }

        sort(buildings, buildings + n);
        sort(x, x + 2*n);
        int m = unique(x , x + 2 *n) - x;
        if(cases++) cout << endl;
        cout << "For map #" << cases << ", the visible buildings are numbered as follows:\n";
        cout << buildings[0].id;
        for(int i = 1 ; i < n;++i) {
            bool vis = false;
            for(int j = 0; j < m - 1;++j)
            {
                if(visible(i, (x[j] + x[j + 1]) / 2)){
                    vis = true;
                    break;
                }
            }
            if(vis){
                cout << " " << buildings[i].id;
            }
        }
        cout << endl;

    }
    return 0;
}
