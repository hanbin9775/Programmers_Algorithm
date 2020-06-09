#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int solution(int n, vector<string> data) {
    int answer = 40320;
    bool cands[40320];
    for(int i=0;i<40320; i++)
        cands[i] = true;

    vector<char> origin = { 'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T' };

    for (int i = 0; i<n; i++) {
        char first = data[i][0];
        char second = data[i][2];
        char optr = data[i][3];
        int dist = data[i][4] - '0';
        int cand_idx=0;
        do{
            if(cands[cand_idx] == true){
                int f_idx;
                int s_idx;
                bool check = true;

                for (int k = 0; k<8; k++) {
                    if (first == origin[k]) f_idx = k;
                    if (second == origin[k]) s_idx = k;
                }

                switch (optr) {
                case '=':
                    if (abs(f_idx - s_idx) != dist + 1) check = false;
                    break;
                case '<':
                    if (abs(f_idx - s_idx) >= dist + 1) check = false;
                    break;
                case '>':
                    if (abs(f_idx - s_idx) <= dist + 1) check = false;
                    break;
                }
                if (!check) {
                    answer--; 
                    cands[cand_idx]=false; 
                }
            }
            cand_idx++;
        }while(next_permutation(origin.begin(), origin.end()));
    }

    return answer;
}