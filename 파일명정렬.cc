#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int stringToint(string a){
    int result = 0;
    for(int i=0; i<a.length(); i++){
        result *= 10;
        result += a[i]-'0';
    }
    return result;
}

bool comp(string a, string b){
    
    int a_head_end;
    bool head_flag = true;
    int a_num_end;
    
    for(int i=0; i<a.length(); i++){
        if(isdigit(a[i]) && head_flag) {
            a_head_end = i;
            head_flag = false;
        }
        if(!head_flag && !isdigit(a[i])){
            a_num_end = i;
            break;
        }
    }
    string a_head = a.substr(0, a_head_end);
    transform(a_head.begin(), a_head.end(), a_head.begin(), ::tolower);
    string a_num_s = a.substr(a_head_end, min(5,a_num_end-a_head_end));
    int a_num = stringToint(a_num_s);
    
    int b_head_end;
    head_flag = true;
    int b_num_end;
    
    for(int i=0; i<b.length(); i++){
        if(isdigit(b[i]) && head_flag) {
            b_head_end = i;
            head_flag = false;
        }
        if(!head_flag && !isdigit(b[i])){
            b_num_end = i;
            break;
        }
    }
    
    string b_head = b.substr(0, b_head_end);
    transform(b_head.begin(), b_head.end(), b_head.begin(), ::tolower);
    string b_num_s = b.substr(b_head_end, min(5,b_num_end-b_head_end));
    int b_num = stringToint(b_num_s);
    
    if(a_head == b_head) return a_num < b_num;
    else return a_head < b_head;
    
}

vector<string> solution(vector<string> files) {
    stable_sort(files.begin(), files.end(), comp);
    return files;
}