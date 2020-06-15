#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    
    deque<int> dq;
    int len = operations.size();
    
    char _operation;
    int _operator;
    
    for(int i=0; i<len; i++){
        _operation = operations[i][0];
        if(operations[i][2]=='-'){
            _operator = atoi(operations[i].substr(3).c_str())*(-1);            
        }
        else _operator = atoi(operations[i].substr(2).c_str());
        
        switch(_operation){
            case 'I':
                dq.push_back(_operator1);
                break;
            case 'D':
                if(!dq.empty()){
                    if(_operator==1) dq.pop_back();
                    else dq.pop_front();
                }
        }
        sort(dq.begin(), dq.end());
    }
    
    if(dq.empty()){
        answer.push_back(0);
        answer.push_back(0);
    }
    else{
        answer.push_back(dq.back());
        answer.push_back(dq.front());
    }
    return answer;
}