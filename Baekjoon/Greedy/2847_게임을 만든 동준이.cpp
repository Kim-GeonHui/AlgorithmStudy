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
	while (N--) {
		cin >> num;
		arr.push_back(num);
	}

	int ans = 0;
	for (int i = arr.size() - 2; i >= 0; i--) {
		while (arr[i] >= arr[i + 1]) {
			arr[i]--;
			ans++;
		}
	}

	cout << ans;

	return 0;
}