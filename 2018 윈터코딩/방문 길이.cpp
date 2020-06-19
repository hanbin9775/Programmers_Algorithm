#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//경계 검사
bool checklimit(int n){
    if(n>5 || n<-5)
        return false;
    else
        return true;
}
//중복 제거, 다음부턴 중복 제거할 때는 set 자료구조를 사용하도록 하자..
int eraseOverlaps(vector <pair<pair<int,int>,pair<int,int>>> dir_v){
    int answer;
    sort(dir_v.begin(),dir_v.end());
    dir_v.erase(unique(dir_v.begin(),dir_v.end()),dir_v.end());
    answer= dir_v.size();
    //방향은 다르지만 선분은 같은 것 검사
    for(int i=0; i<dir_v.size()-1; i++){
        for(int j=i+1; j<dir_v.size(); j++){
            if(dir_v[i].first==dir_v[j].second && dir_v[i].second == dir_v[j].first){
                answer-=1;
            }
        }
    }
    return answer;
}

int solution(string dirs)
{
    vector <pair<pair<int,int>,pair<int,int>>> dir_v;
    
	int answer = 0;
    
    int cx=0;
    int cy=0;
    
    //지나간 길 벡터에 입력
    for(int i=0; i<dirs.size(); i++){
        char dir_c;
        dir_c = dirs[i];
        switch(dir_c){
            case 'U':
                if(checklimit(cy+1)){
                    dir_v.push_back(make_pair(make_pair(cx,cy),make_pair(cx,cy+1)));
                    cy+=1;
                }
                break;
            case 'D':
                if(checklimit(cy-1)){
                    dir_v.push_back(make_pair(make_pair(cx,cy),make_pair(cx,cy-1)));
                    cy-=1;
                }
                break;
            case 'R':
                if(checklimit(cx+1)){
                    dir_v.push_back(make_pair(make_pair(cx,cy),make_pair(cx+1,cy)));
                    cx+=1;
                }
                break;
            case 'L':
                if(checklimit(cx-1)){
                    dir_v.push_back(make_pair(make_pair(cx,cy),make_pair(cx-1,cy)));
                    cx-=1;
                }
                break;     
        }
    }
    answer = eraseOverlaps(dir_v);
	return answer;
}