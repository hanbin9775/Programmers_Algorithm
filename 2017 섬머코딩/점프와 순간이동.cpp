#include <iostream>
using namespace std;

int solution(int n)
{
    int ans = 0;
    //거꾸로 생각하기. 순간이동은 비용이 들지 않으므로 순간이동에 우선순위를 둠.
    while(n > 0) {
        if(n%2 == 0) n/=2;
        else {
            n-=1;
            ans+=1;
        }
    }

    return ans;
}