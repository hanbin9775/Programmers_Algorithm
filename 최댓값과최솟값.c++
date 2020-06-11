#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    vector<int> v;
    int len = s.length();
    int cur=0;
    while(cur<len){
        if(s[cur]=='-') v.push_back( (-1)*stoi(s.substr(cur+1,s.find(' ',cur)-cur-1)));
        else v.push_back(stoi(s.substr(cur,s.find(' ',cur)-cur)));
        cur = s.find(' ',cur)+1;
        if(cur==0)break;
    }
    sort(v.begin(), v.end());
    answer = to_string(v[0]) +' '+ to_string(v[v.size()-1]);
    return answer;
}