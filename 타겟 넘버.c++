#include <string>
#include <vector>

using namespace std;

int answer;
int arr[21];

void checkEveryNumber(int cur, int index, int target, int len){

    //끝
    if(index==len-1){
        if(cur==target){
            answer+=1;
        }
        return;
    }

    checkEveryNumber(cur+arr[index+1], index+1, target, len);

    checkEveryNumber(cur-arr[index+1], index+1, target, len);

}

int solution(vector<int> numbers, int target) {

    int len = numbers.size();

    for(int i=0; i<len; i++){
        arr[i] = numbers[i];
    }

    checkEveryNumber(arr[0], 0, target ,len);
    checkEveryNumber(-arr[0], 0, target ,len);
    return answer;
}