#include <string>
#include <algorithm>
#include <vector>

using namespace std;

bool check[1000];

int solution(string str1, string str2) {
    int answer = 0;
    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);

    vector<string> v1;
    vector<string> v2;

    for (int i = 0; i<str1.length() - 1; i++) {
        if (str1[i] >= 97 && str1[i] <= 122 && str1[i + 1] >= 97 && str1[i + 1] <= 122)
            v1.push_back(str1.substr(i, 2));
    }
    for (int i = 0; i<str2.length() - 1; i++) {
        if (str2[i] >= 97 && str2[i] <= 122 && str2[i + 1] >= 97 && str2[i + 1] <= 122)
            v2.push_back(str2.substr(i, 2));
    }
    int intersection = 0;

    for (int i = 0; i<v1.size(); i++) {
        for (int j = 0; j<v2.size(); j++) {
            if (!check[j] && v1[i] == v2[j]) {
                intersection++;
                check[j] = true;
                break;
            }
        }
    }
    int sum = v1.size() + v2.size() - intersection;
    if (sum == 0) return 65536;
    answer = 65536 * intersection / sum;
    return answer;
}