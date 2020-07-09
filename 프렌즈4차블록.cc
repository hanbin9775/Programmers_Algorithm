#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(int m, int n, vector<string> board) {
    int answer =0;
    set<pair<int,int>> s;
    set<pair<int,int>>::iterator it;
    vector<string> new_board;

    for(int j=0; j<n; j++){
        string temp = "";
        for(int i=m-1; i>=0; i--){
            temp = temp + board[i][j];
        }
        new_board.push_back(temp);
    }
    bool erasable = true;
    while(erasable){
        erasable = false;
        for(int i=0; i<n-1; i++){
            for(int j=0; j<m-1; j++){
                if(new_board[i][j]!='X'&& new_board[i][j]==new_board[i][j+1]
                  && new_board[i][j+1]==new_board[i+1][j]
                  && new_board[i+1][j]==new_board[i+1][j+1]){
                    s.insert(make_pair(i,j));
                    s.insert(make_pair(i+1,j));
                    s.insert(make_pair(i,j+1));
                    s.insert(make_pair(i+1,j+1));
                    erasable = true;
                }
            }
        }
        for(it = s.begin(); it!=s.end(); it++){
            new_board[it->first][it->second] = '0';
            answer++;
        }
        s.clear();
        for(int i=0; i<n; i++){
            int cnt=0;
            for(int j=0; j<m; j++){
                if(new_board[i][j]=='0'){
                    new_board[i].erase(new_board[i].begin()+j);
                    new_board[i] = new_board[i]+'X';
                    j--;
                }
            }
        }
    }

    return answer;
}