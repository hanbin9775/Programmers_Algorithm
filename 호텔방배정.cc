#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<long long, long long> um;
unordered_map<long long, long long>::iterator it;


long long check(long long wanted){
    if(um[wanted]==0) return wanted;
    else {
        um[wanted] = check(um[wanted]);
        return um[wanted];
    }
}



vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;
    
    for(int i=0; i<room_number.size(); i++){
        long long wanted = room_number[i];
        long long assigned = check(wanted);
        answer.push_back(assigned);
        um[assigned] = assigned+1;
    }
    
    return answer;
}