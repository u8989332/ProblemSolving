#include <iostream>
#include <vector>
#include <map>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
const int INF = 0x3f3f3f3f;

// 每一個請求的處理時間為t，而t_queues是從第1筆開始，
// 到最後的1筆的時間點，
// 以範例測資第1筆，ID 128的請求的t_queues = [0, 10, 20, 30, ...., 190]
struct Topic{
    int t;
    queue<int> t_queues;
};

// 每一位客服有id、他下次可以工作的起始時間ok_time、他現在工作的起始時間start_time,
// n種可處理的請求。可處理的請求ID存在topic_ids。
// 使用operator<是排序當前時間點可以做工的人，先從最早的工作起始時間，若有相同再以ID最小的。
struct Person{
    int id, ok_time, start_time, n;
    int topic_ids[22];
    bool operator< (const Person& other){
        if(start_time != other.start_time)
            return start_time < other.start_time;
        return id < other.id;
    }
};

// 客服請求的對應, key是id
map<int, Topic> requests_queue;

// N是請求種類數, M是客服數
int N,M,r,rtid;
int tid, num, td, t, dt, sid;

int main()
{
    int sc = 1;

    /*
    紀錄最大的處理時間點
    */
    int needtime = -1;

    /*
    把這變數想成從0秒開始不斷累加1做檢查的進階版時間戳記，它不斷更新每M位客服處理的起始時間點，下次就從這時間點往後檢查。
    */
    int time = INF;
    while(cin >> N && N){

        for(int i = 0 ; i < N;++i)
        {
            Topic curT;
            cin >> tid >> num >> td >> t >> dt;
			// time取最小的第1筆請求的時間點
            time = min(time, td);
            Topic topic;
            topic.t = t;
            auto &now(requests_queue[tid] = topic);
            for(int j = 0; j < num;++j)
            {
                now.t_queues.push(td);
                td += dt;
            }
        }

        cin >> M;
        vector<Person> service_man(M);
		for (int i = 0;i < M;++i) {
            Person p;
            p.start_time = 0;
            p.ok_time = 0;
            cin >> p.id >> p.n;
			for (int j=0;j < p.n;++j)
				cin >> p.topic_ids[j];
			service_man[i] = p;
		}

        while(N){
            /*
             在這M位客服，紀錄最早的可工作時間點
            */
            int fullNextTime = INF;

            /*
            依照operator< 排序
            */
            sort(service_man.begin(), service_man.end());
            for(int i = 0 ; i < M;++i)
            {
                Person& curP = service_man[i];

                /*
                該客服的下次可工作時間點
                */
                int cur_person_earliest_ok_time = INF;

                // 代表他現在還在忙
                if(curP.ok_time > time){
                    cur_person_earliest_ok_time = curP.ok_time;
                }
                else{
                    // 每種請求
                    for(int j = 0 ; j < curP.n;++j){
                        Topic& curT = requests_queue[curP.topic_ids[j]];
                        // 已經處理完的換下一個
                        if(curT.t_queues.empty()){
                            continue;
                        }

                        // 代表這請求能被這位客服處理
                        if(curT.t_queues.front() <= time) {
                            // 這位客服下個有空的時間點是處理完這請求以後
                            cur_person_earliest_ok_time = time + curT.t;

                            // 更新最後的處理時間
                            if(needtime < cur_person_earliest_ok_time){
                                needtime = cur_person_earliest_ok_time;
                            }

                            // 這位客服開始工作的時間點
                            curP.start_time = time;

                            // 將這筆請求移除
                            curT.t_queues.pop();
                            // 空了就代表這種請求都完成，種類再減1
                            if(curT.t_queues.empty()){
                                N--;
                            }

                            // 現在這位客服在工作，換下一位客服
                            break;
                        }
                        // 現在這時間點還不到這請求可處理的時間點，就看此客服下次可處理的時間點是不是能更早
                        else if(curT.t_queues.front() < cur_person_earliest_ok_time){
                            cur_person_earliest_ok_time = curT.t_queues.front();
                        }
                    }
                    // 所有請求都看過，計算他下次能工作的時間點
                    curP.ok_time = cur_person_earliest_ok_time;
                }
                // 更新所有客服最早可處理的時間點
                fullNextTime = min(fullNextTime, cur_person_earliest_ok_time);
            }
            // 下次就從這時間點開始檢查，因為至少有人有空
            time = fullNextTime;
        }

        cout << "Scenario " << sc++ << ": All requests are serviced within " << needtime << " minutes." << endl;

        requests_queue.clear();
        service_man.clear();
        time = INF;
        needtime = -1;
    }
    return 0;
}
