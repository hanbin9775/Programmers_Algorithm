#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<string> answer;
bool finished;



int ticket_num;

void DFS(vector<string> v, map<string, vector<string>> m) {


    if (finished) {
        return;
    }

    if (ticket_num + 1 == v.size()) {
        answer.resize(v.size());
        copy(v.begin(), v.end(), answer.begin());
        finished = true;
        return;
    }

    string cur = v.back();

    for (int i = 0; i<m[cur].size(); i++) {
        string temp = m[cur][i]; 
        v.push_back(temp);
        m[cur].erase(m[cur].begin() + i);
        DFS(v, m);
        m[cur].push_back(temp);
        sort(m[cur].begin(), m[cur].end());
        v.pop_back();
    }


}

vector<string> solution(vector<vector<string>> tickets) {

    map<string, vector<string>> m;
    map<string, vector<string>>::iterator it;

    ticket_num = tickets.size();
    vector<string> temp;

    for (int i = 0; i<ticket_num; i++) {
        it = m.find(tickets[i][0]);

        if (it == m.end()) {
            temp.push_back(tickets[i][1]);
            m.insert(make_pair(tickets[i][0], temp));
            temp.pop_back();
        }
        else {
            (it->second).push_back(tickets[i][1]);
            sort((it->second).begin(), (it->second).end());
        }
    }

    vector<string> start;
    start.push_back("ICN");

    DFS(start, m);

    return answer;
}