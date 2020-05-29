#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

bool isPrime(int n){
    if(n==1 || n==0) return false;
    for(int i=2; i<=sqrt(n); i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}

int solution(string numbers) {
    int answer = 0;
        
    string token;
    int len = numbers.length();
    
    set<int> s;
    
    sort(numbers.begin(), numbers.end());
    
    int temp;
    do{
        for(int i=1; i<=len; i++){
            temp =0;
            token = numbers.substr(0,i);
            for(int j=0; j<i; j++){
                temp *=10;
                temp += token[j]-'0';
            }
            if(isPrime(temp)){
                s.insert(temp);
            }
        } 
    }while(next_permutation(numbers.begin(), numbers.end()));
    
    answer = s.size();
    
    return answer;
}