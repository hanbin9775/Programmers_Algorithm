#include <string>
#include <vector>
#include <cmath>

using namespace std;

int findLast0(long long num)
{
    int cnt = 1;

    while (num > 0)
    {
        if (num % 2 == 1)
        {
            cnt++;
            num /= 2;
        }
        else
        {
            break;
        }
    }

    return cnt;
}

vector<long long> solution(vector<long long> numbers)
{
    vector<long long> answer;

    for (int i = 0; i < numbers.size(); i++)
    {
        long long num = numbers[i];
        int last0 = findLast0(num);

        if (last0 < 2)
            answer.push_back(num + 1);
        else
            answer.push_back(num + pow(2, last0 - 2));
    }

    return answer;
}