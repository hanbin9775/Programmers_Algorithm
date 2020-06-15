#include <string>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

#define INF 100000

int arr[51][51];


void floyd_warshall(int len){
    for(int i=0; i<len; i++){
        for(int j=0; j<len; j++){
            for(int k=0; k<len; k++){
                if((arr[j][i]!=INF) && (arr[i][k] !=INF)){
                    arr[j][k] = min(arr[j][k], arr[j][i]+arr[i][k]);
                }
            }
        }
    }
}

bool stringCompare(string a, string b){
    int cnt=0;
    for(int i=0; i<a.length(); i++){
        if(a[i]!=b[i]){
            cnt+=1;
        }
        if(cnt>1){
            return false;
        }
    }
    return true;
}

int solution(string begin, string target, vector<string> words) {
    
    int answer =10000;
    int len = words.size();
    
    for(int i=0; i<len; i++){
        for(int j=0; j<len; j++){
            if(i!=j){
                if(stringCompare(words[i],words[j])){
                    arr[i][j]=1;
                    arr[j][i] = 1;
                }
                else{
                    arr[i][j] = INF;
                }
            }
        }
    }
    
    floyd_warshall(len);
    
    int target_index;
    
    for(int i=0; i<len;i++){
        if(target==words[i]){
            target_index = i;
            break;
        }
        if(i==len-1){
            return 0;
        }
    }
    
    for(int i=0; i<len; i++){
        if(stringCompare(words[i],begin)){
            answer = min(answer, arr[i][target_index]+1);
        }
    }
    
    return answer;
}