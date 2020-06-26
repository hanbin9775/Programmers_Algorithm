#include <string>
#include <vector>

using namespace std;

long long dp[2001];

long long getDP(int n){
    if(dp[n]!=0) return dp[n];
    return dp[n]=(getDP(n-1)+getDP(n-2))%1234567;
}

long long solution(int n) {
    long long answer = 0;
    dp[1] = 1; dp[2] = 2;
    answer = getDP(n);
    return answer;
}