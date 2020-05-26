#include <string>
#include <vector>

using namespace std;

int dp[101][101];

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;

    for(int i=0; i<puddles.size(); i++){
        dp[puddles[i][1]][puddles[i][0]] = -1;
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(i==1 && j==1){
                dp[i][j] = 1;
            }
            else if(dp[i][j]!=-1){
                if(i>0 && dp[i-1][j]!=-1){
                    dp[i][j] += dp[i-1][j];
                }
                if(j>0 && dp[i][j-1]!=-1){
                    dp[i][j] += dp[i][j-1];
                }
                dp[i][j] %= 1000000007; 
            }    

        }
    }

    answer = dp[n][m];

    return answer;
}