#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#pragma warning (disable:4996)

using namespace std;

vector<int> arr;
int N, M;

bool solve(int num) {
	int answer = 0;
	for (int i = 0; i < N; i++) answer += min(arr[i], num);
	return answer > M;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	arr.assign(N, 0);
	int sum = 0;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		sum += arr[i];
	}

	cin >> M;

	if (sum <= M) {
		cout << *max_element(arr.begin(), arr.end());
		return 0;
	}

	int front = 1;
	int end = 1000000000;
	int mid = (front + end) / 2;

	while (front < end) {
		if (solve(mid)) end = mid;
		else front = mid + 1;
		mid = (front + end) / 2;
	}
	
	cout << end - 1;

	return 0;
}