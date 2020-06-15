#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<long long,vector<long long>,greater<long long>> pq (scoville.begin(), scoville.end());

    while(pq.top()<K){
        
        if(pq.size()<2){
            return -1;
        }
        int least = pq.top();
        pq.pop();
        pq.push(least + pq.top()*2);
        pq.pop();
        answer++;
    }
    
    return answer;
}