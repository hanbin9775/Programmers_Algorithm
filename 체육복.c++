#include <string>
#include <vector>

using namespace std;

int arr[32];

int solution(int n, vector<int> lost, vector<int> reserve) {

    int answer = 0;

    for(int i : lost) arr[i] -=1;
    for(int i : reserve) arr[i] +=1;

    for(int i=1;i<=n; i++){
        if(arr[i]==-1){
            if(arr[i-1]==1)
                arr[i-1]=arr[i]=0;
            else if(arr[i+1]==1)
                arr[i+1]=arr[i]=0;
            else{
                answer++;
            }
        }
    }

    answer = n-answer;
    return answer;
}