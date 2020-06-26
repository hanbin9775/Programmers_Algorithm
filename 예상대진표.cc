#include <iostream>
#include <cmath>

using namespace std;

int solution(int n, int a, int b)
{
    int cnt=1;

    while(true){
        if(abs(a-b)==1){
            if(a<b && a%2==1) break;
            else if(a>b && b%2==1) break;
        }

        if(a%2==0) a /= 2;
        else a = a/2+1;
        if(b%2==0) b /= 2;
        else b = b/2+1;
        cnt++;
    }
    return cnt;
}