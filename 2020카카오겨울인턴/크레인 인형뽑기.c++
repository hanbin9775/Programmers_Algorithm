#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> stk;

    int cmd_len = moves.size();
    int board_len = board.size();

    int move;

    for(int i=0; i<cmd_len; i++){
        move = moves[i]-1;

        for(int j=0; j<board_len; j++){
            if(board[j][move]!=0){
                if(!stk.empty() && stk.top() == board[j][move]){
                    stk.pop();
                    answer+=2;
                }
                else{
                    stk.push(board[j][move]);
                }
                board[j][move]=0;
                break;
            }
        }
    }


    return answer;
}