#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool subtractNumandCheck(vector<int> stones, int num, int k){
    for(int i=stones.size()-1; i>=0; i--){
        stones[i] -= num;
    }
    int cnt_0=0;
    for(int i=stones.size()-1; i>=0; i--){
        if(stones[i]<=0) cnt_0++;
        else cnt_0=0;

        if(cnt_0>=k) return false;
    }
    return true;
}

int solution(vector<int> stones, int k) {
    int answer = 0;

    vector<int> v = stones;

    sort(v.begin(), v.end());


    int start=v[0];
    int end = v[v.size()-1];

    while(start<end){
        int mid = (start+end)/2;


        if(subtractNumandCheck(stones,mid,k)){
            start=mid+1;
        }
        else{
            end = mid;
        }
    }

    answer =start;

    return answer;
}