#include <vector>
#include <iostream>
using namespace std;

//소수인지 확인하는 함수
bool checkifpn(int num){
    //1은 소수 아님
    if(num==1){
        return false;
    }
    //2는 소수
    if(num==2){
        return true;
    }
    // num은 num/2보다 큰 수로 나누어 떨어지지 않음
    for(int i=2; i<num/2; i++){
        //나누어 떨어지면 소수 아님
        if(num%i==0){
            return false;
        }
    }
    return true;
}

int solution(vector<int> nums) {
    int answer = 0;

    //nums의 모든 3가지 조합의 합 검사
    for(int i=0; i<=nums.size()-3; i++){
        for(int j=i+1; j<=nums.size()-2; j++){
            for(int k=j+1; k<=nums.size()-1; k++){
                if(checkifpn(nums[i]+nums[j]+nums[k])){
                    answer+=1;    
                }
            }
        }
    }

    return answer;
}