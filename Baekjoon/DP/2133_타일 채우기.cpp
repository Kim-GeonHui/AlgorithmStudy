#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#pragma warning (disable:4996)

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	if (N % 2 == 1) {
		cout << 0;
		return 0;
	}
	vector<int> arr(31);
	arr[0] = 1;
	arr[2] = 3;
	for (int i = 4; i <= N; i += 2) {
		arr[i] = arr[i - 2] * 3;
		for (int j = i - 4; j >= 0; j -= 2)
			arr[i] += arr[j] * 2;
	}

	cout << arr[N];

	return 0;
}