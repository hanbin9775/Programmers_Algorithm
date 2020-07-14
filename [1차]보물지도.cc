#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    for(int i=0; i<n; i++){
        int bn = arr1[i] | arr2[i];
        string temp ="";
        for(int j=0; j<n; j++){
            if(bn%2==0) temp = " " + temp;
            else temp = "#" + temp;
            bn /= 2;
        }
        answer.push_back(temp);
    }
    return answer;
}