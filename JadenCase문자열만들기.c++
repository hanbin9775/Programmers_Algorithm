#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int len = s.length();
    int cur=0;
    while(cur<len){
        if(!isdigit(s[cur]) && islower(s[cur])) s[cur] = toupper(s[cur]);
        int space = s.find(' ',cur);
        if(space == string::npos) {
            for(int i=cur+1; i<len; i++)
                if(!isdigit(s[i]) && isupper(s[i])) s[i] = tolower(s[i]);
            break;
        }
        else {
            for(int i=cur+1; i<space; i++)
                if(!isdigit(s[i]) && isupper(s[i])) s[i] = tolower(s[i]);
            cur = space +1;
        }
    }
    answer = s;
    return answer;
}