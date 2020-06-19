#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int len = people.size();

    deque<int> dq;
    dq.resize(len);

    sort(people.begin(), people.end());
    copy(people.begin(), people.end(), dq.begin());

    int cur;

    while(!dq.empty()){
        cur = dq.back();
        dq.pop_back();
        if(!dq.empty()) cur+=dq.front();

        if(cur <=limit){
            answer++;
            if(!dq.empty()) dq.pop_front();
        }
        else answer++;
    }


    return answer;
}