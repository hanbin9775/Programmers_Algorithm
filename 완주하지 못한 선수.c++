#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";

    sort(participant.begin(),participant.end());
    sort(completion.begin(),completion.end());

    int index=0;

    while(1){

        if(participant[index]==completion[index]){
            index+=1;    
        }
        else{
            answer = participant[index];
            break;
        }

        if(index==participant.size()-1){
            answer = participant[index];
            break;
        }
    }



    return answer;
}
