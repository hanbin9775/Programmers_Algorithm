#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> temp;

    int len = commands.size();

    int cmd1;
    int cmd2;
    int cmd3;

    for(int i=0; i<len; i++){

        cmd1 = commands[i][0];
        cmd2 = commands[i][1];
        cmd3 = commands[i][2];

        for(int i=cmd1-1;i<cmd2; i++ ){
            temp.push_back(array[i]);
        }

        sort(temp.begin(), temp.end());

        answer.push_back(temp[cmd3-1]);

        while(!temp.empty()){
            temp.pop_back();
        }
    }

    return answer;
}