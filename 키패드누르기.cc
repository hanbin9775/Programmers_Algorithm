#include <string>
#include <vector>

using namespace std;

int calcDist(int a, int b){
    int a_y = (a-1)/3;
    int a_x = (a-1)%3;
    int b_y = (b-1)/3;
    int b_x = (b-1)%3;
    
    return abs(a_y-b_y)+abs(a_x-b_x);
}

void press_with_left(string &s, int &left_p,int number){
    s += "L";
    left_p = number;
}
void press_with_right(string &s, int &right_p,int number){
    s += "R";
    right_p = number;
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int len = numbers.size();
    int left_p = 10, right_p = 12;
    int number;
    for(int i=0; i<len; i++){
        numbers[i]==0 ? number = 11 : number = numbers[i];
        if(number==1 || number==4 || number==7) press_with_left(answer, left_p, number);
        else if(number==3 || number==6 || number==9) press_with_right(answer, right_p, number);
        else{
            if(calcDist(left_p, number) < calcDist(right_p, number)) press_with_left(answer, left_p, number);
            else if(calcDist(left_p, number) > calcDist(right_p, number)) press_with_right(answer, right_p, number);
            else{
                if(hand=="left") press_with_left(answer, left_p, number);
                else press_with_right(answer, right_p, number);
            }
        }
    }
    
    return answer;
}