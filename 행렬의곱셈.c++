#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    vector<int> temp;
    int height = arr1.size();
    int width = arr2[0].size();
    int loop = arr2.size();
    for(int i=0; i<height; i++){
        for(int j=0; j<width; j++){
            int num=0;
            for(int k=0; k<loop; k++) num+=arr1[i][k]*arr2[k][j];
            temp.push_back(num);
        }
        answer.push_back(temp);
        temp.clear();
    }
    return answer;
}