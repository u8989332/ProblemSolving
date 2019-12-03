#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>

using namespace std;

void split_addr(const string& str, string& name, string& country)
{
    int i = str.find("@");
    name = str.substr(0, i);
    country = str.substr(i+1);
}
map<string, set<string>> countryMapFullEmail;
vector<string> countrySeq;
map<string, vector<string>> countryMapRecvName;
set<string> checkRecvRepeat;
int main()
{

    string mta;
    string country, name;
    int n;
    string send_address;
    string recv_address;
    string msgs[1000];
    int msg_index = 0;
    string send_name, send_country;
    string recv_name, recv_country;
    while(cin >> mta && mta != "*")
    {
        cin >> country;
        cin >> n;
        for(int i = 0 ; i < n;++i)
        {
            cin >> name;
            countryMapFullEmail[country].insert(name + "@" + country);
        }
    }

    while(cin >> send_address && send_address != "*")
    {
        checkRecvRepeat.clear();
        countrySeq.clear();
        countryMapRecvName.clear();
        msg_index = 0;

        split_addr(send_address, send_name, send_country);
        while(cin >> recv_address && recv_address != "*")
        {
            if(checkRecvRepeat.find(recv_address) != checkRecvRepeat.end())
                continue;

            checkRecvRepeat.insert(recv_address);
            split_addr(recv_address, recv_name, recv_country);
            if(!countryMapRecvName.count(recv_country))
            {
                countrySeq.push_back(recv_country);
                vector<string> newRecvList;
                countryMapRecvName[recv_country] = newRecvList;
            }
            countryMapRecvName[recv_country].push_back(recv_address);
        }

        getchar();
        while(getline(cin, msgs[msg_index]))
        {
            if(msgs[msg_index] == "*")
            {
                break;
            }
            msg_index++;
        }
        for(int k = 0 ; k < countrySeq.size();++k)
        {
            cout << "Connection between " << send_country << " and ";
            cout << countrySeq[k] << endl;
            cout << "     HELO " << send_country << endl;
            cout << "     250" << endl;
            cout << "     MAIL FROM:<" << send_address << ">" << endl;
            cout << "     250" << endl;
            vector<string> recvNames = countryMapRecvName[countrySeq[k]];
            int okCount = 0;
            for(int i = 0 ; i < recvNames.size();++i)
            {
                cout << "     RCPT TO:<" << recvNames[i] << ">" << endl;
                if(countryMapFullEmail[countrySeq[k]].count(recvNames[i]))
                {
                    cout << "     250" << endl;
                    okCount++;
                }
                else
                {
                    cout << "     550" << endl;
                }
            }
            if(okCount)
            {
                cout << "     DATA" << endl;
                cout << "     354" << endl;
                for(int j = 0 ; j < msg_index;++j)
                {
                    cout << "     " << msgs[j] << endl;
                }
                cout << "     ." << endl;
                cout << "     250" << endl;
            }
            cout << "     QUIT" << endl;
            cout << "     221" << endl;
        }
    }
    return 0;
}
