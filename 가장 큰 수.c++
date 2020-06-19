#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(const string &a, const string &b){
    
    return a+b > b+a;
    
}


string solution(vector<int> numbers) {
    string answer = "";
    
    vector<string> num_toString;
    
    for(int i=0; i<numbers.size(); i++){
        num_toString.push_back(to_string(numbers[i]));    
    }
    
    sort(num_toString.begin(), num_toString.end(), compare);
    
    if(num_toString[0]=="0"){
        return "0";
    }
    
    for(int i=0; i<num_toString.size(); i++){
        answer += num_toString[i];
    }
    
    return answer;
}