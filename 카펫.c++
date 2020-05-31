#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    int total = brown+yellow;
    
    for(int i =3; i<=sqrt(total); i++){
        if(total%i==0 && (total/i-2)*(i-2)==yellow){
            answer.push_back(total/i);
            answer.push_back(i);
        } 
    }
    
    return answer;
}