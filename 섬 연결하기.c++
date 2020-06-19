#include <string>
#include <vector>
#include <queue>
using namespace std;

int arr[100][100];
bool visited[100];

struct comp{
    bool operator()(pair<int, int> a, pair<int, int> b){ 
        return a.first > b.first;
    }  
};

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, comp> pq;

    for(vector<int> v : costs) {
        arr[v[0]][v[1]] = v[2];
        arr[v[1]][v[0]] = v[2];
    }
    //BFS
    int cur=0;
    int cnt=1;
    visited[cur] = true;
    for(int i=1; i<n; i++) {
        if(arr[0][i]!=0) pq.push(make_pair(arr[0][i],i));
    }

    while (cnt < n) {
        if (!visited[pq.top().second]) {
            cur = pq.top().second;
            answer += pq.top().first;
            visited[cur] = true;
            pq.pop();
            cnt++;
        }
        else {
            pq.pop();
            continue;
        }

        for (int i = 0; i<n; i++) {
            if (i != cur && !visited[i] && arr[cur][i] != 0) pq.push(make_pair(arr[cur][i], i));
        }
    }

    return answer;
}