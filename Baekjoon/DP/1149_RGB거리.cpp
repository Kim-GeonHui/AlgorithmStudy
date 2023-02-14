#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#pragma warning (disable:4996)

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, num1, num2, num3;
	cin >> N;
	vector<tuple<int, int, int>> arr(N);
	tuple<int, int, int> t;
	vector<tuple<int, int, int>> ans;
	for (int i = 0; i < N; i++) {
		cin >> num1 >> num2 >> num3;
		t = make_tuple(num1, num2, num3);
		arr[i] = t;
	}

	ans.push_back(arr[0]);
	for (int i = 1; i < N; i++) {
		num1 = min(get<1>(ans[i - 1]), get<2>(ans[i - 1])) + get<0>(arr[i]);
		num2 = min(get<0>(ans[i - 1]), get<2>(ans[i - 1])) + get<1>(arr[i]);
		num3 = min(get<0>(ans[i - 1]), get<1>(ans[i - 1])) + get<2>(arr[i]);
		t = make_tuple(num1, num2, num3);
		ans.push_back(t);
	}

	int answer = min(get<0>(ans[N - 1]), get<1>(ans[N - 1]));
	answer = min(answer, get<2>(ans[N - 1]));
	cout << answer;

	return 0;
}