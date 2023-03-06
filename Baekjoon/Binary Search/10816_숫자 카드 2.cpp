#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#pragma warning (disable:4996)

using namespace std;

vector<int> arr;

int lower_idx(int t) {
	int front, end, mid;
	front = 0;
	end = arr.size();
	mid = (front + end) / 2;

	while (front < end) {
		if (arr[mid] < t) front = mid + 1;
		else end = mid;
		mid = (front + end) / 2;
	}

	return front;
}

int upper_idx(int t) {
	int front, end, mid;
	front = 0;
	end = arr.size();
	mid = (front + end) / 2;

	while (front < end) {
		if (arr[mid] <= t) front = mid + 1;
		else end = mid;
		mid = (front + end) / 2;
	}

	return end;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N;
	arr.assign(N, 0);
	for (int i = 0; i < N; i++) cin >> arr[i];

	cin >> M;
	vector<int> list(M);
	for (int i = 0; i < M; i++) cin >> list[i];

	sort(arr.begin(), arr.end());

	for (int target : list) {
		cout << upper_idx(target) - lower_idx(target) << ' ';
	}

	return 0;
}