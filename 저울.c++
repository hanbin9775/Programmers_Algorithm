#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> weight) {
    int answer = 0;
    sort(weight.begin(),weight.end());
    
    int min_m=1;
    
    for(int i=0; i<weight.size(); i++){
        if(min_m >= weight[i]) min_m += weight[i];   
        else break;
    }
    answer = min_m;
    return answer;
}