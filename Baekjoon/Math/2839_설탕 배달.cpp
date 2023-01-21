#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#pragma warning (disable:4996)

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	vector<int> arr(N + 1, -1);
	arr[3] = 1;
	if (N >= 5) arr[5] = 1;
	
	int temp;
	for (int i = 6; i <= N; i++) {
		if (arr[i - 3] == -1 && arr[i - 5] == -1) continue;
		
		if (arr[i - 3] == -1) temp = arr[i - 5];
		else if (arr[i - 5] == -1) temp = arr[i - 3];
		else temp = min(arr[i - 3], arr[i - 5]);
		
		arr[i] = temp + 1;
	}

	cout << arr[N];

	return 0;
}