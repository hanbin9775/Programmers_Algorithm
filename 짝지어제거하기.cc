#include <iostream>
#include<string>
#include <stack>
using namespace std;

int solution(string s)
{
    stack<char> stk;
    int len = s.length();
    for(int i=0; i<len; i++){
        if(stk.empty()) stk.push(s[i]);
        else if(stk.top()==s[i]) stk.pop();
        else stk.push(s[i]);
    }
    if(stk.empty()) return 1;
    else return 0;
}