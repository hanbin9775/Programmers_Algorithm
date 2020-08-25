#include<vector>
#include <queue>

using namespace std;

int cnt[100][100];

int dir_x[4] = {0, 1,0,-1};
int dir_y[4] = {-1,0,1,0};


int solution(vector<vector<int> > maps)
{
    int answer = -1;
    int n = maps.size();
    int m = maps[0].size();

    queue<pair<int, int>> q;
    q.push(make_pair(0,0));
    cnt[0][0]=1;

    while(!q.empty()){
        int cur_x = q.front().second;
        int cur_y = q.front().first;
        q.pop();

        if(cur_y==n-1 && cur_x==m-1){
            answer = cnt[n-1][m-1];
            break;
        }

        for(int i=0; i<4; i++){
            int next_y = cur_y +dir_y[i];
            int next_x = cur_x +dir_x[i];

            if(next_y<0 || next_y>=n || next_x<0 || next_x>=m) continue;

            if((cnt[next_y][next_x]==0) && (maps[next_y][next_x]==1)){
                cnt[next_y][next_x] = cnt[cur_y][cur_x]+1;
                q.push(make_pair(next_y,next_x));
            }

        }
    }

    return answer;
}