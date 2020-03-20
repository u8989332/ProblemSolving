#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

struct MyMap{
    double x1, y1, x2, y2;
    double area;
    string name;
};

struct MyLocation{
    double x, y;
};

bool cmp(MyMap m1, MyMap m2)
{
    return m1.area > m2.area;
}

map<string, MyMap> areas;
map<string, MyLocation> locations;
int main()
{
    string s1, s2, s3, t;
    getline(cin, t);
    while(getline(cin, s1))
    {
        if(s1 == "LOCATIONS")
        {
            break;
        }

        stringstream ss(s1);
        string name;
        double x1, y1, x2, y2;
        ss >> name >> x1 >> y1 >> x2 >> y2;
        MyMap m;
        if(x1 > x2)
        {
            swap(x1, x2);
            swap(y1, y2);
        }
        m.x1 = x1;
        m.x2 = x2;
        m.y1 = y1;
        m.y2 = y2;
        m.name = name;
        m.area = abs(x2 - x1) * abs(y2 - y1);
        areas[name] = m;
    }

    while(getline(cin, s2))
    {
        if(s2 == "REQUESTS")
        {
            break;
        }

        stringstream ss(s2);
        string name;
        double x, y;
        ss >> name >> x >> y;
        MyLocation m;
        m.x = x;
        m.y = y;
        locations[name] = m;
    }

    while(getline(cin, s3))
    {
        if(s3 == "END")
        {
            break;
        }

        stringstream ss(s3);
        string name;
        int level;
        ss >> name >> level;
        cout << name << " at detail level " << level;
        auto findLoc = locations.find(name);
        if(findLoc == locations.end()){
            cout << " unknown location" << endl;
        }
        else
        {
            MyLocation curL = findLoc->second;
            vector<MyMap> curList;
            for(auto it = areas.begin(); it != areas.end();++it)
            {
                MyMap curMap = it->second;
                if( (curMap.x1 <= curL.x && curMap.x2 >= curL.x
                   && curMap.y1 <= curL.y && curMap.y2 >= curL.y) ||
                    (curMap.x1 <= curL.x && curMap.x2 >= curL.x
                   && curMap.y2 <= curL.y && curMap.y1 >= curL.y))

               {
                   curList.push_back(curMap);
               }
            }
            if(curList.size() == 0)
            {
                cout << " no map contains that location" << endl;
            }
            else{
                sort(curList.begin(), curList.end(), cmp);
                if(curList.size() < level)
                {
                    cout << " no map at that detail level; using " << curList[curList.size()-1].name << endl;
                }
                else{
                    cout << " using " << curList[level-1].name << endl;
                }
            }
        }
    }
    return 0;
}
