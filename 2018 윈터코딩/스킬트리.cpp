#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    int st_cnt;
    bool wrongst;

    for(int i=0; i<skill_trees.size(); i++){

        st_cnt=0;
        wrongst = false;

        for(int j=0; j<skill_trees[i].length(); j++){

            //잘못된 스킬트리임을 인지
            if(wrongst){
                break;
            }

            //스킬 순서대로 배웠을 때 cnt++
            if(skill_trees[i][j]==skill[st_cnt]){
                st_cnt++;
            }
            //앞서 배웠을 때 잘못된 스킬트리라고 알림
            for(int k=st_cnt+1; k<skill.length(); k++){
                if(skill[k]==skill_trees[i][j]){
                    wrongst = true;
                    break;
                }
            }


        }
        //잘못된 스킬트리가 아니라면
        if(!wrongst){
            answer++;
        }

    }

    return answer;
}
