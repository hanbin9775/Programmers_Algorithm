#include <string>
#include <vector>
#include <map>

using namespace std;


const string enter = "님이 들어왔습니다.";
const string leave = "님이 나갔습니다.";

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, string> id_m;
    vector<pair<int, string>> log;

    string cmd;
    string id;
    string nick;

    for (int i = 0; i < record.size(); i++) {
        int space = record[i].find(' ');
        cmd = record[i].substr(0, space);
        if (cmd == "Leave") id = record[i].substr(space+1);
        else {
            id = record[i].substr(space+1, record[i].find(' ', space+1)-space-1);
            nick = record[i].substr(record[i].find(' ', space + 1)+1);
        }

        if (cmd == "Enter") {
            if (id_m.find(id)==id_m.end()) {
                id_m.insert(make_pair(id, nick));
            }
            else {
                id_m.find(id)->second = nick;
            }
            log.push_back(make_pair(0, id));
        }
        else if (cmd == "Leave") {
            log.push_back(make_pair(1, id));
        }
        else if (cmd == "Change") {
            id_m.find(id)->second = nick;
        }
    }

    for (int i = 0; i < log.size(); i++) {
        switch (log[i].first) {
            case 0:
                answer.push_back(id_m.find(log[i].second)->second + enter);
                break;
            case 1:
                answer.push_back(id_m.find(log[i].second)->second + leave);
                break;
        }
    }

    return answer;
}