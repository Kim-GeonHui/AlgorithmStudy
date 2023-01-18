#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#pragma warning (disable:4996)

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long N;
	cin >> N;

	vector<long long> arr;
	int idx = 0;
	long long len = 6;
	arr.push_back(1);
	while (arr[idx] <= 1000000000) {
		arr.push_back(arr[idx] + len);
		idx++;
		len += 6;
	}

	for (int i = 0; i <= idx; i++) {
		if (arr[i] >= N) {
			cout << i + 1;
			return 0;
		}
	}

	return 0;
}