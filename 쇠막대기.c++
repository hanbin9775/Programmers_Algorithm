#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(string arrangement) {
    int answer = 0;

    int len = arrangement.length();

    stack<int> stk;
    char tok;

    for(int i=0; i<len; i++){
        tok = arrangement[i];


        //철근 끝
        if(tok==')'){
            stk.pop();
            answer+=1;
        }
        //laser일 때
        else if(tok=='(' && arrangement[i+1]==')' ){
            answer+= stk.size();
            i+=1;
        }
        //철근 시작 : (
        else if(tok=='('){
            stk.push(1);
        }


    }


    return answer;
}