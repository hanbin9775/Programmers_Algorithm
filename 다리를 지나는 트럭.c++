#include <string>
#include <vector>
#include <stack>

using namespace std;


int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;

    //현재 다리 위에 올라와 있는 트럭의 총 무게
    int on_bridge_weight = 0;

    int truck_len = truck_weights.size();

    //다리 벡터
    vector<int> v;
    for(int i=0; i<bridge_length;i++){
        v.push_back(0);
    }

    //트럭 순서 스택
    stack<int> stk;
    for(int i=0; i<truck_len;i++){
        stk.push(truck_weights.back());
        truck_weights.pop_back();
    }


    //총과한 버스 수
    int passed_truck=0;

    while(passed_truck<truck_len){

        //버스 다리 위에서 이동
        if(v.back()!=0){
            passed_truck+=1;
            on_bridge_weight-= v.back();
        }
        v.pop_back();
        v.insert(v.begin(),0);

        //새로운 버스 
        if(!stk.empty() && weight>=on_bridge_weight+stk.top()){
            v[0] = stk.top();
            on_bridge_weight += stk.top();
            stk.pop();
        }

        //1루프 = 1초 흐름
        answer+=1;
    }




    return answer;
}