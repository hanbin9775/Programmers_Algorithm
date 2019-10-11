#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    
    //가장 큰 숫자의 index. 이게 정해지면 다음 index부터 검색하면 된다.
    int maxindex=0;
    //루프 몇 번 도는가에 대한 cnt.
    int loopcnt = number.length()-k;
    
    //가장 큰 수를 검색할 범위
    int start, end;
    // number에서 검색할 수 있는 남은 길이. 범위를 계산하기 위해 설정한다.
    int remainlength = number.length();
    
    while(loopcnt>0){
        int maxnum =0;
        //가장 큰 수를 검색할 범위를 설정한다.
        start = maxindex;
        end = start+remainlength-loopcnt;
        
        for(int i=start; i<=end; i++){
            if(maxnum<number[i]-'0'){
                maxnum = number[i]- '0';
                maxindex = i;
            }
        }
        
        remainlength = number.length() - maxindex-1;
        
        answer.append(to_string(maxnum));
        
        loopcnt--;
        maxindex+=1;
    }
    
    return answer;
}