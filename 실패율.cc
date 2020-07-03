#include <string>
#include <vector>
#include <queue>
using namespace std;

struct comp{
  bool operator()(pair<double, int> a, pair<double, int> b){
      if(a.first == b.first) return a.second > b.second;
      return a.first < b.first;
  }
};

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    priority_queue<pair<double, int>,vector<pair<double,int>>, comp> pq;

    for(int cur_stage=1; cur_stage<=N; cur_stage++){
        double stage_fail = 0;
        double stage_arrive =0;
        for(int i=0; i< stages.size(); i++){    
            if(stages[i]>=cur_stage) stage_arrive++;
            if(stages[i]==cur_stage) stage_fail++;
        }
        if(stage_arrive==0) stage_arrive = 1;
        pq.push(make_pair((stage_fail/stage_arrive),cur_stage));
    }
    while(!pq.empty()){
        answer.push_back(pq.top().second);
        pq.pop();
    }

    return answer;
}