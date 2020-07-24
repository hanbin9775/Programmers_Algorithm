#include <string>
#include <vector>

using namespace std;

int dp[1000000];
int dp2[1000000];

int solution(vector<int> money) {
    int answer = 0;

    dp[0] = money[0];
    dp[1] = money[0];

    dp2[0] = 0;
    dp2[1] = money[1];

    int size = money.size();

    for(int i=2; i<size-1; i++){
        dp[i] = max(dp[i-2]+money[i], dp[i-1]);
    }
    for(int i=2; i<size; i++){
        dp2[i] = max(dp2[i-2]+money[i], dp2[i-1]);
    }
    answer = max(dp[size-2], dp2[size-1]);
    return answer;
}