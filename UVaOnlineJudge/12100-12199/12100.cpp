#include <iostream>
#include <queue>
using namespace std;

struct Job
{
    int position;
    int priority;
};

int job_priority_counts[10];
deque<Job> jobs;

int main()
{
    int cases;
    cin >> cases;
    int n;
    int target_index, t;
    int ans;
    while(cases--)
    {
        ans = 0;
        for(int i = 1 ; i <= 9;++i)
        {
            jobs.clear();
            job_priority_counts[i] = 0;
        }
        cin >> n >> target_index;
        for(int i = 0 ; i < n;++i)
        {
            cin >> t;
            job_priority_counts[t]++;
            Job j;
            j.position = i;
            j.priority = t;
            jobs.push_back(j);
        }
        int top_priority = 9;
        while(!jobs.empty())
        {
            while(job_priority_counts[top_priority] <= 0)
                top_priority--;
            Job f = jobs.front();
            if(f.priority != top_priority)
            {
                jobs.pop_front();
                jobs.push_back(f);
            }
            else{
                ans++;
                if(f.position == target_index)
                {
                    cout << ans << endl;
                    break;
                }
                jobs.pop_front();
                job_priority_counts[top_priority]--;
            }
        }
    }
    return 0;
}
