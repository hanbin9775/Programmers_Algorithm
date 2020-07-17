#include <string>
#include <vector>

using namespace std;

int answer;

void getNQueen(int n, int idx, vector<int> v){
    if(n==idx) {answer++; return;}

    for(int i=0; i<n; i++){
        bool ifPossible = true;
        for(int j=0; j<idx; j++){
            if( v[j]==i || abs(j-idx)==abs(i-v[j])){
                ifPossible = false;
                break;
            }
        }
        if(ifPossible){
            v[idx] = i; 
            getNQueen(n, idx+1, v);
        } 
    }
}

int solution(int n) {
    vector<int> v;
    v.resize(n);
    getNQueen(n,0,v);
    return answer;
}