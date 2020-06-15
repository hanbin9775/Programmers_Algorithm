#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

bool comp(pair<int,int> a, pair<int, int> b){
    return a.second > b.second;
}

vector<int> solution(string s) {
    vector<int> answer;

    int str_len=s.length();

    map<int,int> m;
    int digit_cnt=0;
    int digit_start;
    int element;
    for(int i=0; i<str_len; i++){

        //int detected
        if(isdigit(s[i])){
            //숫자 첫 시작
            if(digit_cnt==0){
                digit_start=i;
            }
            digit_cnt+=1;
        }
        else if(digit_cnt!=0 && !isdigit(s[i])){
            element = atoi(s.substr(digit_start,digit_cnt).c_str());
            map<int,int>::iterator it;
            it = m.find(element);
            if(it != m.end()){
                it->second +=1;
            }
            else{
            m.insert(make_pair(element,1));    
            }
            digit_cnt=0;
        }

    }

    vector<pair<int,int>> v;
    copy(m.begin(), m.end(),back_inserter<vector<pair<int,int>>>(v));

    sort(v.begin(), v.end(), comp);

    for(int i=0; i<v.size(); i++){
        answer.push_back(v[i].first);
    }

    return answer;
}