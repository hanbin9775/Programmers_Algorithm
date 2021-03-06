// 문자열압축.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

int solution(string s) {
	int answer = 1001;

	int len = s.length();
	string temp;

	for (int i = 1; i <= len / 2; i++) {
		int cnt = 1;
		temp.clear();
		for (int cur = 0; cur < len; cur += i) {

			if (cur + 2*i -1 >= len) {
				if (cnt > 1) {
					temp.append(to_string(cnt));
				}
				temp.append(s.substr(cur));
				break;
			}

			if (s.substr(cur, i) == s.substr(cur + i, i)) {
				cnt += 1;
			}
			else if (s.substr(cur, i) != s.substr(cur + i, i)) {
				if (cnt > 1) {
					temp.append(to_string(cnt));
				}
				temp.append(s.substr(cur, i));
				cnt = 1;

				//마지막 루프면 빠져나온다.
				if (cur + i > len - 1) {
					break;
				}
			}
		}
		if (answer > temp.length()) {
			answer = temp.length();
		}

	}
	if (answer == 1001) {
		return 1;
	}

	return answer;
}

int main() {

	cout << solution("c");

	return 0;
}
