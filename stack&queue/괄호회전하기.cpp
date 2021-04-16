#include <string>
#include <vector>
#include <stack>

using namespace std;

bool isCorrectBracket(string s)
{
    stack<int> stk;
    int len = s.length();

    for (int i = 0; i < len; i++)
    {
        char tok = s[i];

        if (tok == '[' || tok == '(' || tok == '{')
        {
            stk.push(tok);
        }
        else if (stk.empty())
        {
            return false;
        }
        else
        {
            char top = stk.top();
            if (tok - top <= 2)
            {
                stk.pop();
            }
            else
            {
                return false;
            }
        }
    }

    if (stk.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}

string shiftLeft(string s, int d)
{
    while (d-- > 0)
    {
        s = s.substr(1) + s[0];
    }
    return s;
}

int solution(string s)
{
    int answer = 0;
    int len = s.length();

    for (int i = 0; i < len; i++)
    {
        if (isCorrectBracket(shiftLeft(s, i)))
        {
            answer += 1;
        }
    }

    return answer;
}