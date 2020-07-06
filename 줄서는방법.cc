#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool used[20];

vector<int> solution(int n, long long k) {
    vector<int> people;
    long long toDivide;
    long long share = k-1; 
    int counter =n;
    while(counter-->0){
        toDivide = 1;
        for(int i=1; i<n; i++){
            toDivide *= (long long)i;
        }
        long long cnt = share/toDivide;
        int idx=0;
        while(cnt>=0){
            if(!used[idx]) cnt--;
            idx++;
        }
        people.push_back(idx);
        used[idx-1] = true;
        n--;
        share = share % toDivide;
    }

    return people;
}