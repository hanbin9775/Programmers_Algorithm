#include <string>
#include <vector>

using namespace std;

int dp[101][100001];

int solution(int K, vector<vector<int>> travel) {
    int answer = 0;
    
    for(int i=1; i<=travel.size(); i++){
        for(int j=1; j<=K; j++){
            if(j>=travel[i-1][0] && i==1){
                dp[i][j] = max(dp[i][j], travel[i-1][1]+dp[i-1][j-travel[i-1][0]]);
            }
            else if(j>=travel[i-1][0] && dp[i-1][j-travel[i-1][0]]!=0){
                dp[i][j] = max(dp[i][j], travel[i-1][1]+dp[i-1][j-travel[i-1][0]]);
            }
            if(j>=travel[i-1][2] && i==1){
                dp[i][j] = max(dp[i][j], travel[i-1][3]+dp[i-1][j-travel[i-1][2]]);
            } 
            else if(j>=travel[i-1][2] && dp[i-1][j-travel[i-1][2]]!=0){
                dp[i][j] = max(dp[i][j], travel[i-1][3]+dp[i-1][j-travel[i-1][2]]);
            } 
        }
    }
    return dp[travel.size()][K];
}