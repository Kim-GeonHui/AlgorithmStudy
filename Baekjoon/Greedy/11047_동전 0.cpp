#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#pragma warning (disable:4996)

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, K, coin;
	vector<int> arr;

	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> coin;
		arr.push_back(coin);
	}

	sort(arr.rbegin(), arr.rend());

	int ans = 0;
	for (int i = 0; i < arr.size(); i++) {
		while (K >= arr[i]) {
			K -= arr[i];
			ans++;
		}
	}

	cout << ans;

	return 0;
}