#include <vector>

using namespace std;

int MOD = 20170805;

int arr[500][500];

int get_from_up(int i, int j, const vector<vector<int>> &city_map){
    if(i-1 <0) return 0;
    if(city_map[i-1][j]==2) return get_from_up(i-1,j, city_map);
    else return arr[i-1][j];
}

int get_from_left(int i, int j, const vector<vector<int>> &city_map){
    if(j-1 <0) return 0;
    if(city_map[i][j-1]==2) return get_from_left(i,j-1,city_map);
    else return arr[i][j-1];
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> city_map) {
    int answer = 0;

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            arr[i][j] = 0;
        }
    }

    for(int i=0; i<m; i++){
        if(city_map[i][0]!=1) arr[i][0] = 1;
        else break;
    }
    for(int i=0; i<n; i++){
        if(city_map[0][i]!=1) arr[0][i] = 1;
        else break;
    }
    for(int i=1; i<m; i++){
        for(int j=1; j<n; j++){
            if(city_map[i][j]!=1) {
                arr[i][j] = (get_from_up(i,j,city_map)+get_from_left(i,j,city_map))%MOD;               
            }
        }
    }

    return arr[m-1][n-1];
}