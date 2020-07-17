#include <string>
using namespace std;
int solution(string s)
{
    int answer=1;
    int len = s.length();

    for(int i=0; i<len; i++){
        char tok1 = s[i];
        for(int j=i+1; j<len; j++){
            char tok2 = s[j];
            if(tok1==tok2){
                bool isPal = true;
                for(int k=i+1; k<=(j+i)/2; k++){
                    if(s[k]!=s[j+i-k]){
                        isPal = false;
                        break;
                    }
                }
                if(isPal) answer = max(answer, j-i+1);
            }
        }
        if(answer> len-i+1) break;
    }
    return answer;
}