#include <stdio.h>
#include <iostream>
#include <vector>
#pragma warning (disable:4996)

using namespace std;

int main() {

	int N;
	cin >> N;

	vector<int> arr(N);
	arr[0] = 1;
	arr[1] = 3;

	for (int i = 2; i < N; i++) {
		arr[i] = arr[i - 1] + arr[i - 2] * 2;
		arr[i] %= 10007;
	}

	cout << arr[N - 1];
	
	return 0;
}