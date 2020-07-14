#include <string>
#include <vector>

using namespace std;

#define DEFINED true

bool arr[101][101];

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    
    for(int i=0; i<results.size(); i++){
        arr[results[i][0]][results[i][1]]=DEFINED;
    }
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            for(int k=1; k<=n; k++){
                if(arr[j][i]==DEFINED && arr[i][k]==DEFINED){
                    arr[j][k] = DEFINED;
                }
            }
        }
    }
    
    for(int i=1; i<=n; i++){
        int cnt=1;
        for(int j=1; j<=n; j++){
            cnt += arr[i][j]+arr[j][i];
        }
        if(cnt == n) answer++;
    }
    
    return answer;
}