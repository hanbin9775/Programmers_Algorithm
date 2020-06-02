#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(vector<int> a, vector<int> b){ return a[0] < b[0];}

int solution(vector<vector<int>> routes) {
    int answer = 1;
    sort(routes.begin(), routes.end(), compare);
    int min_end = routes[0][1];
    for(int i=1; i<routes.size(); i++){
        if(min_end >= routes[i][0]) min_end = min(min_end, routes[i][1]);
        else{
            answer++;
            min_end = routes[i][1];
        }
    }
    return answer;
}