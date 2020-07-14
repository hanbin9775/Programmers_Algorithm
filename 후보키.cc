#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<vector<int>> subsets;

bool comp(vector<int> a, vector<int> b){
    return a.size() < b.size();
}

bool ifCandkey(vector<int> v, const vector<vector<string>> &relation){
    set<vector<string>> s;
    set<vector<string>>::iterator it;
    vector<string> temp;
    for(int i=0; i<relation.size(); i++){
        for(int j=0; j<v.size(); j++){
            temp.push_back(relation[i][v[j]]);   
        }
        it = s.find(temp);
        if(it==s.end()) s.insert(temp);
        else return false;
        temp.clear();
    }
    return true;
}

void impl_subset(vector<int> v, int cnt,int n){
    if(cnt==n){
        subsets.push_back(v);
        return;
    }
    impl_subset(v,cnt+1, n);
    v.push_back(cnt);
    impl_subset(v,cnt+1, n);
}

bool isIncluded(vector<int> a, vector<int> b){
    for(int i=0; i<a.size(); i++){
        bool check = false;
        for(int j=0; j<b.size(); j++){
            if(a[i]==b[j]) {
                check =true;
                break;
            }
        }
        if(!check) return false;
    }
    return true;
}

int solution(vector<vector<string>> relation) {
    int answer = 0;
    int col = relation[0].size();
    vector<int> v;
    impl_subset(v, 0, col);
    sort(subsets.begin(), subsets.end(),comp);

    for(int i=1; i<subsets.size(); i++){
        if(ifCandkey(subsets[i],relation)){
            answer++;
            //후보키를 포함하는 부분집합 제외
            for(int j=i+1; j<subsets.size(); j++){    
                if(isIncluded(subsets[i],subsets[j])){
                    subsets.erase(subsets.begin()+j);
                    j--;
                }
            }
        }
    }

    return answer;
}