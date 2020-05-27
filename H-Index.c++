#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int solution(vector<int> citations) {
    int answer = 0;

    sort(citations.begin(), citations.end());

    int len = citations.size();

    for(int i=0; i<len; i++){

        if(citations[i] <= len-i){
            answer = citations[i];
        }
        else{
            answer = max(answer, len-i);
            break;
        }

    }

    return answer;
}