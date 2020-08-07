#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> gems) {
    unordered_map<string,int> range;
    unordered_map<string,int>::iterator it;

    for(int i=gems.size()-1; i>=0; i--){
        if(range.find(gems[i])==range.end()) {
            range.insert(make_pair(gems[i],0));
        }
    }

    int start=0, end=0;
    int ans_s=0, ans_e=gems.size()-1;

    range.find(gems[end])->second +=1;

    while(end<gems.size()){
        bool fullfill = true;
        for(auto it = range.begin(); it != range.end(); it++){
            if(it->second==0){
                end++;
                if(end<gems.size()) range.find(gems[end])->second +=1;
                fullfill = false;
                break;
            }
        }
        if(fullfill){
            if(end-start< ans_e-ans_s){
                ans_e = end;
                ans_s = start;
            }
            range.find(gems[start])->second -=1;
            start++;
        }
    }

    return {ans_s+1, ans_e+1};
}