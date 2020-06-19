#include <string>
#include <vector>

using namespace std;

bool visited[21];

int findShortest(string name){
    int visit_cnt = 0;
    for(int i=1; i<name.length(); i++){
        if(name[i]!='A'){
            visited[i] = true;
            visit_cnt += 1;
        }
    }
    int total_move=0;

    int cur_index=0;

    while(visit_cnt>0){
        //search to right
        int r_index=cur_index;
        int r_cnt=0;
        while(visited[r_index]==false){
            if(r_index==name.length()-1){
                r_index = 0;
            }
            else{
                r_index+=1;
            }
            r_cnt+=1;
        }
        //search to left
        int l_index=cur_index;
        int l_cnt = 0;
        while(visited[l_index]==false){
            if(l_index==0){
                l_index = name.length()-1;
            }
            else{
                l_index-=1;
            }
            l_cnt+=1;
        }
        if(r_cnt>l_cnt){
            cur_index = l_index;
            total_move += l_cnt;
        }
        else{
            cur_index = r_index;
            total_move += r_cnt;
        }
        visited[cur_index] = false;
        visit_cnt-=1;
    }
    return total_move;
}

int solution(string name) {
    int answer = 0;

    int len = name.length();
    int tok;

    for(int i=0; i<len; i++){
        tok = name[i];
        if(tok<=78 ){
            answer+= tok-65;
        }
        else{
            answer += 91-tok;
        }
    }

    answer += findShortest(name);

    return answer;
}