#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> score;
    score.resize(3);
    int first_pick[5] = {1,2,3,4,5};
    int second_pick[8] = {2,1,2,3,2,4,2,5};
    int third_pick[10] = {3,3,1,1,2,2,4,4,5,5};
    for(int i=0; i<answers.size(); i++){
        if(answers[i] == first_pick[i%5]) score[0]++;
        if(answers[i] == second_pick[i%8]) score[1]++;
        if(answers[i] == third_pick[i%10]) score[2]++;
    }
    int highestScore = max(score[0], max(score[1],score[2]));
    for(int i=0; i< score.size(); i++){
        if(highestScore==score[i]) answer.push_back(i+1);
    }
    return answer;
}