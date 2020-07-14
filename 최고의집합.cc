#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    if(n>s) return {-1};
    
    vector<int> answer;
    
    int share = s/n;
    int remainder = s%n;

    for(int i=0; i<n; i++){
        answer.push_back(share);
    }
    
    for(int i=n-1; i>=0; i--){
        if(remainder-- == 0) break;
        answer[i]++;
    }
    
    return answer;
}