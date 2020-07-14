#include <string>
#include <vector>
#include <cmath>

using namespace std;

bool notPrime[1000001];

int solution(int n) {
    int answer = 0;

    for(int i=2; i<n; i++){
        if(notPrime[i]) continue;
        for(int j=i+i; j<=n; j+=i)
            notPrime[j] = true;
    }

    for(int i=2; i<=n; i++)
        if(!notPrime[i]) answer++;

    return answer;
}