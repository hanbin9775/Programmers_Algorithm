#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;

    vector<vector<int>> v;
    vector<int> temp;
    
    int height = triangle.size();
    
    for(int i=0; i<height; i++){
        
        for(int j=0; j<=i; j++){
            temp.push_back(0);
        }
        v.push_back(temp);
        temp.clear();
    }
    
    v[0][0] = triangle[0][0];
    
    for(int i=0; i<height-1; i++){
        for(int j=0; j<=i; j++){
            v[i+1][j] = max(v[i+1][j], v[i][j] + triangle[i+1][j]);
            v[i+1][j+1] = max(v[i+1][j+1], v[i][j] + triangle[i+1][j+1]);
        }
    }
    
    sort(v[height-1].begin(),v[height-1].end());
    answer = v[height-1][height-1];
    
    return answer;
}