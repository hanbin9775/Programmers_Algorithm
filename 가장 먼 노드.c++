#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define INF 50001;

bool arr[20001][20001];
bool visited[20001];
int dist[20001];

int solution(int n, vector<vector<int>> edge) {
    int answer = 1;
    
    queue<int> q;
    
    for(vector<int> v : edge){
        arr[v[0]][v[1]] = true;
        arr[v[1]][v[0]] = true;
    }
    
    //dijkstra
    for(int i=1; i<=n; i++){
        if(i!=1) dist[i] = INF;
    }
    q.push(1);
    int cnt =0;
    
    while(cnt!=n){
        int cur = q.front();
        q.pop();
        if(visited[cur]) continue;
        visited[cur] =true;
        cnt++;
        
        for(int i=1; i<=n; i++){
            if(!visited[i] && arr[cur][i]){
                q.push(i);
                dist[i] = min(dist[i], dist[cur]+1);
            }
        }
    }
    
    sort(dist+1, dist+n+1);
    
    for(int i=1; i<n; i++){
        if(dist[i]==dist[n]) answer++;
    }
    
    return answer;
}