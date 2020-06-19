#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    int cnt_l=0, cnt_r=0;
    for(int i=0; i<s.length(); i++){
        switch(s[i]){
            case '(':
                cnt_l++; break;
            case ')':
                cnt_r++; break;
        }
        if(cnt_l<cnt_r) return false;
    }
    if(cnt_l!=cnt_r) return false;
    else return true;
}