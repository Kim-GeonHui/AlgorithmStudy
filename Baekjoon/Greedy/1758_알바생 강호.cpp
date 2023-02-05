#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#pragma warning (disable:4996)

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, num, money;
	cin >> N;
	vector<int> arr;
	for (int i = 0; i < N; i++) {
		cin >> num;
		arr.push_back(num);
	}

	sort(arr.rbegin(), arr.rend());
	long long ans = 0;
	for (int i = 0; i < arr.size(); i++) {
		money = max(0, arr[i] - i);
		if (money == 0) break;
		ans += money;
	}

	cout << ans;

	return 0;
}