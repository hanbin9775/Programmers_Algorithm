#include <string>
#include <vector>

using namespace std;

vector<int> answer;

void compactArr(int y_start, int x_start, int size, vector<vector<int>> &origin)
{

    if (size == 1)
    {
        answer[origin[y_start][x_start]]++;
        return;
    }

    int compareNumber = origin[y_start][x_start];
    bool isSame = true;
    for (int i = y_start; i < y_start + size; i++)
    {
        for (int j = x_start; j < x_start + size; j++)
        {
            if (compareNumber != origin[i][j])
            {
                isSame = false;
                break;
            }
        }
        if (!isSame)
            break;
    }

    if (isSame)
        compactArr(y_start, x_start, 1, origin);
    else
    {
        compactArr(y_start, x_start, size / 2, origin);
        compactArr(y_start + size / 2, x_start, size / 2, origin);
        compactArr(y_start, x_start + size / 2, size / 2, origin);
        compactArr(y_start + size / 2, x_start + size / 2, size / 2, origin);
    }
}

vector<int> solution(vector<vector<int>> arr)
{

    answer.resize(2);

    compactArr(0, 0, arr.size(), arr);

    return answer;
}