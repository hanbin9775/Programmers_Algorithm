#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

map<string, int>::iterator it;

void combination(map<string, int> &m, int i, string s, int size, string cur)
{

    if (size == cur.length())
    {
        it = m.find(cur);
        if (it == m.end())
        {
            m[cur] = 1;
        }
        else
        {
            m[cur] += 1;
        }
        return;
    }
    if (s.length() == i)
        return;

    combination(m, i + 1, s, size, cur + s[i]);
    combination(m, i + 1, s, size, cur);
}

vector<string> solution(vector<string> orders, vector<int> course)
{
    vector<string> answer;

    for (int i = 0; i < course.size(); i++)
    {
        map<string, int> m;

        for (int j = 0; j < orders.size(); j++)
        {
            string order = orders[j];
            sort(order.begin(), order.end());
            combination(m, 0, order, course[i], "");
        }

        //m 에서 값이 가장 큰 조합 구하기
        int max_num = 0;
        for (it = m.begin(); it != m.end(); it++)
        {
            if (max_num < it->second)
            {
                max_num = it->second;
            }
        }
        if (max_num > 1)
        {
            for (it = m.begin(); it != m.end(); it++)
            {
                if (max_num == it->second)
                {
                    answer.push_back(it->first);
                }
            }
        }
    }

    sort(answer.begin(), answer.end());

    return answer;
}