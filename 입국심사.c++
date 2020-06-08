#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(int n, vector<int> times) {
	sort(times.begin(), times.end());

	int len = times.size();
	long long start = 0;
	long long end = (long long)times[len - 1] * (long long)n;
	long long mid, sum;
	long long answer = end;

	while (end - start >= 0) {
		sum = 0;
		mid = (start + end) / 2;

		for (int i = 0; i < len; i++) {
			sum += mid / (long long)times[i];
		}

		if (sum < n) start = mid + 1;
		else {
			if (answer > mid) answer = mid;
			end = mid - 1;
		}
	}

	return answer;
}