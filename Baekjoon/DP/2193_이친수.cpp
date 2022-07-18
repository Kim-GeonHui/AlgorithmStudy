#include <stdio.h>
#include <iostream>
#include <vector>
#pragma warning (disable:4996)

using namespace std;

int main() {

	int N;
	cin >> N;

	vector<vector<long long int>> arr(N, vector<long long int>(2));

	if (N > 3) {
		arr[3][0] = 2;
		arr[3][1] = 1;
	}

	for (int i = 4; i < N; i++) {
		arr[i][0] = arr[i - 1][0] + arr[i - 1][1];
		arr[i][1] = arr[i - 1][0];
	}

	if (N == 1)
		cout << 1;
	else if (1 < N && N < 5)
		cout << N - 1;
	else
		cout << arr[N - 1][0] + arr[N - 1][1];

	return 0;
}