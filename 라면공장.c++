#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
    int answer = 0;

    priority_queue<int> pq;
    
    int date_index=0;
    
    while(stock<k){
        
        while(dates[date_index] <= stock){
            pq.push(supplies[date_index]);
            date_index++;            
        }
        
        stock+= pq.top();
        pq.pop();
        answer+=1;
    }
    
    return answer;
}