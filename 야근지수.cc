#include <string>
#include <vector>
#include <queue>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    priority_queue<int> pq;

    int len = works.size(); 
    for(int i=0; i<len; i++)
        pq.push(works[i]);

    int temp;
    while(n-->0){
        if(pq.top()>0){
            temp = pq.top();
            pq.pop();
            pq.push(temp-1);
        }
    }

    while(!pq.empty()){
        answer += (long long)pq.top() * (long long)pq.top();
        pq.pop();
    }

    return answer;
}