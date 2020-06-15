#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string,int> m;
    map<string,int>::iterator it;

    for(int i=0; i<clothes.size(); i++){

        it = m.find(clothes[i][1]);
        //없으면
        if(it == m.end()){
            m.insert(make_pair(clothes[i][1],1));
        }
        //있으면
        else{
            it->second += 1;    
        }

    }


    for(auto it = m.begin(); it!=m.end(); it++){
        answer *= it->second +1;
    }

    answer -= 1;

    return answer;
}