#include <string>
#include <vector>

using namespace std;

int dp[2001][2001];

int getDP(int l, int r,const vector<int>&left, const vector<int>&right){

    if(l==left.size() || r==right.size()) return 0;

    if(dp[l][r]!=0) return dp[l][r];

    if(left[l]> right[r]){
        int curAns = getDP(l,r+1,left,right)+ right[r];
        dp[l][r] =curAns;
        return curAns;
    }
    else{
        int curAns = max(getDP(l+1,r+1,left,right), getDP(l+1,r,left,right));
        dp[l][r] = curAns;
        return curAns;
    }
}

int solution(vector<int> left, vector<int> right) {
    return getDP(0,0,left,right);
}