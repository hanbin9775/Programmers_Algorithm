#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    //완료까지 남은 날 저장할 vector
    vector<int> daysLeft;
    
    //input length
    int length = progresses.size();
    
    //남은 날 계산. 소수점 이하는 반올림
    for(int i=0; i<length; i++){
        daysLeft.push_back(ceil(float((100-progresses[i])/speeds[i])));
    }
    
    
    for(int i=0; i<length; i++){
        //마지막 원소일때
        if(i==length-1){
            answer.push_back(1);
            break;
        }
        for(int j=i+1; j<length; j++){
            if(daysLeft[i]<daysLeft[j]){
                answer.push_back(j-i);
                i=j-1;
                break;
            }
            if(j==length-1){
                answer.push_back(length-i);
                //루프 종료를 위한 i 초기화
                i=length;
                break;
            }
        }
    }
    
    return answer;
}