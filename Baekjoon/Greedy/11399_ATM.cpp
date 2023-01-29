#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#pragma warning (disable:4996)

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, num;
	cin >> N;

	vector<int> arr;
	for (int i = 0; i < N; i++) {
		cin >> num;
		arr.push_back(num);
	}

	sort(arr.begin(), arr.end());

	int ans = 0;
	int k = arr.size();

	for (int i = 0; i < arr.size(); i++) {
		ans += arr[i] * k;
		k--;
	}

	cout << ans;

	return 0;
}