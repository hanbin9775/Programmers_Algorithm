#include <string>
#include <vector>

using namespace std;

vector<vector<int>> move1to3 = {{1,3}};

vector<vector<int>> getHanoi(int n){
    if(n==1) return move1to3;

    vector<vector<int>> result;
    vector<vector<int>> move1to2 = getHanoi(n-1);
    vector<vector<int>> move2to3 = getHanoi(n-1);

    for(int i=0; i<move1to2.size(); i++){
        if(move1to2[i][0]==3) move1to2[i][0] = 2;
        else if(move1to2[i][0]==2) move1to2[i][0] = 3;
        if(move1to2[i][1]==3) move1to2[i][1] = 2;
        else if(move1to2[i][1]==2) move1to2[i][1] = 3;
    }
    for(int i=0; i<move2to3.size(); i++){
        if(move2to3[i][0]==1) move2to3[i][0] = 2;
        else if(move2to3[i][0]==2) move2to3[i][0] = 1;
        if(move2to3[i][1]==1) move2to3[i][1] = 2;
        else if(move2to3[i][1]==2) move2to3[i][1] = 1;
    }
    for(int i=0; i<move1to2.size(); i++){
        result.push_back(move1to2[i]);
    }
    result.push_back({1,3});
    for(int i=0; i<move2to3.size(); i++){
        result.push_back(move2to3[i]);
    }
    return result;
}

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;

    answer = getHanoi(n);    

    return answer;
}