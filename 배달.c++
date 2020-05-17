#include <iostream>
#include <vector>
using namespace std;

#define INF 1000000

long long dist[51];
long long visit[51];
int vertex;
int arr[51][51];

int smallestDist(){
    int min = INF;
    int index = 0;

    for(int i=0; i<vertex;i++){
        if(!visit[i] && dist[i]<min ){
            min = dist[i];
            index = i;
        }
    }

    return index;
}

void dijkstra(int start){
    for(int i=0; i<vertex;i++){
        dist[i] = arr[start][i];
    }
    visit[start] = true;

    for(int i=0; i<vertex-2; i++){
        int cur = smallestDist();
        visit[cur] = true;
        for(int j=0; j<vertex; j++){
            if(!visit[j]){
                if(dist[cur] + arr[cur][j] < dist[j]){
                    dist[j] = dist[cur] + arr[cur][j];
                }
            }
        }
    }
}

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    vertex = N;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(i==j){
                arr[i][j] = 0;
            }
            else{
                arr[i][j] = INF;
            }
        }
    }

    for(int i=0; i<road.size(); i++){
        if(arr[road[i][0]-1][road[i][1]-1] > road[i][2]){
            arr[road[i][0]-1][road[i][1]-1] = road[i][2];
            arr[road[i][1]-1][road[i][0]-1] = road[i][2];   
        }
    }

    dijkstra(0);

    for(int i=0; i<N; i++){
        if(dist[i]<=K){
            answer+=1;
        }
    }


    return answer;
}