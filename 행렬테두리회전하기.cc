#include <string>
#include <vector>

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries)
{
    vector<int> answer;
    vector<vector<int>> v;

    int cnt = 1;
    for (int i = 0; i < rows; i++)
    {
        vector<int> temp;
        for (int j = 0; j < columns; j++)
        {
            temp.push_back(cnt++);
        }
        v.push_back(temp);
    }

    for (int s = 0; s < queries.size(); s++)
    {
        int x1 = queries[s][0] - 1;
        int y1 = queries[s][1] - 1;
        int x2 = queries[s][2] - 1;
        int y2 = queries[s][3] - 1;
        int min_num = 10001;

        //step1
        vector<int> temp1;
        for (int i = y1; i < y2; i++)
        {
            temp1.push_back(v[x1][i]);
        }
        //step2
        vector<int> temp2;
        for (int i = x1; i < x2; i++)
        {
            temp2.push_back(v[i][y2]);
        }
        //step3
        vector<int> temp3;
        for (int i = y2; i > y1; i--)
        {
            temp3.push_back(v[x2][i]);
        }
        //step4
        vector<int> temp4;
        for (int i = x2; i > x1; i--)
        {
            temp4.push_back(v[i][y1]);
        }

        for (int i = y1 + 1; i <= y2; i++)
        {
            v[x1][i] = temp1[i - y1 - 1];
            if (min_num > v[x1][i])
            {
                min_num = v[x1][i];
            }
        }
        for (int i = x1 + 1; i <= x2; i++)
        {
            v[i][y2] = temp2[i - x1 - 1];
            if (min_num > v[i][y2])
            {
                min_num = v[i][y2];
            }
        }
        int cnt = 0;
        for (int i = y2 - 1; i >= y1; i--)
        {
            v[x2][i] = temp3[cnt++];
            if (min_num > v[x2][i])
            {
                min_num = v[x2][i];
            }
        }
        cnt = 0;
        for (int i = x2 - 1; i >= x1; i--)
        {
            v[i][y1] = temp4[cnt++];
            if (min_num > v[i][y1])
            {
                min_num = v[i][y1];
            }
        }
        answer.push_back(min_num);
    }

    return answer;
}