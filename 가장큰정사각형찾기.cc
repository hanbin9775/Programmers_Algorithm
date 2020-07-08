#include<vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> board)
{
    int answer = board[0][0];
    int row = board.size();
    int col = board[0].size();
    
    for(int i=1; i<row; i++){
        for(int j=1; j<col; j++){
            if(board[i][j]==0) continue;
            int min_size = min(board[i-1][j-1],min(board[i-1][j],board[i][j-1]));
            board[i][j] = min_size+1;
            answer = max(answer, board[i][j]);
        }
    }
    return answer*answer;
}