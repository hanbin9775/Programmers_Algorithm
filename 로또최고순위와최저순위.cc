#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool isIndex(int value, vector<int> target_v)
{
    for (int i = 0; i < target_v.size(); i++)
    {
        if (value == target_v[i])
        {
            return true;
        }
    }
    return false;
}

vector<int> solution(vector<int> lottos, vector<int> win_nums)
{
    vector<int> answer;
    int max_num = 0;
    int min_num = 0;

    for (int i = 0; i < 6; i++)
    {

        if (lottos[i] != 0)
        {
            if (isIndex(lottos[i], win_nums))
            {
                max_num += 1;
                min_num += 1;
            }
        }
        else
        {
            max_num += 1;
        }
    }

    answer = {6 - max_num + 1, 6 - min_num + 1};

    if (max_num <= 1)
    {
        answer[0] = 6;
    }
    if (min_num <= 1)
    {
        answer[1] = 6;
    }

    return answer;
}