#include <iostream>
#include <vector>
using namespace std;

int dp[100000];
int dp2[100000];

int solution(vector<int> sticker)
{
    int answer = 36;

    int size = sticker.size();
    if(size==1) return sticker[0];

    dp[0] = sticker[0];
    dp[1] = sticker[0];

    dp2[0] = 0;
    dp2[1] = sticker[1];

    for(int i=2; i<size-1; i++){
        dp[i] = max(dp[i-1], dp[i-2]+sticker[i]);
    }
    for(int i=2; i<size; i++){
        dp2[i] = max(dp2[i-1], dp2[i-2]+sticker[i]);
    }

    answer = max(dp[size-2], dp2[size-1]);

    return answer;
}