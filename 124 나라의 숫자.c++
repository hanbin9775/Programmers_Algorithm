#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(int n) {
    string answer = "";

    vector<int> v;

    while(n>0){
        v.push_back(n%3);
        n /= 3;
    }

    reverse(v.begin(), v.end());

    for(int i=v.size()-1; i>0; i--){
        if(v[i]==0){
            v[i-1] -= 1;
            v[i] = 4;
        }
        else if(v[i] == -1){
            v[i-1] -= 1;
            v[i] = 2;
        }
    }
    if(v[0]==0) v.erase(v.begin());

    for(int i=0; i<v.size(); i++){
        answer += to_string(v[i]);
    }

    return answer;
}