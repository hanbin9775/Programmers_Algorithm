#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;

    unordered_map<string, int> dict;
    unordered_map<string, int>::iterator it;
    string temp;
    for (char ch = 'A'; ch <= 'Z'; ch++) {
        temp += ch;
        dict.insert(make_pair(temp, ch - 64));
        temp = "";
    }

    int cur = 0;
    int len = msg.length();
    int dict_cnt = 26;

    while (cur < len) {
        int cnt = 1;
        it = dict.find(msg.substr(cur, cnt));
        while (it != dict.end()) {
            cnt++;
            it = dict.find(msg.substr(cur, cnt));
            if (cnt + cur > len) break;
        }
        answer.push_back(dict.find(msg.substr(cur, cnt - 1))->second);
        dict.insert(make_pair(msg.substr(cur, cnt), ++dict_cnt));
        cur += cnt - 1;
    }

    return answer;
}