#include <string>
#include <vector>

using namespace std;

void hanoi(int n, int from, int to, vector<vector<int>>& answer){
    if(n==0) return;
    
    int mid=0;
    for(int i=1; i<=3; i++){
        if(i!=to && i!=from) mid = i;
    }
    
    hanoi(n-1, from, mid, answer);
    answer.push_back({from, to});
    hanoi(n-1, mid, to, answer);
}

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    hanoi(n, 1,3, answer);
    return answer;
}