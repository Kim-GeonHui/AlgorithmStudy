#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#pragma warning (disable:4996)

using namespace std;

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, num, temp;
	cin >> N;
	vector<int> arr(N - 1);
	cin >> num;
	for (int i = 1; i < N; i++) cin >> arr[i - 1];

	for (int n : arr) {
		temp = gcd(num, n);
		cout << num / temp << '/' << n / temp << '\n';
	}

	return 0;
}