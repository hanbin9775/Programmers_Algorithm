#include <string>
#include <vector>
#include <set>

using namespace std;
using namespace std;

int answer;
set<string>::iterator it;
set<set<string>> answer_set;

bool ifCandidate(string a, string b){
    if(a.length()!= b.length()) return false;
    for(int i=a.length()-1; i>=0; i--){
        if(a[i]!='*' && (a[i]!=b[i])) return false;
    }
    return true;
}

void getPossibleCase(const vector<vector<string>>& candidate, int idx, set<string> s){
    if(idx==candidate.size()){
        answer_set.insert(s);
        return;
    }

    for(int i=0; i<candidate[idx].size(); i++){
        it = s.find(candidate[idx][i]);
        if(it==s.end()){
            s.insert(candidate[idx][i]);
            getPossibleCase(candidate,idx+1,s);
            s.erase(s.find(candidate[idx][i]));
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {


    vector<vector<string>> candidate_list;
    candidate_list.resize(banned_id.size());
    set<string> s;

    for(int i=banned_id.size()-1; i>=0; i--){
        for(int j=user_id.size()-1; j>=0; j--){
            //만약 후보가 된다면
            if(ifCandidate(banned_id[i], user_id[j])){
                candidate_list[i].push_back(user_id[j]);
            }
        }
    }

    getPossibleCase(candidate_list, 0, s);


    return answer_set.size();
}
