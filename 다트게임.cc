#include <string>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    int len = dartResult.length();

    int score[4];
    int nth=0;

    for(int i=0; i<len; i++){
        char tok = dartResult[i];

        if(isdigit(tok)){
            nth++;
            if(dartResult[i+1]=='0') {
                score[nth] = 10;
                i++;
            }
            else score[nth]=tok-'0';
        }
        else{
            if(tok == 'D') score[nth] *= score[nth];
            if(tok == 'T') score[nth] *= score[nth]*score[nth];
            if(tok=='*'){
                if(nth>=2) {
                    score[nth] *=2;
                    score[nth-1] *= 2;
                }
                if(nth==1) score[nth] *= 2; 
            }
            if(tok=='#') score[nth] *= -1;
        }
    }
    answer = score[1]+score[2]+score[3];
    return answer;
}