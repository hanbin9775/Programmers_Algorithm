#include <string>
#include <vector>

using namespace std;

bool arr[1000];

bool checkIfCandidate(int n1, int n2, int strike, int ball){
    int _strike =0;
    int _ball = 0;
    
    string str1 = to_string(n1);
    string str2 = to_string(n2);
    
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(str1[i]==str2[j]) {
                if(i==j) _strike++;
                else _ball++;
                break;
            }
        }    
    }
    
    if(strike==_strike && ball == _ball) return true;
    else return false;
    
}

int solution(vector<vector<int>> baseball) {
    int answer = 0;
    
    string temp;
    
    for(int i=102; i<=987; i++){
        temp = to_string(i);
        if(temp[0]==temp[1] || temp[0]==temp[2] || temp[1]==temp[2] || temp[1]=='0' || temp[2]=='0'){
            arr[i] = false;
        }
        else arr[i] = true;
    }
    
    int guess;
    int strike;
    int ball;
    
    for(int i=0; i<baseball.size(); i++){
        
        guess = baseball[i][0];
        strike = baseball[i][1];
        ball = baseball[i][2];
        
        for(int j=102; j<=987; j++){
            if(arr[j]==true && !checkIfCandidate(j, guess, strike, ball)){
                arr[j] = false;
            }
        }
    }
    
    for(int i=102; i<=987; i++){
        if(arr[i]==true) answer++;
    }
    
    return answer;
}