#include <string>
#include <vector>

using namespace std;

int dp[100001];

int getDP(int n){
    if(n==0) return 0;
    if(dp[n]!=0) return dp[n];    
    return dp[n]=(getDP(n-1)+getDP(n-2))%1234567;
}

int solution(int n) {
    dp[0] = 0;
    dp[1] = 1;
    return getDP(n);
}