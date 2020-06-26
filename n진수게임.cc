#include <string>
#include <vector>

using namespace std;

string convertToN(int num, int n) {
    string str = "";
    int remainder;
    while (num>0) {
        remainder = num % n;
        switch (remainder) {
        case 10:
            str = "A" + str;
            break;
        case 11:
            str = "B" + str;
            break;
        case 12:
            str = "C" + str;
            break;
        case 13:
            str = "D" + str;
            break;
        case 14:
            str = "E" + str;
            break;
        case 15:
            str = "F" + str;
            break;
        default:
            str = to_string(remainder) + str;
            break;
        }
        num /= n;

    }
    return str;
}

string solution(int n, int t, int m, int p) {
    string answer = "";

    string str ="0";

    for(int i=1; i< t*m*n; i++){
        str += convertToN(i,n);
    }

    int cnt=0;
    int turn;

    while(answer.length()<t){
        turn = cnt%m +1;
        if(turn == p) answer += str[cnt];
        cnt++;
    }

    return answer;
}