#include <iostream>
#include <vector>
#include <queue>
using namespace std;

queue<int> q;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;


    for(int i=0; i<stations.size(); i++){
        q.push(stations[i]-w);
    }

    int index=1;

    while(index<=n){
        if(q.empty() || index < q.front() ){
            index += 2*w+1;
            answer+=1;
        }
        else if(index >= q.front()){
            index = q.front()+2*w+1;
            q.pop();
        }
    }

    return answer;
}