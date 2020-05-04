#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;

    //몇번째 사람인지 확인
    int pindex=1;
    //몇번째 턴인지 확인
    int turn =1;

    for(int i=0; i<words.size(); i++){
        //이전에 나온 단어인지 확인 (이게 다음 단어 비교하는 것보다 빠르므로 이것부터 검사해야한다.)))
        for(int j=0; j<i; j++){
            if(words[i]==words[j]){
                answer.push_back(pindex);
                answer.push_back(turn);
                return answer;
            }
        }
        //마지막 글자와 그 다음 단어의 첫번째 글자 비교
        if(i!=words.size()-1 && (words[i][words[i].size()-1]!=words[i+1][0]) ){
            //그 다음 단어와 비교한 것이므로 그 다음 단어에 해당하는 사람과 차례를 push 해줌
            pindex++;
            if(pindex>n){
                pindex=1;
                turn+=1;
            }
            answer.push_back(pindex);
            answer.push_back(turn);
            return answer;
        }

        pindex++;
        if(pindex>n){
            pindex=1;
            turn+=1;
        }
    }
    answer.push_back(0);
    answer.push_back(0);
    return answer;
}