#include <string>
#include <vector>
using namespace std;

int getLCM(int a, int b){
    int gcd=0;
    for(int i=2; i<=a && i<=b; i++)
        if(a%i==0 && b%i==0) gcd = i;
    if(gcd!=0) return a * b / gcd;
    else return a*b;
}

int solution(vector<int> arr) {
    int answer = arr[0];
    for(int i=1; i<arr.size(); i++)
        answer = getLCM(answer, arr[i]);
    return answer;
}