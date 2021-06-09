#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compScore(vector<string> a, vector<string> b)
{
    return stoi(a[4]) < stoi(b[4]);
}

vector<string> parseString(string s, string divider)
{

    vector<string> parsedInfo;

    while (true)
    {
        int space = s.find(divider);
        if (space == string::npos)
        {
            parsedInfo.push_back(s);
            break;
        }
        parsedInfo.push_back(s.substr(0, space));
        s = s.substr(space + divider.length());
    }

    return parsedInfo;
}

vector<int> solution(vector<string> info, vector<string> query)
{
    vector<int> answer;

    vector<vector<string>> db_info;
    vector<vector<string>> db_query;
    vector<int> sortedScore;

    for (int i = 0; i < info.size(); i++)
    {
        db_info.push_back(parseString(info[i], " "));
    }
    sort(db_info.begin(), db_info.end(), compScore);
    for (int i = 0; i < db_info.size(); i++)
    {
        sortedScore.push_back(stoi(db_info[i][4]));
    }

    for (int i = 0; i < query.size(); i++)
    {
        vector<string> temp = parseString(query[i], " and ");
        temp.push_back(temp[3].substr(temp[3].find(" ") + 1));
        temp[3] = temp[3].substr(0, temp[3].find(" "));
        db_query.push_back(temp);
    }

    for (int i = 0; i < db_query.size(); i++)
    {
        int result = 0;

        vector<string> parsedQuery = db_query[i];

        int start = 0;
        if (binary_search(sortedScore.begin(), sortedScore.end(), stoi(parsedQuery[4])))
        {
            start = lower_bound(sortedScore.begin(), sortedScore.end(), stoi(parsedQuery[4])) - sortedScore.begin();

            for (int k = start; k < sortedScore.size(); k++)
            {
                if (stoi(parsedQuery[4]) == sortedScore[k])
                {
                    start = k;
                    break;
                }
            }
        }
        else
        {
            start = upper_bound(sortedScore.begin(), sortedScore.end(), stoi(parsedQuery[4])) - sortedScore.begin();
        }

        for (int j = start; j < db_info.size(); j++)
        {
            vector<string> parsedInfo = db_info[j];

            if ((parsedQuery[0] == "-" || parsedQuery[0] == parsedInfo[0]) &&
                (parsedQuery[1] == "-" || parsedQuery[1] == parsedInfo[1]) &&
                (parsedQuery[2] == "-" || parsedQuery[2] == parsedInfo[2]) &&
                (parsedQuery[3] == "-" || parsedQuery[3] == parsedInfo[3]))
            {
                result++;
            }
        }
        answer.push_back(result);
    }

    return answer;
}