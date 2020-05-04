#include <string>
#include <vector>
using namespace std;


vector<int> solution(vector<int> prices) {
    vector<int> answer;

    for(int i=0; i<prices.size()-1; i++){
        //비교할 주식가격
        int cmpNum = prices[i];
        //떨어지지 않는 기간 카운트
        int cnt=0;
        for(int j=i+1; j<prices.size(); j++){
            if(prices[j]>=cmpNum){
                cnt+=1;                                    
            }
            //떨어졌을때, 떨어져도 1만큼의 간격이 있으므로 더해준다.
            else if(prices[j]<cmpNum){
                answer.push_back(cnt+1);
                break;
            }
            //배열 끝까지 비교했을 떄
            if(j==prices.size()-1){
                answer.push_back(cnt);
            }
        }
    }
    //마지막 주식은 떨어질 수 없으므로 0
    answer.push_back(0);  
    return answer;
}