#include <string>
#include <vector>

using namespace std;

bool checkIfBalanced(string s){
    int l=0;
    int r=0;
    for(int i=0; i<s.length(); i++){
        switch(s[i]){
            case '(':
                l++; break;
            case ')':
                r++; break;
        }
        if(l<r) return false;
    }
    return true;
}

string step4_4(string s){
    s = s.substr(1,s.length()-2);

    for(int i=0; i<s.length(); i++){
        if(s[i]=='(') s[i]=')';
        else s[i]='(';
    }
    return s;
}

string startConvert(string s){
    string temp="";
    int l=0; int r=0;
    string u, v;
    for(int i=0; i<s.length(); i++){
        switch(s[i]){
            case '(':
                l++; break;
            case ')':
                r++; break;
        }
        if(l==r){
            u = s.substr(0,i+1);
            v = s.substr(i+1);
            if(checkIfBalanced(u)) {
                temp += u;
                temp += startConvert(v); 
                return temp;
            }
            else{
                temp += "(";
                temp += startConvert(v);
                temp += ")";
                temp += step4_4(u);
                return temp;
            }
        }
    }
}

string solution(string p) {
    return startConvert(p);
}