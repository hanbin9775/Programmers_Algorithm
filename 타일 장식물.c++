#include <string>
#include <vector>

using namespace std;

long long dp[81];

long long getNth(int n){
    if(n==0){
        return 0;
    }
    if(dp[n]!=0){
        return dp[n];
    }
    else{
        return dp[n]= getNth(n-1) + getNth(n-2);
    }
}

long long solution(int N) {
    long long answer = 0;
    
    dp[1] = 1;
    dp[2] = 1;
    
    answer = 2*(2*getNth(N)+ getNth(N-1));
    
    return answer;
}