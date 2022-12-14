#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#pragma warning (disable:4996)

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int K;
	cin >> K;

	vector<int> numArr;
	vector<vector<pair<int, int>>> answerArr(K);

	int num;
	for (int i = 0; i < pow(2, K) - 1; i++) {
		cin >> num;
		numArr.push_back(num);
	}

	int mid = pow(2, K) / 2;
	answerArr[0].push_back({ numArr[mid - 1], mid - 1 });

	for (int i = 1; i < K; i++) {
		mid /= 2;
		for (int j = 0; j < answerArr[i - 1].size(); j++) {
			answerArr[i].push_back({ numArr[answerArr[i - 1][j].second - mid], answerArr[i - 1][j].second - mid });
			answerArr[i].push_back({ numArr[answerArr[i - 1][j].second + mid], answerArr[i - 1][j].second + mid });
		}
	}

	for (int i = 0; i < answerArr.size(); i++) {
		for (int j = 0; j < answerArr[i].size(); j++)
			cout << answerArr[i][j].first << ' ';
		cout << '\n';
	}

	return 0;
}