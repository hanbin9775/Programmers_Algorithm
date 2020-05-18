#include <string>
#include <vector>
#include <queue>

using namespace std;

bool visited[201];
queue<int> q;

void BFS(int index, vector<vector<int>> computers){
    visited[index] = true;

    for(int i=0; i<computers.size(); i++ ){
        if(computers[index][i]==1 && i!=index && !visited[i]){
            q.push(i);
        }
    }

    while(!q.empty()){
        int node = q.front();
        q.pop();
        visited[node] = true;
        for(int i=0; i<computers.size(); i++){
            if(computers[node][i]==1 && i!=node && !visited[i]){
                q.push(i);
            }
        }
    }

}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;

    for(int i=0; i<n; i++){
        if(!visited[i]){
            BFS(i,computers);
            answer+=1;
        }
    }

    return answer;
}