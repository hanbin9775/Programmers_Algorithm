#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> budgets, int M) {

    sort(budgets.begin(), budgets.end());
    int answer = budgets[budgets.size() - 1];

    int len = budgets.size();
    long long sum=0;

    for (int i = 0; i < len; i++) {
        sum += budgets[i];
    }

    if(sum <= M) return answer;

    int start = 0;
    int mid;
    int end = len - 1;

    while (true) {

        mid = (start + end) / 2;
        if (mid == start) break;

        sum = 0;
        for (int i = 0; i<len; i++) {
            if (i <= mid) sum += budgets[i];
            else sum += budgets[mid];
        }

        if (sum > M) end = mid;
        else if (sum < M) start = mid;
        else return budgets[(start + end) / 2];

    }

    sum = 0;
    for (int i = 0; i<len; i++) {
        if (i <= mid) sum += budgets[i];
        else sum += budgets[mid];
    }

    long long dsum = 0;
    for (int i = 0; i < mid; i++) {
        dsum += budgets[i];
    }
    if (sum < M) dsum += budgets[mid];
    else mid -= 1;

    answer = (M - dsum) / (len - mid - 1);

    return answer;
}