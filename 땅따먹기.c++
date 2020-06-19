#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[100000][4];

int solution(vector<vector<int> > land)
{
    for(int i=0; i<4; i++){
        dp[0][i]=land[0][i];
    }
    int len = land.size();
    for(int i=1; i<len; i++){
        dp[i][0] = max(dp[i-1][1], max(dp[i-1][2],dp[i-1][3]))+land[i][0];
        dp[i][1] = max(dp[i-1][0], max(dp[i-1][2],dp[i-1][3]))+land[i][1];
        dp[i][2] = max(dp[i-1][0], max(dp[i-1][1],dp[i-1][3]))+land[i][2];
        dp[i][3] = max(dp[i-1][0], max(dp[i-1][1],dp[i-1][2]))+land[i][3];
    }
    return max(dp[len-1][0],max(dp[len-1][1], max(dp[len-1][2],dp[len-1][3])));
}