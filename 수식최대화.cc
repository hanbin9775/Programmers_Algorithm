#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long cac_with_priority(vector<long long> operands, vector<int> operations, const vector<int> &operation_priority){

    int pri_idx=0;
    while(operands.size()>1){
        for(int i=0; i<operations.size(); i++){
            if(operations[i]==operation_priority[pri_idx]){
                switch(operation_priority[pri_idx]){
                    case 1:
                        operands[i] = operands[i]*operands[i+1];
                        break;
                    case 2:
                        operands[i] = operands[i]+operands[i+1];
                        break;
                    case 3:
                        operands[i] = operands[i]-operands[i+1];
                        break;
                }
                operations.erase(operations.begin()+i);
                operands.erase(operands.begin()+i+1);
                i--;
            }
        }
        pri_idx++;
    }
    return abs(operands[0]);
}

long long solution(string expression) {
    long long answer = 0;

    vector<int> operation_priority = {1,2,3};
    vector<long long> operands;
    // 1 : *, 2 : +, 3 : -
    vector<int> operations;

    long long operand=0;
    for(int i=0; i<expression.length(); i++){
        if(isdigit(expression[i])){
            operand *=10;
            operand += (long long)(expression[i]-'0');
        }
        else {
            if(expression[i]=='*') operations.push_back(1);
            if(expression[i]=='+') operations.push_back(2);
            if(expression[i]=='-') operations.push_back(3);
            operands.push_back(operand);
            operand = 0;
        }

        if(i==expression.length()-1){
            operands.push_back(operand);
        }
    }    

    do{
        answer = max(answer, cac_with_priority(operands, operations,operation_priority));
    }while(next_permutation(operation_priority.begin(),operation_priority.end()));

    return answer;
}