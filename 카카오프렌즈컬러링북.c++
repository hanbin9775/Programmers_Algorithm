#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;

    queue<pair<int, int>> q;
    bool visited[100][100];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            visited[i][j] = false;
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j] && picture[i][j] != 0) {
                number_of_area++;
                //bfs
                q.push(make_pair(i, j));
                int size_of_area = 0;
                while (!q.empty()) {
                    int y = q.front().first;
                    int x = q.front().second;
                    q.pop();
                    if (!visited[y][x]) {
                        visited[y][x] = true;
                        size_of_area++;
                    
                        if ( y - 1 >= 0 && !visited[y - 1][x] && picture[y - 1][x] == picture[y][x]) {
                            q.push(make_pair(y - 1, x));
                        }
                        if (y + 1 < m && !visited[y + 1][x] &&  picture[y + 1][x] == picture[y][x]) {
                            q.push(make_pair(y + 1, x));
                        }
                        if (x - 1 >= 0 &&  !visited[y][x - 1] && picture[y][x - 1] == picture[y][x]) {
                            q.push(make_pair(y, x - 1));
                        }
                        if ( x + 1 < n && !visited[y][x + 1] && picture[y][x + 1] == picture[y][x]) {
                            q.push(make_pair(y, x + 1));
                        }
                    }
                }
                max_size_of_one_area = max(max_size_of_one_area, size_of_area);
            }
        }
    }

    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}