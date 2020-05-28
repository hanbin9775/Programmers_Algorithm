#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

bool fasterRequest(vector<int> a, vector<int> b){
    return a[0] < b[0];
}

struct shorterRequest{
    bool operator()(pair<int, int> a, pair<int, int> b){
        return a.second > b.second;
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, shorterRequest> pq;
    
    sort(jobs.begin(), jobs.end(), fasterRequest);
        
    int job_index=0;
    int cur=jobs[0][0]; 
    int avg_waiting=0;
    
    while(true){
        
        for(int i= job_index; i<jobs.size(); i++){
            if(jobs[i][0] <= cur){
                pq.push(make_pair(jobs[i][0], jobs[i][1]));
                job_index=i+1;
            }
            else if(!pq.empty()){
                break;
            }
            else{
                pq.push(make_pair(jobs[i][0], jobs[i][1]));
                cur = jobs[i][0];
                job_index=i+1;
                break;
            }
        }
        
        if(pq.empty()){
            break;
        }
        
        avg_waiting += pq.top().second + cur - pq.top().first;
        cur += pq.top().second;
        pq.pop();
    }
    
    answer = avg_waiting/jobs.size();
    
    return answer;
}