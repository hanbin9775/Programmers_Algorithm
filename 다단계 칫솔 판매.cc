#include <string>
#include <vector>
#include <map>

using namespace std;

map<string, int> m;
map<string, int>::iterator it;

vector<vector<int>> tree;
vector<int> profitRecord;

void calculateProfitRecursive(int id, int profit)
{

    int parentProfit = profit * 0.1;
    int myProfit = profit - parentProfit;

    profitRecord[id] += myProfit;

    if (tree[id].size() != 0)
    {
        calculateProfitRecursive(tree[id][0], parentProfit);
    }
    else
    {
        return;
    }
}

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount)
{
    vector<int> answer;

    for (int i = 0; i < enroll.size(); i++)
    {
        m[enroll[i]] = i;
    }
    tree.resize(enroll.size());
    profitRecord.resize(enroll.size());

    for (int i = 0; i < referral.size(); i++)
    {
        string refName = referral[i];

        if (refName != "-")
        {
            tree[i].push_back(m[refName]);
        }
    }

    for (int i = 0; i < seller.size(); i++)
    {
        string sellerName = seller[i];
        int amountNum = amount[i];

        calculateProfitRecursive(m[sellerName], amountNum * 100);
    }

    answer = profitRecord;
    return answer;
}