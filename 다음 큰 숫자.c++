#include <string>
#include <vector>

using namespace std;

vector<int> b;

int binary1Cnt(int num){
    int cnt=0;
    while(num>0){
        if(num%2==1) cnt++;
        b.push_back(num%2);
        num /=2;
    }
    return cnt;
}

int solution(int n) {
    int answer = 0;
    int cnt = binary1Cnt(n);
    int num_of_1 = cnt;
    do{
        b[0]++; n++;
        for(int i=0; i<b.size(); i++){
            if(b[i]==1) {
                num_of_1++;
                break;
            }
            else if(b[i]==2 && i<b.size()-1) {
                b[i]=0;
                b[i+1]++;
                num_of_1--;
            }
            else if(i==b.size()-1){
                b[i]=0;
                b.push_back(1);
                break;
            }
        }
    }while(num_of_1 != cnt);
    answer = n;
    return answer;
}