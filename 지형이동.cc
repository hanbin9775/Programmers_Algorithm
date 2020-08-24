#include <string>
#include <vector>
#include <queue>

using namespace std;

bool visited[300][300];

int dir_x[4] = {0,1,0,-1};
int dir_y[4] = {-1,0,1,0};

int solution(vector<vector<int>> land, int height) {
    int answer = 0;

    int n = land.size();
    int cnt=0;
    //(h_diff, (y,x))
    priority_queue<pair<int,pair<int,int>>> pq;
    pq.push(make_pair(0, make_pair(0,0)));

    while(cnt<n*n){
        int cur_x = pq.top().second.second;
        int cur_y = pq.top().second.first;
        int diff_h = -1* pq.top().first;
        pq.pop();

        if(!visited[cur_y][cur_x]){
            visited[cur_y][cur_x]= true;
            cnt++;
            if(diff_h>height){
                answer += diff_h;
            }
            if(cnt==n*n) break;
        }
        else{
            continue;
        }

        for(int i=0; i<4; i++){
            int next_x = cur_x + dir_x[i];
            int next_y = cur_y + dir_y[i];

            if(next_x<0 || next_x>=n || next_y<0 || next_y>=n) continue;

            if(!visited[next_y][next_x]){
                pq.push(make_pair(-1*abs(land[cur_y][cur_x]-land[next_y][next_x])  ,make_pair(next_y,next_x)));
            }

        }


    }

    return answer;
}